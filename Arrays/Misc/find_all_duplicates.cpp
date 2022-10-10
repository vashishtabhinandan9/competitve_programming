/**
 * question:
Given an array of n elements that contains elements from 0 to n-1,
 with any of these numbers appearing any number of times. Find these repeating numbers in O(n) 
 and using only constant memory space.

1st method : using modulo
Approach: The basic idea is to use a HashMap to solve the problem.
 But there is a catch, the numbers in the array are from 0 to n-1,
and the input array has length n. So, the input array can be used as a HashMap. 
While Traversing the array, if an element ‘a’ is encountered then increase
 the value of a%n‘th element by n. 
 The frequency can be retrieved by dividing the a % n’th element by n.
Algorithm: 
Traverse the given array from start to end.
For every element in the array increment the arr[i]%n‘th element by n.
Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1.
 Which guarantees that the number n has been added to that index

This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater
 than n only if a value “i” has appeared more than once.


 2nd method:make elements negatie
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
        }
        return res;
    }

**/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method

int main(){
    vector<int> ans={3,3,3,5,4,4,1,1};
   findDuplicates(ans);
    return 0;
}

 vector<int> findDuplicates(vector<int>& numRay) {
        int arr_size=numRay.size();
        	for (int i = 0; i < arr_size; i++) {
		numRay[numRay[i] % arr_size]
			= numRay[numRay[i] % arr_size] + arr_size;
	}
        vector<int> ans;
        	for (int i = 0; i < arr_size; i++) {
		if (numRay[i] >= arr_size * 2) {
			ans.push_back(i);
		}
	}
        return ans;
    }
