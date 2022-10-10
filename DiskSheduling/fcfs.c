#include<stdio.h>
#include<stdlib.h>

void main(){
	
	int headmovement=0,head,n;
	printf("Enter the no of requests : ");
	scanf("%d",&n);
	
	printf("Enter initial head position: ");
	scanf("%d",&head);
	
	int request[n];
	
	for(int i=0;i<n;i++){
	
		printf("%dth request : ",i+1);
		scanf("%d",&request[i]);
	
	}
	printf("%d->",head);
	for(int i =0;i<n;i++){
	printf("%d->",request[i]);
	headmovement+=abs(head-request[i]);
	head=request[i];
	}

	printf("\nTotal head movement: %d\n",headmovement);


}
