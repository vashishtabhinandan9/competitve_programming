/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

*/

int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), ans;
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low<=high){
            int mid = (low + high)/2;
            int i = 0, j = n-1, count =0;
            while(i<n && j >= 0){
                if (mid < matrix[i][j]){
                    j--;
                }else if (mid >= matrix[i][j]){
                    count += j+1;
                    i++;   
                }    
            }
            if(count>=k){
                ans = mid;
                high = mid-1;
            }else if(count<k){
                low = mid+1;
            }
        }
        return ans;