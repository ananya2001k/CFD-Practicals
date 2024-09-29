#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Gauss Jacobi Method
int main()
{
    int n,i,j,iter,iterations;
    printf("Enter the value of n for n*n grid:");
    scanf("%d",&n);
    printf("Enter the number of iterations:");
    scanf("%d",&iterations);
    float u[n][n];
    for(i=0;i<n;i++)
    {
        u[i][0]=0;
        u[n-1][i]=0;
        u[i][n-1]=0;
    }
    for(i=1;i<n-1;i++)
        u[0][i]=100;
    printf("The inital grid is:\n");
    for(j=n-1;j>=0;j--)
    {
        for(i=0;i<n;i++)
            printf("%0.2f\t",u[i][j]);
        printf("\n");
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
            u[i][j]=0;
    }
    for(iter=0;iter<iterations;iter++)
    {
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<n-1;j++)
                u[i][j]=0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]);
        }
        printf("Iteration %d:\n",iter+1);
        for(j=0;j<n;j++)
        {
            for(i=0;i<n;i++)
                printf("%0.2f\t",u[i][j]);
            printf("\n");
        }
    }
}