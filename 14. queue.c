#include <stdio.h>

// implement queue using arrays
struct Queue
{
    int arr[100];
    int rear;
    int max_size;
};

typedef struct Queue queue;

// creating insert delete and display
void insert(queue *Q, int element)
{

    // insert element in the front
    if (Q->rear == Q->max_size)
    {
        printf("Queue is full!\n");
        return;
    }

    for (int i = Q->rear; i > 0; i--)
    {
        Q->arr[i] = Q->arr[i - 1];
    }

    Q->arr[0] = element;
}

void delete (queue *Q)
{

    // delete element from the rear
    if (Q->rear == 0)
    {
        printf("Queue is empty!\n");
        return;
    }

    Q->rear--;
}

void display(queue *Q)
{
    // display the queue
    if (Q->rear == 0)
    {
        printf("Queue is empty!\n");
        return;
    }

    for (int i = 0; i < Q->rear; i++)
    {
        printf("%d ", Q->arr[i]);
    }
    printf("\n");
}

int main()
{

    queue Q = {.arr = {0}, .max_size = 100, .rear = 0};

    printf("Welcome to Queue!\n");

    while (1)
    {
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Display\n");
        printf("4) Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int element;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert(&Q, element);
            printf("Element inserted!\n");
            break;
        case 2:
            delete (&Q);
            printf("Element deleted!\n");
            break;
        case 3:
            display(&Q);
            break;
        default:
            return 0;
        }
    }

    return 0;
}