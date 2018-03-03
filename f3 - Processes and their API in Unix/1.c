/**
 * @brief Write a program that prints its arguments on the standard output as well as its environment variables.
 * 
 * @file 1.c
 * @author Fábio Gaspar
 * @date 2018-03-03
 */
#include <stdio.h>

int main(int argc, char** argv, char** envp) {
    char **argcpy = argv, **envcpy = envp; // just copies, to iterate directly with pointers
    
    printf("ARGUMENTS\n");
    while(*argcpy != NULL) {
        printf("%s\n", *argcpy);
        argcpy++;
    }
    
    printf("\n\nENVIRONMENT VARIABLES\n");
    while(*envcpy != NULL) {
        printf("%s\n", *envcpy);
        envcpy++;
    }
}