#include <stdio.h>
#include <stdlib.h>
int main(){
	int r1,c1,r2,c2;
	if(scanf("%d %d",&r1,&c1)!=2)
		return 0;
	int **a=(int **)malloc(r1*sizeof(int*));
	for(int i=0;i<r1;i++){
		a[i]=(int *)malloc(c1*sizeof(int));
		for(int j=0;j<c1;j++){
			if(scanf("%d",&a[i][j])!=1)
				return 0;
		}
	}
	if(scanf("%d %d",&r2,&c2)!=2)
		return 0;
	if(c1!=r2){
		printf("Invalid input\n");
		for(int i=0;i<r1;i++){
			free(a[i]);
		}
		free(a);
		return 0;
	}
	int **b=(int **)malloc(r2*sizeof(int*));
	for(int i=0;i<r2;i++){
		b[i]=(int *)malloc(c2*sizeof(int));
		for(int j=0;j<c2;j++){
			if(scanf("%d",&b[i][j])!=1)
				return 0;
		}
	}
	int **c=(int **)malloc(r1*sizeof(int *));
	for(int i=0;i<r1;i++){
		c[i]=(int*)calloc(c2,sizeof(int));
	}
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			for(int k=0;k<c1;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			printf("%d ",c[i][j]);
			if(j<c2-1){
				printf("");
			}
		}
		printf("\n");
	}
	int i;
	for(i=0;i<r1;i++)
		free(a[i]);
	free(a);
	for(i=0;i<r2;i++)
		free(b[i]);
	free(b);
	for(i=0;i<r1;i++)
		free(c[i]);
	free(c);
	return 0;
}
