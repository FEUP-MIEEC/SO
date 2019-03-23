#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef char name[30]; 
typedef struct { 
	name st;
	int grades[3];
} test_t;

int main(int argc, char **argv) {
	/** Check arguments */
	if(argc != 2) {
		dprintf(STDERR_FILENO, "Usage: %s <filename input>\n", argv[0]);
		return 1;
	}
	
	/** Open file */
	int fd = open(argv[1], O_RDONLY);
	
	if(fd == -1) {
		perror("Failed to open file");
		return 2;
	}

	/** Read and display student and grades */
	int const test_size = sizeof(test_t);
	test_t test;
	int i = 0;
	while(read(fd, &test, test_size) == test_size) {
		printf("Student %d: %s\n", i++, test.st);
		printf("Grades: %d %d %d\n", test.grades[0], test.grades[1], test.grades[2]);
		printf("=======================================\n");
	}
	/** close file */
	close(fd);
}
