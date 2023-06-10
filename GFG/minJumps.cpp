#include <bits/stdc++.h>
using namespace std;
//O(N) time complexity
int minJumps(int arr[], int n)
{
	if (n <= 1) // If there is only one element or the array
				// is empty, we have reached the end of the
				// array with 0 jumps
		return 0;
	if (arr[0] == 0) // If the first element is 0, we can't
					// move forward
		return -1;

	int maxReach
		= arr[0]; // Stores the maximum index that can be
				// reached with the current jump
	int steps
		= arr[0]; // Stores the number of steps that can be
				// taken from the current index
	int jumps
		= 1; // Stores the number of jumps taken so far

	for (int i = 1; i < n; i++) {
		if (i == n - 1) // If we have reached the end of the
						// array, return the number of jumps
						// taken so far
			return jumps;
		maxReach
			= max(maxReach,
				i + arr[i]); // Update the maximum index
							// that can be reached with
							// the current jump
		steps--; // Decrement the number of steps that can
				// be taken from the current index
		if (steps == 0) { // If no more steps can be taken
						// from the current index, we need
						// to take another jump
			jumps++; // Increment the number of jumps taken
					// so far
			if (i >= maxReach) // If the current index is
							// greater than the maximum
							// index that can be reached,
							// return -1
				return -1;
			steps = maxReach - i; // Update the number of
								// steps that can be taken
								// from the current index
		}
	}
	return -1; // If we haven't reached the end of the
			// array, return -1
}

int main()
{
	int n = 11;
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	cout << minJumps(arr, n) << endl;

	return 0;
}

// This code is contributed by Vaibhav Saroj
