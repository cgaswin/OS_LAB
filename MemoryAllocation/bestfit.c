#include<stdio.h>

void main(){
	
	int numberOfBlocks,numberOfProcesses;
	
	printf("Enter num of blocks : ");
	scanf("%d",&numberOfBlocks);
	
	int blockSize[numberOfBlocks];
	
	for(int i = 0;i< numberOfBlocks;i++){
		printf("%dth block size : ",i+1);
		scanf("%d",&blockSize[i]);	
	}
	
	printf("Enter num of process : ");
	scanf("%d",&numberOfProcesses);
	
	int processSize[numberOfProcesses],allocate[numberOfProcesses];
	
	for(int i = 0;i< numberOfProcesses;i++){
		printf("%dth process size : ",i+1);
		scanf("%d",&processSize[i]);	
	}
	
	for(int i=0;i<numberOfProcesses;i++){
	 allocate[i]=-1;
	}
	
	for(int i =0;i<numberOfProcesses;i++){
	int indexplaced = -1;
	
	for(int j=0;j<numberOfBlocks;j++){
	
		if(blockSize[j]>=processSize[i])
		{
			if(indexplaced==-1){
			indexplaced=j;
			}
			else if(blockSize[j]<blockSize[indexplaced])
			{
				indexplaced=j;
			}
			
		}
		}
		if(indexplaced!=-1){
			allocate[i]=indexplaced;
			blockSize[indexplaced]-=processSize[i];
		}
		
	
	
	}
	
	printf("\nProcess\tprocessSize\tBlock\n");
	
	for(int i =0;i<numberOfProcesses;i++){
	
		printf("%d\t%d\t\t",i+1,processSize[i]);
		
		if(allocate[i]!=-1)
		printf("%d\n",allocate[i]+1);
		else
		printf("Not allocated\n");
		
	}
	


}
