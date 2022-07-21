#include <stdio.h>
#define MAX_LENGTH 100

int binarySearch(int arr[], int n, int key)
{
    int low = 0; 
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[MAX_LENGTH];

    int n;
    printf("Enter the number of elements in the array (sorted): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Applying binary search...\n");

    int index = binarySearch(arr, n, key);

    if (index == -1)
    {
        printf("Element not found!\n");
    }
    else
    {
        printf("Element found at index %d!\n", index);
    }


}