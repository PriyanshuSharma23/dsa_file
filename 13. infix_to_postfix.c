#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining and it's operations

struct Stack
{
    int top; // by default will be -1
    unsigned capacity; // because it will never go below zero
    int *array;
};

// Stack Operations
struct Stack *createStack(unsigned capacity);
int isEmpty(struct Stack *stack);
char peek(struct Stack *stack);
char pop(struct Stack *stack);
void push(struct Stack *stack, char op);

// operands will characters from a-z || A-Z
int isOperand(char _char)
{
    if (_char >= 'a' && _char <= 'z')
        return 1;
    else if (_char >= 'A' && _char <= 'Z')
        return 1;
    else
        return 0;
}

// precedence for operators
// +, -, *, /, %, ^
int precedence(char _char)
{
    switch (_char)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int infixToPostfix(char* exp)
{
    int i, j;
    struct Stack *S = createStack(strlen(exp));

    if (!S)
    {
        printf("Error!\n");
        return -1;
    }

    // we will mutate the exp 
    for (i = 0, j = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
        {
            exp[++j] = exp[i];
        }
        else if (exp[i] == '(')
        {
            push(S, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty(S) && peek(S) != '(')
            {
                exp[++j] = pop(S);
            }
            if (!isEmpty(S) && peek(S) != '(')
            {
                return -1; // invalid expression
            }
            else
            {
                pop(S);
            }
        }
        else
        {
            while (!isEmpty(S) && precedence(exp[i]) <= precedence(peek(S)))
            {
                exp[++j] = pop(S);
            }
            push(S, exp[i]);
        }
    }

    while (!isEmpty(S))
    {
        exp[++j] = pop(S);
    }

    exp[++j] = '\0';

    return 1;

}

int main()
{

    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    printf("%s\n", exp);
    return 0;

}





struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)
        malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity *
                                 sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}
