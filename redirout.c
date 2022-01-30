// Caleb Knight
// CS344
// Project 4
// Redir


#include <stdio.h>  //printf, perror
#include <stdlib.h> //exit
#include <unistd.h> //fork, execlp, close
#include <fcntl.h>  //open


int main(int argc, char *argv[])
{
	const int BUFFER_SIZE = 2048;

	if(argc < 3) {
		printf("\nToo few arguments: Expect 3\n");
		exit(1);
	}

	int redir_fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666); // opens file specified from command with Read and Write permission
   // ftruncate(redir_fd, 0); //Deletes any contents in the file


	int fds[2];  // File desciptors, 0 is read end, 1 is write end
	pipe(fds);   // Create pipe
	int pid = fork(); // used to fork the parent and get a child

	// child stuff
	if(pid == 0) {
		dup2(fds[1], 1); // Dup output to stdin 
		close(fds[0]);   // Close input end
		execvp(argv[2], argv + 2);  // Run given command + third and following args
		exit(0);
	}	

	// parent stuff
	close(fds[1]);       // close output end
	char *buf[BUFFER_SIZE];
	int bytes_read;

	bytes_read = read(fds[0], buf, BUFFER_SIZE);

	while(bytes_read) {
		write(redir_fd, buf, bytes_read);
		break;
	}

	return 0;

}