#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    clock_t t1, t2;
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int n = 0;

    t1 = clock();
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

    bubbleSort(arr, n);

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