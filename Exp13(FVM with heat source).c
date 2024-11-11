#include<stdio.h>
int main()
{
    int i,n;
    float L,q,Q,Ta,Tb,k,h,B,A,alpha[10],beta[10],a[10],b[10],c[10],d[10],x[10];
    printf("Enter the length of the rod:");
    scanf("%f",&L);
    printf("Enter the number of nodal points:");
    scanf("%d",&n);
    printf("Enter the temperature at the left end of the rod:");
    scanf("%f",&Ta);
    printf("Enter the temperature at the right end of the rod:");
    scanf("%f",&Tb);
    printf("Enter the value of cross section area:");
    scanf("%f",&A);
    printf("Enter the thermal conductivity:");
    scanf("%f",&k);
    printf("Enter the heat source:");
    scanf("%f",&q);
    h=L/n;
    B=(k*A)/h;
    Q=(q*A*h);
    for(i=2;i<=n;i++)
        a[i]=-B;
    for(i=1;i<n;i++)
        c[i]=-B;
    for(i=1;i<=n;i++)
    {
        if(i==1 || i==n)
            b[i]=3*B;
        else
            b[i]=2*B;
    }
    for(i=2;i<n;i++)
            d[i]=Q;
    d[1]=2*Ta*B+Q;
    d[n]=2*Tb*B+Q;
    alpha[1]=b[1];
    beta[1]=d[1]/b[1];
    for(i=2;i<=n;i++)
    {
        alpha[i]=b[i]-((a[i]*c[i-1])/alpha[i-1]);
        beta[i]=(d[i]-a[i]*beta[i-1])/alpha[i];
    }
    x[n]=beta[n];
    for(i=n-1;i>0;i--)
        x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);
    printf("the solution of the given system is:\n");
    for(i=1;i<=n;i++)
        printf("%0.3f\t",x[i]);
}