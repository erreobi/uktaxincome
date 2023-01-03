#include <stdio.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE int addNums (int a, int b) {
    return a+b;
}

int main() {
    printf("Hello World -> %d\n", addNums(3,7));
    return 0;
}

