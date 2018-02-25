#include "stdio.h"

int main()
{
    /**
     * a)
    */
    printf("size(char): %lu\n", sizeof(char));
    printf("size(short): %lu\n", sizeof(short));
    printf("size(int): %lu\n", sizeof(int));
    printf("size(long): %lu\n", sizeof(long));
    printf("size(long long): %lu\n", sizeof(long long));

    /**
     * b)
     */
    int a[10];
    struct complex
    {
        double re, im;
    } z;
    char *hello = "Hello, World!";

    printf("size(array): %lu\n", sizeof(a));
    printf("size(struct): %lu\n", sizeof(z));
    printf("size(string): %lu\n", sizeof(hello));
    /*
    OUTPUT
    size(array): 40
    size(struct): 16
    size(string): 8
    */

    /**
     * c)
     */
    printf("size(a[0]): %lu\n", sizeof(a[0]));
    printf("size(*hello): %lu\n", sizeof(*hello));
    /*
    OUTPUT
    size(a[0]): 4
    size(*hello): 1
    */
}