#include<stdio.h>
int func(int x,int y)
{
    return (-10*(x*x+y*y+10));
}
int main()
{
    int n,i,j,h,iterations;
    printf("Enter the value of n for n*n grid:");
    scanf("%d",&n);
    printf("Enter the number of iteration:");
    scanf("%d",&iterations);
    printf("enter the value of h:");
    scanf("%d",&h);
    float u[n][n];
    for(i=0;i<n;i++)
    {
        u[i][0]=0;
        u[n-1][i]=0;
        u[i][n-1]=0;
         u[0][i]=0;
    }
   for(i=1;i<n-1;i++)
   {
       for(j=1;j<n-1;j++)
        u[i][j]=0;
   }
    printf("The inital grid is:\n");
    for(j=n-1;j>=0;j--)
    {
        for(i=0;i<n;i++)
            printf("%3.2f\t",u[i][j]);
        printf("\n");
    }
    for(int iter=0;iter<iterations;iter++)
    {
        if(iter==0)
        {
            u[1][1]=0;
            u[2][2]=0;
            u[1][2]=0.25*(u[1][1]+u[2][2]-h*h*func(1,2));
            u[2][1]=0.25*(u[1][1]+u[2][2]-h*h*func(2,1));
            u[1][1]=0.25*(u[1][2]+u[2][1]-h*h*func(1,1));
            u[2][2]=0.25*(u[1][2]+u[2][1]-h*h*func(2,2));
        }
        else
        {
            for(j=n-2;j>0;j--)
            {
                for(i=1;i<n-1;i++)
                {
                    if(i==1 && j==n-2)
                    {
                        u[i][j]=0.25*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-h*h*func(i,j));
                        u[j][i]=u[i][j];
                    }
                    else if(i==n-2 && j==1)
                        continue;
                    else 
                        u[i][j]=0.25*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-h*h*func(i,j));
                }
            }
        }
        printf("iteration %d:\n",iter+1);
        for(j=n-1;j>=0;j--)
        {
            for(i=0;i<n;i++)
                printf("%3.2f\t",u[i][j]);
            printf("\n");
        }
    }
  
}