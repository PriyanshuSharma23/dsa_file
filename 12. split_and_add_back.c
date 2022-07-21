#include <stdio.h>

int main() {
    int arr[100];
    
    int n;
    printf("Enter the number of elements in the array (< 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the index to split the array: ");
    scanf("%d", &key);

    if (key > n) {
        printf("Invalid index!\n");
        return 0;
    }

    int left[100];
    
    // store the left part of the array into left[]
    for (int i = 0; i < key; i++) {
        left[i] = arr[i];
    }

    int right[100];
    for (int i = key; i < n; i++) {
        right[i - key] = arr[i];
    }

    int result[100];
    int result_index = 0;
    for (int i = 0; i < n - key; i++) {
        result[result_index] = right[i];
        result_index++;
    }

    for (int i = 0; i < key; i++) {
        result[result_index] = left[i];
        result_index++;
    }

    // print the result array
    printf("The result array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;

}