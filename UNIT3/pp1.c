#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;
struct node* create()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insert_begin()
{
    struct node *newnode;
    newnode = create();
    if(start == NULL)
    {
        start= newnode;
    }
    else
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}
void add()
{
    struct node *newnode, *temp;
    newnode = create();
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}
void display()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = start;
    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Add at End");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                add();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    while(choice != 4);
    return 0;
}
