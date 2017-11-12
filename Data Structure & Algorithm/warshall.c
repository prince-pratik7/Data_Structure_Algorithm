#include<stdio.h>

int main()
{ 
int w[5][5],i,j,k,p;
printf("\n enter the Cost Matrix\n");
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
scanf("%d",&w[i][j]);
}
}
for(k=0;k<5;k++)
{
 for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(w[i][j]>w[i][k]+w[k][j])
{
w[i][j]=w[i][k]+w[k][j];
p=w[i][j];
}}}}
printf("\nshortest path is %d\n",p);

}
