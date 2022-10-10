#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(){

 	pid_t PID = fork();
 	
 	if(PID==-1)
 		printf("Error");
 	else if(PID==0){
 		printf("Child\n");
 		printf("PID: %d\n",getpid());
 		printf("Parent PID: %d\n",getppid());
 		exit(0);
 	}	
 	else{
 		printf("Parent\n");
 		printf("Parent waiting\n");
 		wait(NULL);
 		printf("Child terminated\n");
		printf("PID: %d\n",getpid());
 		printf("Parent PID: %d\n",getppid());
 	}
}
