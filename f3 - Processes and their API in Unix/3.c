/**
 * @brief Write a program that creates a child and a grand-child. Each process shall write its PID and that of its parent, as well as the termination code of its child, if it has any. The child and the grand-child shall terminate with code 2 and 3, respectively.
 * 
 * @file 3.c
 * @author Fábio Gaspar
 * @date 2018-03-03
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    // NOTE: For simplification I didn't checked return values from sys calls.. but I should

    
    // Create child
    pid_t p1 = fork();

    if(p1 == 0) {
        // This is the child process, create the grand-child
        pid_t p2 = fork();
        
        if(p2 == 0) {
            printf("PID: %-5d PPID: %-5d (GRAND-CHILD PROCESS)\n", getpid(), getppid());
            exit(3);
        }
        else {
            int st;
            waitpid(p2, &st, 0); // wait for grand-child to terminate
            printf("Grand child exited with %d\n", WEXITSTATUS(st));
            printf("PID: %-5d PPID: %-5d (CHILD PROCESS)\n", getpid(), getppid());
            exit(2);
        }
    }
    else {
        int st;
        waitpid(p1, &st, 0); // wait for child to terminate
        printf("Child exited with %d\n", WEXITSTATUS(st));
        printf("PID: %-5d PPID: %-5d (FATHER PROCESS)\n", getpid(), getppid());
    }
}