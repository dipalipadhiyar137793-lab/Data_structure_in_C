#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
int main()
{
    struct Node *start = NULL;
    struct Node *ptr, *newnode;
    int n, i, num;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }
    printf("Enter value after which you want to insert: ");
    scanf("%d", &num);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &newnode->data);
    ptr = start;
    while(ptr != NULL && ptr->data != num)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("Given node not found.");
        free(newnode);
    }
    else
    {
        newnode->next = ptr->next;
        newnode->prev = ptr;
        if(ptr->next != NULL)
        {
            ptr->next->prev = newnode;
        }
        ptr->next = newnode;
        printf("Node inserted successfully.");
    }
    printf("\nDoubly Linked List: ");
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

