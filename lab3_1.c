#include <stdio.h>

int binarySearchLeftmost(int arr[], int size, int key, int *comparisons)
{
    int low = 0, high = size - 1, result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        (*comparisons)++; // Counting the comparison

        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1; // Continue searching on the left side for leftmost occurrence
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

    return result;
}

int main()
{
    int size, key;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int comparisons = 0;
    int position = binarySearchLeftmost(arr, size, key, &comparisons);

    if (position != -1)
    {
        printf("%d found at index position %d\n", key, position);
        printf("Number of comparisons: %d\n", comparisons);
    }
    else
    {
        printf("%d not found in the array\n", key);
    }

    return 0;
}
