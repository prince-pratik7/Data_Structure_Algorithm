#include<stdio.h>
#define inf 9999
#define size 10
main()
{
	int a[size][size],i,j,n,v1,v2,lcost;
	int dij(int[][j],int,int,int);
	printf("Enter the number of vertex : ");
	scanf("%d",&n);
	//Input 0 if there is no direct edge between vertex pair
	printf("Enter a weighted matrix(with weights) as input :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{//printf("Enter the value of a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("The entered matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}	
	printf("Enter starting vertex v\b");
	scanf("%d",&v1);
	printf("Enter ending vertex v\b");
	scanf("%d",&v2);
	//Check for validity of input vertices
	if(v1<0||v1>n-1||v2<0||v2>n-1)
	{
	printf("!!!!!ERROR!!!!!n");
	printf("!!!!!Invalid vertex given!!!!!");
	return;
	}
	printf("Shortest path between v%d & v%d : ",v1,v2);
	lcost=dij(a,n,v1,v2);
	printf("Shortest cost between v%d & v%d : ",v1,v2);
	printf("%d",lcost);/*Print the shortest cost*/
}
//The input graph,no. of vertices n,source vertex v1 and destination vertex v2 are passed as parameters
int dij(int a[size][size],int n,int v1,int v2)
{
	int length[size],set[size],path[size],i,j,s,z,tmp,temp[size],c=0,f=0;
	s=v1;
	z=v2;
	int srch_min(int[],int[],int);
	for(i=0;i<n;i++)
		set[i]=0;
	for(i=0;i<n;i++)
	{
		if(a[s][i]==0)//There is no direct edge between vertices s and i
		{
			length[i]=inf;
			path[i]=0;//Empty path
		}
		else
		{
			length[i]=a[s][i];
			path[i]=s;// is immediate predecessor of i
		}
	}
	set[s]=1;//s is included in the set
	length[s]=0;//s is implicitly enumerated with length as 0
	while(set[z]!=1)//Iteration will be considered until final vertex z belongs to s
	{
		j=srch_min(length,set,n);//Select a vertex j with minimum label such that it is not included in the set[]
		set[j]=1;//Vertex j is included in the set[]
		for(i=0;i<n;i++)
		{	
			if(set[i]!=1)
			{
				if(a[i][j]!=0)
				{
					if(length[j]+a[i][j]<length[i])//When exsisting label is not minimum only then replacement is done	
					{
						length[i]=length[j]+a[i][j];
						path[i]=j;
					}
				}
			}
		}
	}
	j=0;
	i=z;
	while(i!=s)
	{
		tmp=path[i];
		temp[j]=tmp;
		i=tmp;
		j++;
		c++;
	}
	for(j=c-1;j>=0;j--)
	{
		printf("v%d->",temp[j]);//Print the shortest path
		if(temp[j]==z)
			f=1;
	}
	if(f!=1)
		printf("v%d",z);
	printf("\n");
	return length[z];
}
	//This function will return a vertex with minimum label such that it is not included in set[] 
int srch_min(int length[],int set[],int n) 
{
	int min,i,min_index;
	min=99999,min_index;
	for(i=1;i<n;i++)
	{
		if(set[i]!=1)
		{
			if(length[i]<min)
			{
				min=length[i];
				min_index=i;
			}
		}
	}
	return min_index;
}

	
