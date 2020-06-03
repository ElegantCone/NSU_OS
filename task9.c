#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
main(){

	pid_t pid, ret;
	int status;

	pid = fork();

	if (pid == 0)
		execl("/bin/cat", "cat", "/home/students/18200/saraeva/labs/crusoe.txt", (char*) 0);

	printf("\nparent: waiting for child: %ld\n", pid);

	ret = wait(&status);
	printf("\nparent: wait's return value: %ld\n", ret);
	printf("child's status: %d\n", WEXITSTATUS(status));

	exit(0);
}