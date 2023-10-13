#include <stdio.h>
#include <time.h>

// Function to swap two elements in the array
void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate the first p2 elements of the array to the right by 1 position
void ROTATE_RIGHT(int p1[], int p2)
{
    int lastElement = p1[p2 - 1];

    // Shift elements to the right by one position
    for (int i = p2 - 1; i > 0; i--)
    {
        p1[i] = p1[i - 1];
    }

    // Place the lastElement at the beginning of the rotated section
    p1[0] = lastElement;
}

int main()
{
    clock_t t1, t2;
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int A[N];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int p2;
    printf("Enter the number of elements to be rotated: ");
    scanf("%d", &p2);

    t1 = clock();
    printf("Before ROTATE: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, p2);

    printf("After ROTATE: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    t2 = clock();
    printf("Time taken: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}
