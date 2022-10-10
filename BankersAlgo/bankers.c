#include<stdio.h>

void main(){

	int i,j,k,m,n,y,maximum[20][20],allocation[20][20],available[20][20],safesequenceindex=0;
	
	printf("Enter the number of processes : ");
	scanf("%d",&n)
	
	printf("Enter the number of resources : ");
	scanf("%d",&m)
	
	printf("Enter allocation matrix: ");
	for(i=0;i<n;i++){
		for(j=-0;j<n;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	
	printf("Enter the maximum matrix:");
	for(i=0;i<n;i++){
		for(j=-0;j<n;j++){
			scanf("%d",&maximum[i][j]);
		}
	}
	
	printf("Enter the availble matrix:");
	for(i=0;i<n;i++){
	scanf("%d",&available[i]);
	}
	
	int finish[n],safesequence[n],work[m],need[n][m];
	
	for(i=0;i<n;i++){
		for(j=-0;j<n;j++){
			need[i][j]=maximum[i][j]-allocation[i][j]
		}
	}
	
	printf("The need matrix is: ");
	for(i=0;i<n;i++){
		for(j=-0;j<n;j++){
			printf("%d",&need[i][j]);
		}
	}
	
	for(i=0;i<n;i++)
	finish[i]=0;
	
	for(j=0;j<n;j++)
	work[j]=available[j];
	
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(finish[i]==0){
				int flag;
				for(j=0;j<n;j++){
					if(need[i][j]>available[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					safesequence[safesequenceindex]=i;
					for(y=0;y<m;y++){
					work[y]+=allocation[i][y];
					}
					finish[i]=1;
				}
			
			}
		}
	}
	
	
	printf("\nSafe sequence for processes: ");
	for(i=0;i<n;i++){
		printf("P%d => ",safesequence[i]);
	}
	
	
	

}
