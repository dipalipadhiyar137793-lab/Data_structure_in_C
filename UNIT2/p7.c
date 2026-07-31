#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter a number:");
    scanf("%d",&n);
    if(n<=1)
    {
        printf("No smallest divisor exists.\n");
        return 0;
    }
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            printf("Smallest Divisor = %d\n",i);
            break;
        }
    }

    return 0;
}
