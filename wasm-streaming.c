#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE int multiply (int a, int b)
{
    return a*b;
}