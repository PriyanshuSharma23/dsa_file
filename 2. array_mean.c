#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    printf("The mean of the array is %.2f\n", (float)sum / n);

    return 0;
}