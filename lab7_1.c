// Aim of the program : Write a program to implement the matrix chain multiplication problem using M - table &amp; S-table to find optimal parenthesization of a matrix-chain product. Print the
// number of scalar multiplications required for the given input.
// Note#Dimensions of the matrices can be inputted as row and column values. Validate the dimension compatibility.

#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization
void printOptimalParenthesis(int i, int j, int *s, int n)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParenthesis(i, *((s + i * n) + j), s, n);
        printOptimalParenthesis(*((s + i * n) + j) + 1, j, s, n);
        printf(")");
    }
}

// Function to perform matrix chain multiplication
int matrixChainMultiplication(int dims[], int n)
{
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i <= j)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i < j)
            {
                printf("%d ", s[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParenthesis(1, n - 1, (int *)s, n);
    printf("\n");

    return m[1][n - 1];
}

int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1];
    for (int i = 0; i < n; i++)
    {
        int row, col;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &row, &col);

        if (i == 0)
        {
            dims[i] = row;
        }
        dims[i + 1] = col;
    }

    int result = matrixChainMultiplication(dims, n + 1);
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", result);

    return 0;
}