/**
 * question:
 * https://leetcode.com/problems/single-element-in-a-sorted-array/
 * 
 * solution:
 * https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/1587251/C%2B%2B-Easy-and-Concise-O(logn)-Solution-(W-Explanation)
 * 
 * 

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/




/**
 APPROACH 1: by binary search

So, the array has all the elements repeating twice except for one element which appears only once and the array is sorted.
This means that in every number that's repeated, the first number is at an even index (index%2==0) and the 2nd number is at an odd index.
The idea is to peform a binary search over the entire array and find out if this pattern follows. If somewhere this pattern is broken, then we're going to know in which half of the array there is an element that appears only once.
We reduce the search space to that half an search again, until we're left with a single element, which is the final answer.
Let us look at the first example :

        0    1    2    3    4    5    6    7    8
nums = [1,   1,   2,   3,   3,   4,   4,   8,   8]

We start with left = 0, right = 8 => mid = 0+(8-0)/2 = 4
Now, 4 is an even index which means the first repeating number should be at 4 and the next at 5. 
But nums[4] != nums[5]. So on the left half the pattern's broken. 

*/

int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0, r=nums.size()-1, mid, num;
        
        while(l < r){
            mid = l+(r-l)/2;
            num = (mid%2 == 0) ? mid+1 : mid-1;
            if(nums[mid]==nums[num]) l = mid+1;
            else r = mid;
        }
        return nums[l];
    }

    /**
     *  APPROACH 1: by XOR
     * xor of same element is 0 xor of  number a with 0 is a;
    */
    int singleNonDuplicate(vector<int>& nums) {
        int xOR=0;  //a^a = 0. So all the elements repeating twice become '0' and we return the non-repeating element.
        for(int i=0;i<nums.size();i++) xOr ^= nums[i];
        
        return xOR;
    }