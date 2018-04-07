#include "stdio.h"

#define SIZE 10

int main() {
    
    unsigned int fa = 0, fb = 1;
    printf("%d\n%d\n", fa,fb);
    for(size_t i = 0; i < SIZE - 2; i++) {
        // a - f(n-2)
        // b - f(n-1)
        int fn = fa+fb;
        printf("%d\n", fn);
        fa = fb;
        fb = fn;
    }
}