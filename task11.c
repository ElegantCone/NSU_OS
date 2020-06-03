#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void execvpe(char *file, char *argv[], char *envp[]);

main(){
	static char *argv[]={"task10", "cat", "text", (char*) 0};
	static char *nenv[]={"RUN=yes", "FILE=data", (char*) 0};
	execvpe(argv[0], argv, nenv);
	perror(argv[0]);
	exit(0);
}

void execvpe(char *file, char *argv[], char *envp[]){
	extern char **environ;
	environ = envp;
	execvp(file, argv);
	return;
}