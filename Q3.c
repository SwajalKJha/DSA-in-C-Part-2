/*
Q3. Find the Factor
    Determine the factors of a number (i.e., all positive integer values that evenly divide into a number) and then
    return the pth element of the list, sorted ascending. If there is no pth element, return 0.

Example: n = 20 and p = 3
    The factors of 20 in ascending order are {1, 2, 4, 5, 10, 20}. Using 1-based indexing, if p = 3, then 4 is
    returned. If p > 6, 0 would be returned.

    Function Description:-
    Complete the function pthFactor in the editor below.
    pthFactor has the following parameter(s):
    int n: the integer whose factors are to be found
    int p: the index of the factor to be returned
    Returns: int: the long integer value of the pth integer factor of n or, if there is no factor at that index, then 0 is returned
*/

#include <stdio.h>

int pthFactor(int n, int p);

int main()
{
    int n, p;
    printf("Enter number to find Factor: ");
    scanf("%d", &n);
    printf("Enter the index of which factor value to pick: ");
    scanf("%d", &p);

    int result = pthFactor(n, p);
    printf("Choosen Factor is: %d\n", result);
    return 0;
}

int pthFactor(int n, int p)
{
    // Array to store factors
    int factors[100];
    int count = 0;

    // Find factors of n
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors[count++] = i; // Store the factor and increment count
        }
    }
    // display factor array
    printf("Factors are: ");
    for (int j = 0; j < count; j++)
    {
        printf(" %d ", factors[j]);
    }
    printf("\n");

    // Check if p is within the range of factors

    if (p <= count)
    {
        return factors[p - 1]; // p is 1-based index
    }
    else
    {
        return 0;
    }
}
