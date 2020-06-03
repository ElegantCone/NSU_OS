#include <stdio.h>
#include <signal.h>
#define BEL '\07'
int count1 = 0;
int count2 = 0;

void sigcatch(int);

int main(){
	int nsec = 0;
	signal(SIGINT, sigcatch);
	signal(SIGQUIT, sigcatch);
	signal(SIGALRM, sigcatch);
	for (;;) {
		alarm(1);
		pause();
	}
	return 0;
}

void sigcatch(int sig){
	if (sig == SIGQUIT){
		printf("Count1: %d;\n Count2: %d;\n", count1, count2);	
		exit(1);
	}
	if (sig == SIGALRM) count2++;
	else {
		printf("%c\n", BEL);
		count1++;
	}
	signal(SIGINT, sigcatch);
	signal(SIGQUIT, sigcatch);
	signal(SIGALRM, sigcatch);
}

