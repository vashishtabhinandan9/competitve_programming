//    https://www.geeksforgeeks.org/find-distinct-elements-common-rows-matrix/?ref=lbp


/*

Method 2: Sort all the rows of the matrix individually in increasing order. 
Then apply a modified approach to the problem of
finding common elements in 3 sorted arrays. 
Below an implementation for the same is given. 

*/
// C++ implementation to find distinct elements
// common to all rows of a matrix
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

// function to individually sort
// each row in increasing order
void sortRows(int mat[][MAX], int n)
{
	for (int i=0; i<n; i++)
		sort(mat[i], mat[i] + n);
}

// function to find all the common elements
void findAndPrintCommonElements(int mat[][MAX], int n)
{
	// sort rows individually
	sortRows(mat, n);

	// current column index of each row is stored
	// from where the element is being searched in
	// that row
	int curr_index[n];
	memset(curr_index, 0, sizeof(curr_index));
	int f = 0;

	for (; curr_index[0]<n; curr_index[0]++)
	{
		// value present at the current column index
		// of 1st row
		int value = mat[0][curr_index[0]];

		bool present = true;

		// 'value' is being searched in all the
		// subsequent rows
		for (int i=1; i<n; i++)
		{
			// iterate through all the elements of
			// the row from its current column index
			// till an element greater than the 'value'
			// is found or the end of the row is
			// encountered
			while (curr_index[i] < n &&
				mat[i][curr_index[i]] <= value)
				curr_index[i]++;

			// if the element was not present at the column
			// before to the 'curr_index' of the row
			if (mat[i][curr_index[i]-1] != value)
				present = false;

			// if all elements of the row have
			// been traversed
			if (curr_index[i] == n)
			{
				f = 1;
				break;
			}
		}

		// if the 'value' is common to all the rows
		if (present)
			cout << value << " ";

		// if any row have been completely traversed
		// then no more common elements can be found
		if (f == 1)
			break;
	}
}

// Driver program to test above
int main()
{
	int mat[][MAX] = { {12, 1, 14, 3, 16},
		{14, 2, 1, 3, 35},
		{14, 1, 14, 3, 11},
		{14, 25, 3, 2, 1},
		{1, 18, 3, 21, 14}
	};

	int n = 5;
	findAndPrintCommonElements(mat, n);
	return 0;
}
