/*
** Author: Stephen Sheldon 3/8/2019
** A simple binary search
**
** Time Complexity
** Search: O(logn)
*/

#include <stdio.h>

int binary_search(int arr[], int value, int low, int high);

int main()
{
	int arr[10] = {1, 5, 11, 34, 56, 61, 72, 84, 98, 102};
	int value, result;
	
	printf("What integer would you like to search the array for?\n");
	scanf("%d", &value);
	
	result = binary_search(arr, value, 0, 9);
	
	if (result == -1)
		printf("Sorry, could not find %d in the array!\n", value);
	else
		printf("We found %d in the array at index %d!\n", value, result);
	
	system("PAUSE");
	exit(0);
}

int binary_search(int arr[], int value, int low, int high)
{
	int middle;
	printf("Low is %d, high is %d\n\n", low ,high);
	// Value is not in array
	if (low > high)
		return -1;
	
	middle = (low + high)/2;
	
	// Check if we have found the value
	if (value == arr[middle])
		return middle;
	
	// Is the value below our middle value in the subarray
	if (value < arr[middle])
		binary_search(arr, value, low, middle -1 );
	else // or is it above?
		binary_search(arr, value, low + 1, high);
}
