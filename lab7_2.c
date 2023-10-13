// Aim of the program: Write a program to find out the Longest Common Subsequence of two given strings.Calculate length of the LCS.

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void findLCS(char str1[], char str2[], int m, int n)
{
    int lcs[m + 1][n + 1];

    // Build the LCS matrix
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    int length = lcs[m][n];
    char lcsString[length + 1];
    lcsString[length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcsString[length - 1] = str1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcsString);
    printf("LCS Length: %d\n", lcs[m][n]);
}

int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    findLCS(str1, str2, m, n);

    return 0;
}