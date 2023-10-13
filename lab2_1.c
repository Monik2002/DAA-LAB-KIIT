#include <stdio.h>

void decimalToBinary(FILE *inFile, FILE *outFile)
{
    int num;
    if (fscanf(inFile, "%d", &num) != 1)
    {
        return; // Reached end of file or error
    }

    int binary[16] = {0}; // Assuming 16-bit binary representation
    int i = 15;

    // Convert the decimal number to binary using recursion
    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i--;
    }

    // Write the binary value to the output file
    fprintf(outFile, "The binary equivalent of %d is ", num);
    for (i = 0; i < 16; i++)
    {
        fprintf(outFile, "%d", binary[i]);
    }
    fprintf(outFile, "\n");

    // Call the function recursively for the next decimal number
    decimalToBinary(inFile, outFile);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("Invalid value of 'n'. It should be a positive integer.\n");
        return 1;
    }

    FILE *inFile = fopen(argv[2], "r");
    if (inFile == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }

    FILE *outFile = fopen(argv[3], "w");
    if (outFile == NULL)
    {
        printf("Error opening the output file.\n");
        fclose(inFile);
        return 1;
    }

    printf("Decimal Numbers and their Binary Equivalents:\n");
    decimalToBinary(inFile, outFile);

    fclose(inFile);
    fclose(outFile);
    return 0;
}