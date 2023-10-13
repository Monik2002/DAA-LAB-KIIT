#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    if (inFile == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }

    FILE *outFile = fopen(argv[2], "w");
    if (outFile == NULL)
    {
        printf("Error opening the output file.\n");
        fclose(inFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(inFile, "%d %d", &num1, &num2) == 2)
    {
        int result = gcd(num1, num2);
        fprintf(outFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    printf("GCDs of the pairs have been calculated and stored in %s.\n", argv[2]);

    fclose(inFile);
    fclose(outFile);
    return 0;
}