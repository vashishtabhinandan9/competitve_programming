/**
 * 
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
*/

// https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/1756967/Well-Explained-oror-Two-Easy-Solutions

//          solution1:

 int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0, j = 1;
        for(i, j; i<nums.size() && j<nums.size(); ) {
            if(i==j || nums[j]-nums[i]<k) j++;
            else {
                if(nums[j]-nums[i]==k) {
                    ans++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++; // remove redundant
                }
                i++;
                while(i<j && nums[i]==nums[i-1]) i++; // remove redundant
            }
        }
        return ans;
    }

