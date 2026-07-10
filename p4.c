#include<stdio.h>
int main()
{
    int A[3]={1,2,3};
    int B[3]={4,5,6};
    int C[3]={6};
    int i;

    for(i=0;i<3;i++)
     {
        C[i]=A[i];
     }

    for(i=0;i<6;i++)
     {
        C[i]=B[i];
     }

    printf("Merged array C:");
    for(i=0;i<6;i++)
     {
        printf("%d",C[i]);
     }
    return 0;
}

