// Caleb Knight
// Project 4
// CS 344
// An exercise to pipe the output of a process to the input of another
// and save the output in a file
// Goal: run ls -1a and wc -l --> pipe the output of ls into wc
// % ls -1a | wc -l   --> Tells us how many files in curr dir


#include <stdio.h>   // printf perror
#include <stdlib.h>  // exit
#include <unistd.h>  // fork execlp close

int main(int argc, char *argv[]) 
{
	int fds[2];   // 0 is read end, 1 is write end

	//char *input[];

	pid_t pid = fork();

	if(pid == 0) {
		int result;
		printf("Child's running\n");

		close(fds[1]);
		read(fds[0], &result, sizeof result);

		printf("child: %d\n", result);

		exit(0);
	}

	printf("Parent's running\n");
	close(fds[0]);
	execlp("ls", "ls", "-1a", argv[1], NULL);



	printf("0: %s\n", argv[0]);          // prints args from command line 
	for(int i = 1; i < argc; i ++)       // with corresponding number 
	{                                    // based on order of args entered
		printf("%d: %s\n", i, argv[i]);
	}

}


