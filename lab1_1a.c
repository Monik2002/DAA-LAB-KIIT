#include <stdio.h>
#include <time.h>

int main()
{
    clock_t t1, t2;
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    t1 = clock();

    int smallest = arr[0];
    int second_smallest = arr[0];
    int largest = arr[0];
    int second_largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
    printf("Second Smallest Element: %d\n", second_smallest);
    printf("Second Largest Element: %d\n", second_largest);
    t2 = clock();
    printf("Time taken: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}