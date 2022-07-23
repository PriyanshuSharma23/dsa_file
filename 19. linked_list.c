#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// utility function to create a new node
struct node *newNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *search(int data)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertAtN(int n, int index)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (i < index - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertStart(int n)
{
    struct node *new_node = newNode(n);
    new_node->next = head;
    head = new_node;
}

void insertEnd(int n)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete (int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (index == 0)
    {
        head = head->next;
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
}

void deleteStart()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    head = head->next;
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{

    printf("Welcome to the linked list program\n");
    int choice;

    while (1)
    {
        printf("\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at nth position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from end\n");
        printf("6. Delete from nth position\n");
        printf("7. Print list\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            int n;
            scanf("%d", &n);
            insertStart(n);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &n);
            insertEnd(n);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &n);
            printf("Enter the position: ");
            int index;
            scanf("%d", &index);
            insertAtN(n, index);
            break;
        case 4:
            deleteStart();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &index);
            delete (index);
            break;
        case 7:
            print_list();
            break;
        case 8:
            printf("Enter the data: ");
            scanf("%d", &n);
            struct node *temp = search(n);
            if (temp == NULL)
            {
                printf("Data not found\n");
            }
            else
            {
                printf("Data found at %d\n", temp->data);
            }
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}