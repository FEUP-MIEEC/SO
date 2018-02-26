#include <stdio.h>
#define LENGTH 12

int main() {
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i < LENGTH; i++)
        printf("%s\n", *(months+i));
}