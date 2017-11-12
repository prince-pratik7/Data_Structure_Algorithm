#include<stdio.h>
#include<stdlib.h>
int n, i,s[20][20];

void split(int x, int y){
	int z;
	z=s[x][y];
	if(z!=0){
	printf("split at %d\n",z);
	if((z-x)>1)
		split(x,z);
	if((y-z-1)>1)
		split(z,y);
	}
}

void matrix_chain(int *p){
	int j,k,l;
	long m[20][20],q;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			s[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			j=(i+l-1);
			m[i][j]=999;
			for(k=i;k<=(j-1);k++){
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}	
			}
		}
	}
	split(1,n);
	  printf("minimum no of multiplication reqired for doing so is %d\n",m[1][n]);
}

int main(){
	int p[10];
	printf("enter the no matrix: ");
	scanf("%d",&n);
	printf("enter the elements of the matrix: \n");
	for(i=1;i<=(n+1);i++)
		scanf("%d",&p[i]);
	matrix_chain(p);
	return 0;
}
