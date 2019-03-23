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
		dprintf(STDERR_FILENO, "Usage: %s <filename output>\n", argv[0]);
		return 1;
	}

	/** Open file */
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	
	if(fd == -1) {
		perror("Failed to open file");
		return 2;
	}

	/** Read user input */
	printf("Enter student name followed by grades: <name> <grade1> <grade2> <grade3>\n");
	printf("Press Ctrl+D to end\n\n");
	int ret_scanf;
	do {	
		test_t test;
		ret_scanf = scanf("%s %d %d %d", test.st, &test.grades[0], &test.grades[1], &test.grades[2]);

		if(ret_scanf != EOF) {
			write(fd, &test, sizeof(test));
		}
	} while(ret_scanf != EOF);

	/** close file */
	close(fd);
}
