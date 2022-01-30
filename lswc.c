// Caleb Knight
// CS 344
// Project 4
// Lswc

#include <stdio.h>   // printf perror
#include <stdlib.h>  // exit
#include <unistd.h>  // fork execlp close

int main(int argc, char *argv[]) 
{
	int fds[2];   // File desciptors, 0 is read end, 1 is write end
	pipe(fds);   // Create pipe
	int pid = fork(); // used to fork the parent and get a child


	// child stuff
	if(pid == 0) {
		dup2(fds[0], 0); // Dup read end 
		close(fds[1]);   // Close write end
		execlp("wc", "wc", "-l", (char *) NULL);
		exit(0);
	}

	// parent stuff
	dup2(fds[1], 1);     // Dup write end of pipe to stdout
	close(fds[0]);       // close read end
	execlp("ls", "ls", "-1a", argv[1], (char *) NULL);
}


