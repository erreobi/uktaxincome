#include <float.h>
#include <emscripten.h>


/*
    =================================================
    Band 	           | Taxable income 	| Tax rate
    ==================================================
    Personal Allowance | Up to £12,570 	    |    0%
    Basic rate         | £12,571 to £50,270 |	20%
    Higher rate        | £50,271 to £150,000| 	40%
    Additional rate    | over £150,000 	    |   45%

    SPACIAL CASE:
    You do not get a Personal Allowance on taxable income over £125,140.
    The Personal Allowance goes down by £1 for every £2 of income above the £100,000 limit. 
    It can go down to zero.
*/

//((110000-50270)*0.4) + ((50270-12570)*0.2)+((110000-100000)*0.5)

const float MAX_Personal_Allowance = 12570;
const float MAX_Basic_rate = 50270;
const float MAX_Higher_rate = 150000;
const float MAX_Additional = FLT_MAX;
const float MAX_Personal_Allowance_Removed = 125140;

const float MAX_Personal_Allowance_tax = 0;
const float MAX_Basic_rate_tax = 0.20;
const float MAX_Higher_rate_tax = 0.40;
const float MAX_Additional_tax = 0.45;

// those are the UK task steps.
float taxRates[] = {0, MAX_Personal_Allowance, MAX_Basic_rate, MAX_Higher_rate, MAX_Additional};

// these are the tax to pay for each steps
float taxs[] = {0, MAX_Personal_Allowance_tax, MAX_Basic_rate_tax, MAX_Higher_rate_tax, MAX_Additional_tax};


EMSCRIPTEN_KEEPALIVE float howMuchTaxes(float income)
{

    int index = 1;
    float taxToPay = 0;
    int foundMax = 0;

    // printf("You income is \n");
    float incomeToApplyTaxes = income;

    while (foundMax == 0 && index < 4)
    {
        if (income > taxRates[index])
        {
            //if you are earning more than the last step, the calculation is different
            if (index == 3)
            {
                 taxToPay += (income - taxRates[index - 1]) * taxs[index];
            }else{
                taxToPay += (taxRates[index] - taxRates[index - 1]) * taxs[index];
            }
        }
        else
        {
            incomeToApplyTaxes = income - taxRates[index - 1];
            taxToPay += (incomeToApplyTaxes)*taxs[index];
            foundMax = 1;
        }
        index++;
    }


    //Special Case
    if (income > 100000)
    {
        if (income > MAX_Personal_Allowance_Removed)
        {
            taxToPay += MAX_Personal_Allowance;
        }else{
            taxToPay += (income-100000)*0.5;
        }
    }

    // printf("All considered you will pay %f", taxToPay);

    return taxToPay;
}
