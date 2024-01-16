#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Number of elements in the array
    int *arr; // Pointer to the dynamically allocated array

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Return an error code
    }

    // Input elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the elements
    printf("Elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0; // Return success code
}
