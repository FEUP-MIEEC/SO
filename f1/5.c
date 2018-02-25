#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int my_strlen(char *str) {
    int i = 0;
    while(*(str + i) != '\0') i++;

    return i;
}
int main(int argc, char** argv) {
    if(argc != 2) {
        errno = E2BIG;
        perror(NULL);
        exit(-1);
    }

    printf("Length of %s = %d\n", argv[1], my_strlen(argv[1]));
}