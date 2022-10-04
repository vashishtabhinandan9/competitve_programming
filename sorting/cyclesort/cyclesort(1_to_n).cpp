//ques: This method is only
// applicable when given array values or elements are in the range of 1 to N or  0 to N
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method
void cyclesort(int arr[],int n,int x){    
    while(arr[x-1]!=x){
        int y=arr[x-1];
        arr[x-1]=x;
        x=y;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    if(arr[i]!=i+1)
    cyclesort(arr,n,arr[i]);

    for(int i=0;i<n;i++) cout<<arr[i];
}

//2nd method

void cyclicSort2(int arr[], int n){
  int i = 0;
  while(i < n)
  {
    // as array is of 1 based indexing so the
    // correct position or index number of each
    // element is element-1 i.e. 1 will be at 0th
    // index similarly 2 correct index will 1 so
    // on...
    int correct = arr[i] - 1 ;
    if(arr[i] != arr[correct]){
 
      // if array element should be lesser than
      // size and array element should not be at
      // its correct position then only swap with
      // its correct position or index value
      swap(arr[i], arr[correct]) ;
    }else{
 
      // if element is at its correct position
      // just increment i and check for remaining
      // array elements
      i++ ;
    }
  }
 
}
