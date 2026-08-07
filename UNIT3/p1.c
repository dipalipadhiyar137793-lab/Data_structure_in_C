#include<stdio.h>
#include<conio.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
}*start,*newnode;

void create_11()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
}

void display()
{
    struct node*ptr;
    for(ptr=start;ptr->next!=NULL;ptr=ptr->next)
    {
        printf("\n %d",ptr->data);
    }
}

void main()
{
    start=NULL;
    int ch;
    while(1)
    {
        printf("1.create\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1: create_11();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
                    break;
            default: printf("wrong choice");
        }
    }
    return 0;
}
