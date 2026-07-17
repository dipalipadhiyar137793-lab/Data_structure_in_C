#include <stdio.h>

int main()
{
    int a[100],n,i,pos,value;
    printf("Enter the elements:");

    scanf("%d",&n);
    printf("Enter the elements:\n");


    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("Enter the position to insert(1 to %d)",n+1);

        scanf("%d",&pos);
        printf("Enter the element to insert:");

        scanf("%d",&value);
        if(pos<1||pos>n+1)
        {
            printf("position not found");
        }
        else
        {
            for(i=n;i>=pos;i--)
                a[i]=a[i-1];

         a[pos-1]=value;
         n++;
        }
        printf("array after insertion:\n");
         for(i=0;i<=n;i++)
            printf("%d",a[i]);

         return 0;
}


