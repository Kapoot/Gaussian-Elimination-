/*

Gauss Elimination Matrix Solver
Dylan Kapustka, Abed Ahmed
Dr. Singh
10-28-2019

*/

//*DK* indicates parts by Dylan
//*AA* indicates parts by Abed

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    /*AA*/
    int i,j,k,n;
    float GE[20][20],c,x[10],sum=0.0;
    printf("\nHow many rows are in this matrix? ");
    scanf("%d",&n);
    printf("\nEnter each element row wise:\n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("GE[%d][%d] : ", i,j);
            scanf("%f",&GE[i][j]);
        }
    }
    for(j=1; j<=n; j++) 
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=GE[i][j]/GE[j][j];
                for(k=1; k<=n+1; k++)
                {
                    GE[i][k]=GE[i][k]-c*GE[j][k];
                }
            }
        }
    }
    x[n]=GE[n][n+1]/GE[n][n];
    /*DK*/
   // applies backwards substitution 
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+GE[i][j]*x[j];
        }
        x[i]=(GE[i][n+1]-sum)/GE[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); // solutions printed x1, x2, or x3 iterated
    }
    getch();
}
