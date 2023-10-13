#include <stdio.h>
#include <time.h>

void readIntArrayFromFile(char *filename, int arr[], int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

int countDuplicates(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break; // Count duplicate only once
            }
        }
    }

    return count;
}

int findMostRepeatingElement(int arr[], int n)
{
    int maxCount = 0;
    int mostRepeatedElement = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 1; // Count current element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostRepeatedElement = arr[i];
        }
    }

    return mostRepeatedElement;
}

int main()
{
    clock_t t1, t2;
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    t1 = clock();
    int arr[n];

    readIntArrayFromFile("input.txt", arr, n);
    printf("The content of the array: ");

    // printf("The content of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int totalDuplicates = countDuplicates(arr, n);
    printf("Total number of duplicate values = %d\n", totalDuplicates);

    int mostRepeatedElement = findMostRepeatingElement(arr, n);
    printf("The most repeating element in the array = %d\n", mostRepeatedElement);

    t2 = clock();
    printf("Time taken: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}
