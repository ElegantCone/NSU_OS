#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

main(int argc, char **argv){
	int pid;
	int fd[2];
	static char *lines[3] = { "Here 3 lines of text.\n",
				"It was in lower case\n",
				"made to upper!\n" };
	char input[1000];
	int rtn;
	
	if (pipe(fd) == -1){
		perror(argv[0]);
		exit(1);
	}
	
	if ( (pid = fork()) > 0) { //parent
		close(fd[0]);
		for (int i = 0; i < 3; i++)
			write( fd[1], lines[i], strlen(lines[i]) );
		close(fd[1]);
	}
	else if (pid == 0) { //child
		close(fd[1]);
		while( (rtn = read(fd[0], input, 1000)) > 0) {
			for (int i = 0; i < rtn; i++)
				if ( islower(input[i]) ) input[i] = toupper(input[i]);
			write(1, input, rtn);
		}
		close(fd[0]);
	}
	else { //can't fork
		perror(argv[0]);
		exit(2);
	}

	exit(0);
}
