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
    return 0;
}