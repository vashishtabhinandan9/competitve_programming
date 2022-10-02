#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void bubblesort(int arr[],int n,int i){
     if(i>=n-1) return;
     bubblesort(arr,n,i+1);
     //bool flag=0;
     for(int j=i;j<n-1;j++){
        if(arr[j]>arr[j+1])
        {
        swap(arr[j],arr[j+1]);
        }
     }
}

int main(){
    int arr[5];
    int size= sizeof(arr)/sizeof(*arr);
    for(int i=0;i<size;i++){
       cin>>arr[i]; 
    }

    bubblesort(arr,size,0);
    for(int i=0;i<size;i++){
       cout<<arr[i]; 
    }

    return 0;
    //getch();
}