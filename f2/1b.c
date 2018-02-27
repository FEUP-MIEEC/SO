#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: %s src_filename dst_filename\n", argv[0]);
        exit(1);
    }

    // open src file and store file descriptor
    int src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1) {
        perror(NULL);
        exit(2);
    }

    // open dst file and store file descriptor
    /*
        NOTE: I added the O_CREAT flag (and changed from read_only to write_only) because I want the system to create the dst file if it doesn't exit
        That flag requires another parameter, mode -> an octal number that sets the file permissions
        You can use bitwise operations and flags (macros) defined on the STD, 
            or you can't write the number in octal (easier sometimes, perhaps less legible)
        
        mode : rwx|rwx|rwx -> (user permission)|(group permission)|(others permission)
        r -> read
        w -> write
        x -> execute

        I decided to give read & write permissions to everyone, therefore, mode in bits = 110 110 110, and on octal = 666
    */

    int dst_fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if(dst_fd == -1) {
        perror(NULL);
        exit(3);
    }

    // Read src file and write to dst file
    char buffer[64];
    int length = 0, ret;

    while((ret = read(src_fd, buffer, 64)) != 0) {
        // read returns 0 when there are no more bytes to read (and other particular cases)
        // read returns -1 on error
        // read returns the number of bytes read
        if(ret == -1) {
            perror(NULL);
            exit(4);
        }

        length += ret; // read bytes
        if(write(dst_fd, buffer, ret) == -1) {
            perror(NULL);
            exit(5);
        }
    }

    printf("\n\nFile length: %d\n", length);

    close(src_fd);
    close(dst_fd);
}