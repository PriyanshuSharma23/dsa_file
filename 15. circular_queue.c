// implementing a circular queue
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int *arr;
    int front;
    int rear;
    int size;
};

void init(struct queue *q, int size)
{
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

// creating utility function to check if queue is full
int isFull(struct queue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

// creating insert, delete and display functions
void insert(struct queue *q, int data)
{

    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;

    printf("%d inserted\n", data);
}

void delete (struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("%d deleted\n", q->arr[q->front]);

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
}

void display(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[i]);
}

int main()
{
    struct queue q;
    init(&q, 5);

    printf("Welcome to circular queue\n");

    int choice;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter data: ");
            scanf("%d", &data);
            insert(&q, data);
            break;
        case 2:
            delete (&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}