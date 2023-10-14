#include <stdio.h>

// Function to find an element x in a circularly sorted array
int circularArraySearch(int A[], int n, int x)
{
	// search space is A[low..high]
	int low = 0, high = n - 1;

	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// find the mid value in the search space and
		// compares it with target value
		int mid = (low + high)/2;

		// if target is found, return its index
		if (x == A[mid])
			return mid;

		// if right half (A[mid..high]) is sorted and mid is not
		// the target element
		if (A[mid] <= A[high])
		{
			// compare target with A[mid] and A[high] to know
			// if it lies in A[mid..high] or not
			if (x > A[mid] && x <= A[high])
				low = mid + 1;	// go searching in right sorted half
			else
				high = mid - 1;	// go searching left
		}

		// if left half (A[low..mid]) is sorted and mid is not
		// the target element
		else
		{
			// compare target with A[low] and A[mid] to know
			// if it lies in A[low..mid] or not
			if (x >= A[low] && x < A[mid])
				high = mid - 1;	// go searching in left sorted half
			else
				low = mid + 1;	// go searching right
		}
	}

	// target not found or invalid input
	return -1;
}

// main function
int main(void)
{
	int A[] = {9, 10, 2, 5, 6, 8};
	int target = 5;

	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);

	if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found in the array");

	return 0;
}
