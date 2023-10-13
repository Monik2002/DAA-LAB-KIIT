#include <stdio.h>
void decimalToBinary(int num, FILE *outputFile)
{
    if (num > 0)
    {
        decimalToBinary(num / 2, outputFile);
        fprintf(outputFile, "%d", num % 2);
    }
}

int main()
{
    int n;
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the name of the input disc file: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }
    printf("Enter the name of the output disc file: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL)
    {
        printf("Error opening the output file.\n");
        return 1;
    }
    int decimalNumber;
    for (int i = 0; i < n; i++)
    {
        if (fscanf(inputFile, "%d", &decimalNumber) != 1)
        {
            printf("Error reading decimal number from input file.\n");
            return 1;
        }
        decimalToBinary(decimalNumber, outputFile);
        fprintf(outputFile, "\n");
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("%d decimal numbers converted to binary and stored in the output file.\n", n);

    return 0;
}