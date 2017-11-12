#include<stdio.h>
#include<stdlib.h>
int v,x[20],a[20][20],m;
void nextValue(int k){
	int j;
	while(1){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0){
			printf("Graph cannot be coloured with given no of colors.\n");
			exit(1);
		}
		for(j=1;j<=v;j++){
			if(a[k][j]==1 && x[j]==x[k])
				break;
		}
		if(j==v+1)
			return;
	}
}

int main(){
	int k,j,i,e,v1,v2;
	printf("enter the no of vertices: ");
	scanf("%d",&v);
	
	for(i=1;i<=v;i++){
		x[i]=0;
		for(j=1;j<=v;j++)
			a[i][j]=0;
	}
	printf("enter the no of edges: ");
	scanf("%d",&e);
	
	printf("enter the edges:\n");
	for(i=0;i<e;i++){
		scanf("%d %d",&v1,&v2);
		a[v1][v2]=1;
		a[v2][v1]=1;
	}
	printf("enter the total no of colors: ");
	scanf("%d",&m);
	
	for(k=1;k<=v;k++){
		nextValue(k);
	}
	for(k=1;k<=v;k++){
		printf(" vertex %d--> %d\n",k,x[k]);
	}
	
	return 0;
}
