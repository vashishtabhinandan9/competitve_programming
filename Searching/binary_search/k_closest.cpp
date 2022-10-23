#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method
int flor;
int crossover(int arr[],int x,int k,int l,int r){
    /* Function to find the cross over point (the point before
which elements are smaller than or equal to x and after
which greater than x)*/

//***** basically finding floor of the element
    if(l>=r) return flor;
    int m=(l+r)/2;
    if(arr[m]==x) {
        flor= m;
   return  crossover(arr,x,k,l,m-1);
     }
    else if(arr[m]>x)  {
       return  crossover(arr,x,k,l,m-1);
    }

    else { 
        flor=m;
      return  crossover(arr,x,k,m+1,r);
        }
    return flor;
}

void printKclosest(int arr[],int x,int k, int n){
    int l=0,r=n-1,cnt=0;
int ind= crossover(arr,x,k,l,r);
cout<< "flor" << arr[ind];
    l=ind-1;r=ind+1;
    // Compare elements on left and right of crossover
    // point to find the k closest elements
while(l>=0&&cnt<k &&r<n){
if(x-arr[l] > arr[r]-x ){
cout<<" , " << arr[r++];
}
else cout<<" , " << arr[l--];

cnt ++;
}

// If there are no more elements on right side, then
    // print left elements
    while (cnt < k && l >= 0)
       { cout<<" , " << arr[l++]; cnt++;}
    // If there are no more elements on left side, then
    // print right elements
    while (cnt < k && r < n)
       { cout<<" , " << arr[r++]; cnt++;}

}


int main()
{
int arr[] ={12, 16, 22, 30, 35, 39, 42,
            45, 48, 50, 53, 55, 56};
int n = sizeof(arr)/sizeof(arr[0]);
int x = 35, k = 4;
printKclosest(arr, x, 4, n);
return 0;
}