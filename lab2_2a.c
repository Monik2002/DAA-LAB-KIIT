#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }
    int num1, num2;
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF)
    {
        int result = gcd(num1, num2);
        fprintf(output_file, "GCD of %d and %d is %d\n", num1, num2, result);
    }
    fclose(input_file);
    fclose(output_file);
    printf("GCD calculation completed and results stored in 'output.txt'.\n");
    return 0;
}