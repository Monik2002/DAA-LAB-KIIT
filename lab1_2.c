#include <stdio.h>
#include <time.h>

void calculatePrefixSum(int arr[], int prefixSum[], int N)
{
    prefixSum[0] = arr[0]; // The first element of prefixSum is the same as the first element of arr

    // Calculate the prefix sum for the rest of the elements
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main()
{
    clock_t t1, t2;
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N], prefixSum[N];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    t1 = clock();

    calculatePrefixSum(arr, prefixSum, N);

    printf("Prefix sum array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    t2 = clock();
    printf("Time taken: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}
