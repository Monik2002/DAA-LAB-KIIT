#include <stdio.h>

int insertionSort(int arr[], int n)
{
    int comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }

        arr[j + 1] = key;
    }
    return comparisons;
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrayToFile(int arr[], int size, FILE *file)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n");
}

int main()
{
    int choice;
    FILE *inputFile, *outputFile;
    int arr[500];

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outInsAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outInsDesc.txt", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outInsRand.dat", "w");
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (inputFile == NULL || outputFile == NULL)
        {
            printf("Error opening files.\n");
            return 1;
        }

        int n = 0;
        while (fscanf(inputFile, "%d", &arr[n]) != EOF)
        {
            n++;
        }

        printf("Before Sorting: ");
        displayArray(arr, n);

        int comparisons = insertionSort(arr, n);

        printf("After Sorting: ");
        displayArray(arr, n);

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == 0)
        {
            printf("Scenario: Best-case\n");
        }
        else if (comparisons == (n * (n - 1)) / 2)
        {
            printf("Scenario: Worst-case\n");
        }
        else
        {
            printf("Scenario: Average-case\n");
        }

        // Write the sorted array to the output file
        printArrayToFile(arr, n, outputFile);

        fclose(inputFile);
        fclose(outputFile);
    }

    return 0;
}
