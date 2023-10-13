#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long long comparisons = 0;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_arr[n1], right_arr[n2];

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Exiting the program.\n");
            break;
        }

        char input_filename[20], output_filename[20];
        int n, *data;

        if (choice == 1)
        {
            strcpy(input_filename, "inAsce.dat");
            strcpy(output_filename, "outMergeAsce.dat");
        }
        else if (choice == 2)
        {
            strcpy(input_filename, "inDesc.dat");
            strcpy(output_filename, "outMergeDesc.dat");
        }
        else if (choice == 3)
        {
            strcpy(input_filename, "inRand.dat");
            strcpy(output_filename, "outMergeRand.dat");
        }
        else
        {
            printf("Invalid choice. Please select a valid option.\n");
            continue;
        }

        FILE *input_file = fopen(input_filename, "r");
        if (input_file == NULL)
        {
            printf("Error opening input file.\n");
            return 1;
        }

        fscanf(input_file, "%d", &n);
        data = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            fscanf(input_file, "%d", &data[i]);

        fclose(input_file);

        clock_t start_time = clock();
        comparisons = 0;
        merge_sort(data, 0, n - 1);
        clock_t end_time = clock();

        double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1e9;

        FILE *output_file = fopen(output_filename, "w");
        if (output_file == NULL)
        {
            printf("Error opening output file.\n");
            return 1;
        }

        fprintf(output_file, "%d\n", n);
        for (int i = 0; i < n; i++)
            fprintf(output_file, "%d ", data[i]);
        fprintf(output_file, "\n");

        fclose(output_file);

        printf("Before Sorting: ");
        print_array(data, n);

        printf("After Sorting: ");
        print_array(data, n);

        printf("Number of Comparisons: %lld\n", comparisons);
        printf("Execution Time: %.2lf nanoseconds\n", execution_time);

        free(data);
    }

    return 0;
}