#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int no_months(char *mon1, char *mon2) {
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    int m1, m2;
    for(m1 = 0; m1 < 12 && strncasecmp(months[m1], mon1, 3) != 0; m1++);
    for(m2 = 0; m2 < 12 && strncasecmp(months[m2], mon2, 3) != 0; m2++);

    if(m1 > 11 || m2 > 11) {
        printf("Invalid month string!\n");
        exit(1);
    }

    return (m1 > m2) ? m1 - m2 : m2 - m1;
}
int main() {
    
    printf("%d\n", no_months("january", "mar"));
    printf("%d\n", no_months("dec", "jan"));
    printf("%d\n", no_months("asfdsaf", "mar"));
}