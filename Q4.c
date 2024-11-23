/*
Q4. Count Duplicate Elements
Given an integer array, numbers, count the number of elements that occur more than once.
Example numbers = [1, 3, 3, 4, 4, 4]

There are two non-unique elements: 3 and 4.
    Function Description:-
    Complete the function countDuplicate in the editor below.
    countDuplicate has the following parameter(s):
    int numbers[n]: an array of integers
    Returns: int: an integer that denotes the number of non-unique values in the numbers array
*/
#include <stdio.h>
#include <stdlib.h>

int countDuplicate(int *numbers, int n);

int main()
{
    int numbers[] = {1, 3, 3, 4, 4, 4};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int result = countDuplicate(numbers, n);
    printf("Number of duplicate elements: %d\n", result);
    return 0;
}

int countDuplicate(int *numbers, int n)
{
    int count = 0;
    int *frequency = (int *)calloc(1001, sizeof(int)); // Assuming numbers are between 0 and 1000

    // Count occurrences of each number
    for (int i = 0; i < n; i++)
    {
        frequency[numbers[i]]++;
    }

    // Count how many numbers occur more than once
    for (int i = 0; i < 1001; i++)
    {
        if (frequency[i] > 1)
        {
            count++;
        }
    }

    free(frequency);
    return count;
};
