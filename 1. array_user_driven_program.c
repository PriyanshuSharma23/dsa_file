#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int main()
{
    int arr[MAX_LENGTH];
    int i = 0;

    printf("Welcome to array user driven program!\n");
    while (1)
    {
        printf("1) Enter a number\n");
        printf("2) Print array\n");
        printf("3) Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            int num;
            scanf("%d", &num);
            arr[i] = num;
            i++;
        }
        else if (choice == 2)
        {
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
        else if (choice == 3)
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