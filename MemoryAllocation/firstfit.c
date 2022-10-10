#include<stdio.h>

void main(){
	
	int nob,nop;
	
	printf("Enter num of blocks : ");
	scanf("%d",&nob);
	
	int blocksize[nob];
	
	for(int i = 0;i< nob;i++){
		printf("%dth block size : ",i+1);
		scanf("%d",&blocksize[i]);	
	}
	
	printf("Enter num of process : ");
	scanf("%d",&nop);
	
	int processsize[nop],allocate[nop];
	
	for(int i = 0;i< nop;i++){
		printf("%dth process size : ",i+1);
		scanf("%d",&processsize[i]);	
	}
	
	for(int i=0;i<nop;i++){
	 allocate[i]=-1;
	}
	
	for(int i =0;i<nop;i++){
		for(int j =0;j<nob;j++){
		
			if(blocksize[j]>=processsize[i])
			{
				allocate[i]=j;
				blocksize[j]-= processsize[i];
				break;
			}
		
		}
	}	
	
	printf("\nProcess\tProcessSize\tBlock\n");
	
	for(int i =0;i<nop;i++){
	
		printf("%d\t%d\t\t",i+1,processsize[i]);
		
		if(allocate[i]!=-1)
		printf("%d\n",allocate[i]+1);
		else
		printf("Not allocated\n");
		
	}
	


}
