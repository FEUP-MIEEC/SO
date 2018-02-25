#include <stdio.h>
#include <stdlib.h>

void in_fibonacci(int *fib, int n) {
    unsigned int fa = 0, fb = 1;

    if (n >= 1) *(fib) = fa; else return;
    if (n >= 2) *(fib+1) = fb; else return;

    for(int i = 2; i < n; i++) {
        // a - f(n-2)
        // b - f(n-1)
        *(fib + i) = fa+fb;
        fa = fb;
        fb = *(fib + i);
    }
}

int main(int argc, char** argv) {
    int n;

    if(argc == 2)
        n = atoi(*(argv+1));
    else
        exit(-1);

    // allocate memory
    int *fibSeq = (int *) malloc(sizeof(int)*n);
    if(fibSeq == NULL) 
        exit(-2); // failed to allocate memory, exit

    // call function to fill the array
    in_fibonacci(fibSeq, n);

    // display the sequence
    for(int i = 0; i < n; i++)
        printf("%d ", *(fibSeq + i));
    printf("\n");

    // free memory
    free(fibSeq);
}