#include <stdio.h>

main(){
	
	FILE *fptr;
	char *lines[3] = { "Here 3 lines of text.\n",
				"It was in lower case\n",
				"made to upper!\n" };
	int i;

	fptr = popen("./task26child", "w");
		
	for (i = 0; i < 3; i++)
		fputs(lines[i], fptr);

	pclose(fptr);	
}
