#include <stdio.h>
#include <stdlib.h>

struct BetterArr
{
    int arr[20];
    int length;
    int size;
};

typedef struct BetterArr arr;

arr *insert(arr *A, int location, int x)
{
    if (location > A->length)
        return NULL;
    for (int i = A->length; i != location; i--)
    {
        A->arr[i] = A->arr[i - 1];
    }
    A->arr[location] = x;
    A->length += 1;
    return A;
}

int Get(arr *A, int n)
{
    if (n >= A->length || n < 0)
        return -1;
    else
        return A->arr[n];
}

arr *Delete(arr *A, int i)
{
    for (int j = i; j < A->length; j++)
    {
        A->arr[j] = A->arr[j + 1];
    }
    A->length -= 1;
    return A;
}

int Search(arr *A, int x)
{
    int index = -1;
    for (int i = 0; i < A->length; i++)
    {
        if (A->arr[i] == x)
        {
            index = i;
            return index;
        }
    }

    return index;
}

arr *addElement(arr *A, int n)
{
    A->arr[A->length] = n;
    A->length += 1;
    return A;
}

void DisplayArray(arr *A)
{
    for (int i = 0; i < A->length; i++)
    {
        printf("%d ", A->arr[i]);
    }
    printf("\n");
}

int main()
{

    arr A = {.arr = {0}, .length = 0, .size = 20};

    printf("Welcome to array user driven program!\n");

    while (1)
    {
        printf("1) Insert Element\n");
        printf("2) Insert to last\n");
        printf("3) Delete Element\n");
        printf("4) Search Element\n");
        printf("5) Print Array\n");
        printf("6) Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int location, x;
            printf("Enter location: ");
            scanf("%d", &location);
            printf("Enter element: ");
            scanf("%d", &x);
            A = *(insert(&A, location, x));
            printf("Element inserted!\n");
            break;
        case 2:
            int n;
            printf("Enter element: ");
            scanf("%d", &n);
            A = *(addElement(&A, n));
            printf("Element added!\n");
            break;
        case 3:
            int i;
            printf("Enter location: ");
            scanf("%d", &i);
            A = *(Delete(&A, i));
            printf("Element deleted!\n");
            break;
        case 4:
            int key;
            printf("Enter key to search: ");
            scanf("%d", &key);
            int index = Search(&A, key);
            if (index == -1)
                printf("Element not found!\n");
            else
                printf("Element found at index %d\n", index);
        case 5:
            DisplayArray(&A);
            break;
        case 6:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}