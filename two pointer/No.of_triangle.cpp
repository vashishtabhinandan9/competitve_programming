/**
 * question:
 * Given an unsorted array of positive integers, 
 * find the number of triangles that can be formed with three different array elements as 
 * three sides of triangles. For a triangle to be possible from 3 values, 
 * the sum of any of the two values (or sides) must be greater than the third value (or third side). 
 * */


#include <bits/stdc++.h>
using namespace std;

void CountTriangles(vector<int> A)
{

	int n = A.size();

	sort(A.begin(), A.end());

	int count = 0;

	for (int i = n - 1; i >= 1; i--) {
		int l = 0, r = i - 1;
		while (l < r) {
			if (A[l] + A[r] > A[i]) {

				// If it is possible with a[l], a[r]
				// and a[i] then it is also possible
				// with a[l+1]..a[r-1], a[r] and a[i]
				count += r - l;

				// checking for more possible solutions
				r--;
			}
			else

				// if not possible check for
				// higher values of arr[l]
				l++;
		}
	}
	cout << "No of possible solutions: " << count;
}

// Driver code
int main()
{

	vector<int> A = { 10, 21, 22, 100, 101, 200, 300 };

	// Function call
	CountTriangles(A);
}
