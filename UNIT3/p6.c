#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertAtStarting(struct Node *head, int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
        {
            printf(" <-> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Starting\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert at starting: ");
                scanf("%d", &value);

                head = insertAtStarting(head, value);

                printf("Node inserted at starting successfully.\n");
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);

                head = insertAtEnd(head, value);

                printf("Node inserted at end successfully.\n");
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
