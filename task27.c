#include <stdio.h>

main(int argc, char **argv){
	FILE *fin, *fout;
	char line[BUFSIZ];

	fin = fopen(argv[1], "r");
	if (fin == NULL) {
		perror(argv[0]);
		exit(1);
	}
	
	fout = popen("wc -l", "w");
	while ( fgets(line, BUFSIZ, fin) != NULL)
		if (line[0] == '\n')
			fputs(line, fout);
	fclose(fin);
	pclose(fout);
}