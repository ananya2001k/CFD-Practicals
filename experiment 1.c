#include<stdio.h>
int main()
{
	int i,j,m,n;
	float c,h,k,r,u[10][10];
	h=1,k=0.125,c=1,n=5,m=8;
	for(j=0;j<n+1;j++)
	{
		u[0][j]=0;
		u[m][j]=0;
	}
	for(i=1;i<m;i++)
	{
		u[i][0]=(4*i)-(i*i)/2.0;
	}
	r=0.5;
	for(j=0;j<n;j++)
	{
		for(i=1;i<m;i++)
		{
			u[i][j+1]=r*(u[i-1][j]+u[i+1][j])+(1-2*r)*u[i][j];
		}
	}
	printf("the solution of parabolic equation:\n");
	printf("(i,j)\t");
	for(i=0;i<=m;i++)
	{
		printf("u(%d,j)\t",i);
	}
	printf("\n");
	for(j=0;j<n+1;j++)
	{
		printf("(i,%d)\t",j);
		{
			for(i=0;i<=m;i++)
				printf("%5.2f\t",u[i][j]);
			printf("\n");
		}
	}
}