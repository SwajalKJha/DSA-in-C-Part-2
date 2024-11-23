/*
Q2. Write a C/C++ program to implement Binary Search. We need to check for duplicate element
    inputs, if found any should not insert into the input array. The array should manage in sorted order.
    Apply a duplicacy check on the element while inserting the element, if found duplicate then discards
    the input. The input element should insert in the array at the right position( index). Appropriate
    shifting can be applied in the array in order to insert the input element at the right position. An
    appropriate condition check needs to apply for element not found scenario.
(a) Binary Search ( iterative approach)
(b) Binary Search ( recursion approach )
*/
#include <stdio.h>

#define MAX 5

void bubbleSort(int arr[], int count);
int binarySearch(int arr[], int start, int end, int x);
int isDuplicate(int arr[], int count, int value);

int main()
{
    int arr[MAX];
    int count = 0;
    int x, choice;

    // Input elements into the array
    while (count < MAX)
    {
        int input;
        printf("Enter element for index %d: ", count);
        scanf("%d", &input);

        if (isDuplicate(arr, count, input) == 0)
        {
            arr[count] = input;
            count++;
        }
        else
        {
            printf("Duplicate value! Please enter a different number.\n");
        }
    }

    // Print the input array
    printf("The input array is: ");
    for (int i = 0; i < count; i++)

        printf("%d ", arr[i]);
}
printf("\n");

bubbleSort(arr, count);

printf("The sorted array is: ");
for (int i = 0; i < count; i++)
{
    printf("%d ", arr[i]);
}
printf("\n");

int start = 0;
int end = count - 1;

printf("\nEnter the number you want to search: ");
scanf("%d", &x);

printf("Do Searching with (1) Iteration (2) Recursion: ");
scanf("%d", &choice);

int result = binarySearch(arr, start, end, x);
if (result != -1)
{
    printf("\nElement found at index %d!\n", result);
}
else
{
    printf("\nElement not found!\n");
}

return 0;
}

void bubbleSort(int arr[], int count)
{
    // Sorting the array
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isDuplicate(int arr[], int count, int value)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == value)
        {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

int binarySearch(int arr[], int start, int end, int x)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, start, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, end, x);
        }
    }
    return -1;
}
