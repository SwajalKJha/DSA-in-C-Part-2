/*
Q1. Write a C/C++ program to implement Linear Search. We need to check for duplicate inputs. If the
	duplicate element is allowed then a linear search algo needs to implement accordingly. An
	appropriate condition check needs to apply for element not found scenario.
(a) Search Element ( iterative approach )
(b) Search Element ( recursion approach )
(c) Print Input array ( iterative approach )
(d) Print Input array ( recursion approach )
(e) Print Input array reverse order ( iterative approach )
(f) Print Input array reverse order ( recursion approach )
*/

#include <stdio.h>
#include <stdlib.h>

int search_element_iteration(int *arr, int n);
int search_element_recursion(int *arr, int n, int x);
void print_array_iteration(int *arr, int n);
void print_array_recursion(int *arr, int n);
void print_reverse_array_iteration(int *arr, int n);
void print_reverse_array_recursion(int *arr, int n);

int main()
{
	int *arr, n, choice;

	printf("Enter the size of array: ");
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int)); // malloc for dynamic array
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	printf("Enter Data in the array\n"); // enter the array data
	printf("-------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("Please enter for location %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	int foundDuplicate = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				printf("Duplicate value found: %d\n", arr[i]);
				foundDuplicate = 1;
				break; // Break to avoid multiple prints for the same duplicate
			}
		}
	}
	if (!foundDuplicate)
	{
		printf("No duplicates found.\n");
	}

	while (1)
	{
		printf("\n");
		printf("Options:\n (1) Search Element (iterative approach)\n (2) Search Element (recursion approach)\n (3) Print Input array (iterative approach)\n (4) Print Input array (recursion approach)\n (5) Print Input array reverse order (iterative approach)\n (6) Print Input array reverse order (recursion approach)\n (7) Quit\n");
		printf("Enter the choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			search_element_iteration(arr, n);
			break;
		case 2:
			int x;
			printf("Enter the number to search: ");
			scanf("%d", &x);
			if (!search_element_recursion(arr, n, x))
			{
				printf("The number is not found in the array");
			}
			break;
		case 3:
			print_array_iteration(arr, n);
			break;
		case 4:
			print_array_recursion(arr, n);
			break;
		case 5:
			print_reverse_array_iteration(arr, n);
			break;
		case 6:
			print_reverse_array_recursion(arr, n);
			break;
		case 7:
			printf("Quiting...\n");
			return 0;
		default:
			printf("Invalid Choice\n");
			break;
		}
		printf("\n*************************\n");
	}
	return 0;
}

int search_element_iteration(int *arr, int n)
{
	int x, found = 0;
	printf("Enter the number to search: ");
	scanf("%d", &x);

	for (int j = 0; j < n; j++)
	{
		if (arr[j] == x)
		{
			found = 1;
			printf("The number is found at location %d", j + 1);
			break;
		}
	}
	if (!found)
	{
		printf("The number is not found in the array");
	}
	return found;
}

int search_element_recursion(int *arr, int n, int x)
{
	if (n <= 0)
	{
		return 0;
	}
	if (arr[n - 1] == x)
	{
		printf("The number is found at location %d", n);
		return 1;
	}
	return search_element_recursion(arr, n - 1, x);
}

void print_array_iteration(int *arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		printf("%d ", arr[j]);
	}
}

void print_array_recursion(int *arr, int n)
{
	if (n <= 0)
	{
		return;
	}
	print_array_recursion(arr, n - 1);
	printf("%d ", arr[n - 1]);
}

void print_reverse_array_iteration(int *arr, int n)
{
	for (int j = n - 1; j >= 0; j--)
	{
		printf("%d ", arr[j]);
	}
}

void print_reverse_array_recursion(int *arr, int n)
{
	if (n <= 0)
	{
		return;
	}
	printf("%d ", arr[n - 1]);
	print_reverse_array_recursion(arr, n - 1);
}
