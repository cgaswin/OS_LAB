#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int arr[],int n){
	for(int i =0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
			swap(&arr[j],&arr[j+1]);
		}
	}
}

void main(){

	int n,head,headmovement,direction,disksize;
	
	printf("Enter the no of requests : ");
	scanf("%d",&n);
	int request[n];
	
	for(int i =0;i<n;i++){
		printf("%dth request : ",i+1);
		scanf("%d",&request[i]);
	}
	bubblesort(request,n);
	
	printf("Enter initial head position : ");
	scanf("%d",&head);
	
	printf("Enter the disksize: ");
	scanf("%d",&disksize);
	
	printf("Enter direction(0 for left,1 for right) : ");
	scanf("%d",&direction);
	
	int startindex;
	for(int i =0;i<n;i++){
		if(head<request[i]){
			startindex=i;
			break;
		}
	
	}
	
	if(direction==0){
	for(int i=startindex-1;i>=0;i--){
		printf("%d->",request[i]);
		headmovement+=abs(request[i]-head);
		head=request[i];
	}
	headmovement+=abs(request[0]);
	printf("%d->",0);
	head=0;
	
	headmovement+=abs(disksize-1);
	head=disksize-1;
	printf("%d->",(disksize-1));
	
	for(int i=n;i>=startindex;i--){
		printf("%d->",request[i]);
		headmovement+=abs(request[i]-head);
		head=request[i];
	}
	
	
	}else{
	
	for(int i=startindex;i<n;i++){
		printf("%d->",request[i]);
		headmovement+=abs(request[i]-head);
		head=request[i];
	}
	headmovement+=abs(disksize-1-request[n-1]);
	head=disksize-1;
	printf("%d->",(disksize-1));
	
	
	headmovement+=abs(disksize-1);
	head=0;
	printf("%d->",0);
	
	for(int i=0;i<startindex;i++){
		printf("%d->",request[i]);
		headmovement+=abs(request[i]-head);
		head=request[i];
	}
	
	
	}
	
	printf("\nTotal head movement: %d",headmovement);
	
}
