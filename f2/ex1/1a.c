#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s file_name\n", argv[0]);
        exit(1);
    }

    // open file and store file descriptor
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror(NULL);
        exit(2);
    }

    // Read file and write to STDOUT 
    char buffer[64];
    int length = 0, ret;

    while((ret = read(fd, buffer, 64)) != 0) {
        // read returns 0 when there are no more bytes to read (and other particular cases)
        // read returns -1 on error
        // read returns the number of bytes read
        if(ret == -1) {
            perror(NULL);
            exit(3);
        }

        length += ret; // read bytes
        if(write(STDOUT_FILENO, buffer, ret) == -1) {
            perror(NULL);
            exit(4);
        }
    }

    printf("\n\nFile length: %d\n", length);

    close(fd);

    return 0;
}