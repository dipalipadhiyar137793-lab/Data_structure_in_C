int main()
{
    int A[10],i,largest;
    printf("enter 10 number:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }
    largest=A[0];
    for(i=1;i<10;i++)
    {
        if (A[i]>largest)
        {
            largest=A[i];
        }
    }
    printf("largest value=%d",largest);
    return 0;
}
