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

// utility function to print the list
void print_list()
{
    struct node *temp = head;

    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

// inserting at the beginning of the list
void insert_at_beginning(int data)
{
    struct node *new_node = newNode(data);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        new_node->next = head;
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        head = new_node;
    }
}

// insert at nth position
void insert_at_n(int n, int index)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        struct node *temp = head;
        int i = 0;
        while (i < index - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// insert at end of the list
void insert_at_end(int n)
{
    struct node *new_node = newNode(n);
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

// delete at first
void delete_at_first()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // if head next is head, then it means only one node is present in the list
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
}

// delete at nth position
void delete_at_n(int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // if head next is head, then it means only one node is present in the list
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    if (index == 0)
    {
        head = head->next;
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (i < index - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // if head next is head, then it means only one node is present in the list
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    struct node *temp2 = temp->next;

    temp->next = head;

    free(temp2);
}

// search
int search(int n)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    struct node *temp = head;
    int i = 0;
    while (temp->next != head)
    {
        if (temp->data == n)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    if (temp->data == n)
    {
        return i;
    }
    return -1;
}

int main()
{

    printf("Welcome to the circular linked list program\n");

    int choice, index, data;
    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at nth position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at first\n");
        printf("5. Delete at nth position\n");
        printf("6. Delete at end\n");
        printf("7. Search\n");
        printf("8. Print list\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the index: ");
            int index;
            scanf("%d", &index);
            insert_at_n(data, index);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;
        case 4:
            delete_at_first();
            break;
        case 5:
            printf("Enter the index: ");
            scanf("%d", &index);
            delete_at_n(index);
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
            printf("Enter the data: ");
            scanf("%d", &data);
            index = search(data);
            if (index == -1)
            {
                printf("Data not found\n");
            }
            else
            {
                printf("Data found at %d\n", index);
            }
            break;
        case 8:
            print_list();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}