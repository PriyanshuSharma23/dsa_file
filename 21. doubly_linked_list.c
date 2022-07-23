#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

// utility function to create a new node
struct node *newNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// utility function to print the list
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

void insert_at_beginning(int data)
{
    struct node *new_node = newNode(data);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_at_n(int n, int index)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        int i = 0;
        struct node *temp = head;
        while (i < index - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void insert_at_end(int n)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
        new_node->prev = temp;
    }
}

void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_at_n(int n, int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        int i = 0;
        struct node *temp = head;
        while (i < index - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        free(temp2);
    }
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }
}

void search(int n)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                printf("%d found\n", n);
                return;
            }
            temp = temp->next;
        }
        printf("%d not found\n", n);
    }
}

int main()
{

    printf("Welcome to the doubly linked list program\n");
    int choice, n, index;

    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at n\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at n\n");
        printf("6. Delete at end\n");
        printf("7. Search\n");
        printf("8. Print list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &n);
            insert_at_beginning(n);
            break;
        case 2:
            printf("Enter the number to insert: ");
            scanf("%d", &n);
            printf("Enter the index: ");
            scanf("%d", &index);
            insert_at_n(n, index);
            break;
        case 3:
            printf("Enter the number to insert: ");
            scanf("%d", &n);
            insert_at_end(n);
            break;
        case 4:
            delete_at_beginning();
            break;
        case 5:
            printf("Enter the index: ");
            scanf("%d", &index);
            delete_at_n(n, index);
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            printf("Enter the number to search: ");
            scanf("%d", &n);
            search(n);
            break;
        case 8:
            print_list();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }

    return 0;
}