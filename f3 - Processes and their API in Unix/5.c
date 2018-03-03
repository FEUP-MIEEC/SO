/**
 * @brief Write a program that compiles a C program whose name is passed on its command line. Your program should execute gcc (/usr/bin/gcc), by invoking the execve() system call with appropriate arguments.
 * 
 * @file 5.c
 * @author Fábio Gaspar
 * @date 2018-03-03
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
    if (argc != 2)
    {
        printf("Usage: %s file.c\n", *argv);
        exit(1);
    }

    /* 
     * The new program instance will have it's own array of arguments, 
    where the first it's the executable name, the second we want it to be the source code file to compile
     * The array ends with null character. According with the standard "The value of argc shall be nonnegative. argv[argc] shall be a null pointer."
     * 
     * The execve function on _man_ says it expects a filename... That's wrong! It requires the path to executable file
    */
    char *args[] = {"/usr/bin/gcc", *(argv + 1), NULL};
    execve("/usr/bin/gcc", args, envp);

    // this code will only run if execve fails
    perror(NULL);
    exit(2);
}