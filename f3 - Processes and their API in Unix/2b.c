/**
 * @brief Write a program that creates a child process, which writes its environment variables and their files to another file, whose name is a command line argument of both the parent and the child processes.
 Compare the files created by both processes. 
 What is the relationship between the environment variables of a process and of its children?
 *
 * @file 2a.c
 * @author Fábio Gaspar
 * @date 2018-03-03
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void writeEnvVarToFile(char *filename) {
    /**
     * Try to open the file
     * O_WRONLY write only access mode
     * O_CREAT if the file doesn't exist, create it
     * O_TRUNC if the file exists, it's truncated to length zero, a.k.a it's content is "cleared"
     */
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1) {
        perror(NULL);
        exit(2);
    }

    char **envcpy = envp; // just a copy to not lose a reference to environment variables array
    while(*envcpy != NULL) {
        if(write(fd, *envcpy, strlen(*envcpy)) == -1 || write(fd, "\n", 1) == -1){
            perror(NULL);
            exit(3);
        }

        envcpy++;
    }

    if(close(fd) == -1) {
        perror(NULL);
        exit(4);
    }
}
int main(int argc, char** argv, char** envp) {
    // check if there's an argument (path to file)
    if(argc != 2) {
        printf("Usage: %s <file path>\n", *argv);
        exit(1);
    }

}