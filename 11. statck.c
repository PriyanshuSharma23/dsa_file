#include <stdio.h>
#include <stdlib.h>

// implement stack using array

struct Stack
{
    int arr[100];
    int top;
    int max_size;
};

typedef struct Stack stack;

// methods for push, pop, display

void push(stack *S, int x)
{
    if (S->top == S->max_size)
    {
        printf("Stack is full!\n");
        return;
    }
    S->arr[S->top] = x;
    S->top += 1;
}

void pop(stack *S)
{
    if (S->top == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    S->top -= 1;
}

void display(stack *S)
{
    if (S->top == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i < S->top; i++)
    {
        printf("%d ", S->arr[i]);
    }
    printf("\n");
}

int main()
{

    stack S = {.arr = {0}, .max_size = 100, .top = 0};

    printf("Welcome to Stack!\n");

    while (1)
    {
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("4) Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            int x;
            printf("Enter the element to push: ");
            scanf("%d", &x);
            push(&S, x);
        }
        else if (choice == 2)
        {
            pop(&S);
        }
        else if (choice == 3)
        {
            display(&S);
        }
        else if (choice == 4)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    

    return 0;
}