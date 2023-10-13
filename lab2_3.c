#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    clock_t t1, t2;
    t1 = clock();
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int n = 0;

    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &arr[n]) == 1)
    {
        n++;
        if (n >= MAX_SIZE)
        {
            break;
        }
    }
    fclose(file);

    selectionSort(arr, n);

    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    t2 = clock();
    printf("Time taken: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}