#include <stdio.h>

int main() {
    int num = 0x01020304; // a number that uses 4 bytes
    char *ptr = (char* )&num;
    if(*ptr == 4) {
        printf("little endian\n");
    }
    else if (*(ptr + 3) == 1) {
        printf("big endian\n");
    }

    
    printf("%p : %d\n", ptr, *ptr++);
    printf("%p : %d\n", ptr, *ptr++);
    printf("%p : %d\n", ptr, *ptr++);
    printf("%p : %d\n", ptr, *ptr++);
}