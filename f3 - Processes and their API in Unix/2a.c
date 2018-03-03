/**
 * @brief Write environment variables and their values in a file, whose name is its first argument.
 * The exercise doesn't forbid the usage of C standard functions, but I decided to use system calls to work with files, because... ¯\_(ツ)_/¯
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

int main(int argc, char** argv, char** envp) {
    // check if there's an argument (path to file)
    if(argc != 2) {
        printf("Usage: %s <file path>\n", *argv);
        exit(1);
    }

    /**
     * Try to open the file
     * O_WRONLY write only access mode
     * O_CREAT if the file doesn't exist, create it
     * O_TRUNC if the file exists, it's truncated to length zero, a.k.a it's content is "cleared"
     */
    int fd = open(*(argv+1), O_WRONLY | O_CREAT | O_TRUNC);
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