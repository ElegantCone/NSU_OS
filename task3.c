#include <stdio.h>
#include <unistd.h>
void ReturnIds(){
	printf("Your effective id: %d\n", geteuid());
	printf("Your real id: %d\n", getuid());
}
void OpenCloseFile(FILE *fin){
	fin = fopen("fileForTask3.txt", "r");
	if (fin == NULL)
		perror("You haven't enough permissions for open this file");
	else printf("File opened succesfully\n");
	fclose(fin);
}
int main(){
	 printf("\n");
	 FILE *fin; 

	 ReturnIds();
	 OpenCloseFile(fin); 

	 //setuid(getuid());

	 ReturnIds();
	 OpenCloseFile(fin);

	 return 0;
}
