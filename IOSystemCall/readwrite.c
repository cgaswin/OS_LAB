#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main(){

	int file_descriptor = open("./test.txt",O_RDWR | O_CREAT);
	printf("\nFile Descriptor : %d\n",file_descriptor);
	
	if(file_descriptor == -1){
		
		printf("Could'nt open file\n");
		return;
	}
	
	printf("\n The file opened with read and write access\n");
	
	char buffer[100];
	
	printf("Enter a string to write : ");
	fgets(buffer,50,stdin);
	
	char message[strlen(buffer)];
	strcpy(message,buffer);
	
	write(file_descriptor,message,sizeof(message));
	lseek(file_descriptor,0,SEEK_SET);
	read(file_descriptor,buffer,sizeof(message));
	printf("\n%s was written onto the file\n",buffer);
	
	close(file_descriptor);


}
