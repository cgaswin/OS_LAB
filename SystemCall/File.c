#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

void main(){

	DIR *dir = opendir(".");
	
	if(dir == NULL){
		printf("Unsuccessful");
		return;
	}
	
	struct dirent *files;
	
	while((files = readdir(dir)) !=NULL)
		printf("%s\n",files->d_name);
	
	closedir(dir);
	


}
