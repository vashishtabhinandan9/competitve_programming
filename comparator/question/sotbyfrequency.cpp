/**
 * Question:
 * Given an array of integers nums, sort the array in increasing order based on the
 *  frequency of the values.
 *  If multiple values have the same frequency,
 *  sort them in decreasing order.
 * Return the sorted array.
 */

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
bool comp(pair<int,int>p,pair<int,int>q){
    if(p.second==q.second){//second is the frequency while first is the value
    //if frequency is same then sort by value
    return p.first>q.first;//how it works
    /**
     * if (first > second) holds true then no swap else swap also we are doin greverse sort herei.e greater element comes first
     * 
    //else if sort by freequency 
    return p.second<q.second;
    }
}
*/
 bool static comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second)
        return a>b;  //a.firsr>b.first 
        else
        return a.second<b.second;
    }

void printarray(vector<int> arr){
for(int i=0;i<arr.size();i++) cout<<arr[i];
}

int main(){

    int n;
        cin>>n;
        int nums[n] ={0};
        for(int i=0;i<n;i++) cin>>nums[i];

     unordered_map<int,int> mp;
         for(int i=0;i<n;i++)
         {
             mp[nums[i]]++;
         }
         vector<pair<int,int>> vec;
         for(auto i:mp)
         {
             vec.push_back(i);//  temp.push_back({i.first,i.second});  
             ///now adding frequency in first and value in second column...
         }
         sort(vec.begin(),vec.end(),comp);

         vector<int> ans;

          for(auto z:vec){
            int a=z.first;
            int b=z.second;
            for(int j=0;j<a;j++){
                ans.push_back(b);
            }
        }

        printarray(ans);
        
         
    return 0;
}
