#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method


void inPlaceMerge(vector<int> &nums, int low, int mid, int high) {
	if (low >= high) return;
	int l = low, r = mid + 1, size = high - low + 1;
	while (l <= mid and r <= high) {
		if (nums[l] <= nums[r]) l++;
		else {
			int val = nums[r];
			for (int k = r++; k > l; k--)
				nums[k] = nums[k - 1];
			nums[l++] = val;
			mid++;
		}
	}
}

void outPlaceMerge(vector<int> &nums, int low, int mid, int high) {
	if (low >= high) return;
	int l = low, r = mid + 1, k = 0, size = high - low + 1;
	vector<int> sorted(size, 0);
	while (l <= mid and r <= high)
		sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	while (l <= mid) 
		sorted[k++] = nums[l++];
	while (r <= high) 
		sorted[k++] = nums[r++];
	for (k = 0; k < size; k++)
		nums[k + low] = sorted[k];
}

void mergeSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	int mid = (high - low) / 2 + low;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid + 1, high);
	inPlaceMerge(nums, low, mid, high);
    outPlaceMerge(nums, low, mid, high);
}
void printarray(vector<int>& arr){
       for(int i=0;i<arr.size();i++) cout<<arr[i];
       }

int main(){
   int n;
       cin>>n;
       vector<int> arr(n,0);
       for(int i=0;i<n;i++) cin>>arr[i];

       mergeSort(arr,0,n-1);

       printarray(arr);
       
    return 0;
}