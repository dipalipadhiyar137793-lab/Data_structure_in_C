#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node* insertAfter(struct Node *head, int specificValue, int newValue)
{
    struct Node *temp;
    struct Node *newNode;

    temp = head;


    while (temp != NULL && temp->data != specificValue)
    {
        temp = temp->next;
    }


    if (temp == NULL)
    {
        printf("Specific node %d not found.\n", specificValue);
        return head;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newValue;

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Node %d inserted after %d successfully.\n",
           newValue, specificValue);

    return head;
}

struct Node* insertBefore(struct Node *head, int specificValue, int newValue)
{
    struct Node *temp;
    struct Node *newNode;

    temp = head;

    while (temp != NULL && temp->data != specificValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Specific node %d not found.\n", specificValue);
        return head;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = newValue;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
    {
        temp->prev->next = newNode;
    }
    else
    {
        head = newNode;
    }

    temp->prev = newNode;

    printf("Node %d inserted before %d successfully.\n",
           newValue, specificValue);

    return head;
}

void display(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    temp = head;

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

struct Node* createList(struct Node *head)
{
    struct Node *newNode;
    struct Node *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return head;
    }

    for (i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            return head;
        }

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice;
    int specificValue;
    int newValue;

    head = createList(head);

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert After Specific Node\n");
        printf("2. Insert Before Specific Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the specific node value: ");
                scanf("%d", &specificValue);

                printf("Enter the new node value: ");
                scanf("%d", &newValue);

                head = insertAfter(head, specificValue, newValue);
                break;

            case 2:
                printf("Enter the specific node value: ");
                scanf("%d", &specificValue);

                printf("Enter the new node value: ");
                scanf("%d", &newValue);

                head = insertBefore(head, specificValue, newValue);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Program terminated successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }
    }

    return 0;
}
