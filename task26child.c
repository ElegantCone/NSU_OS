#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

main(){
	char input[1000];
	int rtn, i;
	while (	(rtn = read(0, input, 1000)) > 0) {
		for (i = 0; i < rtn; i++)
			if (islower(input[i])) input[i] = toupper(input[i]);
		write(1, input, rtn);
	}
	exit(0);
}
