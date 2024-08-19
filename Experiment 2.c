#include<stdio.h>
#include<math.h>
float f(float i)
{
    float pi=3.14;
    return sin(pi*i);
}
int main()
{
	int i,j,m,n;
	float c,h,k,r,u[10][10];
	h=0.2,k=0.02,c=1,n=3,m=5;
	for(j=0;j<n+1;j++)
	{
		u[0][j]=0;
		u[m][j]=0;
	}
	for(i=1;i<m;i++)
	{
		u[i][0]=f(0.2*i);
	}
	r=(k*c*c)/(h*h);
	for(j=0;j<n;j++)
	{
		for(i=1;i<m;i++)
		{
			u[i][j+1]=r*(u[i-1][j]+u[i+1][j])+(1-2*r)*u[i][j];
		}
	}
	printf("the solution of parabolic equation:\n");
	printf("(i,j)\t\t");
	for(i=0;i<=m;i++)
	{
		printf("u(%0.2f,j)\t",i*0.2);
	}
	printf("\n");
	for(j=0;j<n+1;j++)
	{
		printf("(i,%0.2f)\t",j*0.02);
		{
			for(i=0;i<=m;i++)
				printf("%5.3f\t\t",u[i][j]);
			printf("\n");
		}
	}
}