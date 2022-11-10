/*
Given an m x n matrix, return all elements of the matrix in spiral order.
**/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method

static int x=0,y=0;
void recurse(vector<vector<int>> &mat,int m,int n,int dx,int dy)
{
    vector<int> ans;
     
     vector<vector<bool>> vis(m,vector<bool>(n,0));
     
     if(dx==1 && dy==0){//moves right
     while((x>=0 && x<n ) && vis[x][y]!=0 ){
        //ans.push_back(mat[x][y]);
        cout<<mat[x][y];
        x+=dx;y+=dy;
     }
     recurse(mat,m,n,0,1);
     }


}
 vector<int> iterate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction=1;
        vector<int> v;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) v.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return v;
        
    }


//3rd way dfs

    
    public:    
    vector<int> ans;
    
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited, bool flag){
        //if out of range, return
        if(i == matrix.size() || j == matrix[0].size() || i < 0 || j < 0){
            return;
        }
        //if already visited, return
        if(visited[i][j] != 0){
            return;
        }
        //taking the value to our ansult as well marking visited
        ans.push_back(matrix[i][j]);
        visited[i][j]=1;
        /*
        flag true means we are coming from the bottom, i.e. outer layer done
        give us priority over going to the right ;-;
        */
        if (flag==true){
            dfs(i-1, j, matrix, visited, true);    //up
            dfs(i, j+1, matrix, visited, false);   //right
            dfs(i+1, j, matrix, visited, false);   //down
            dfs(i, j-1, matrix, visited, false);   //left          
        }else{
            dfs(i, j+1, matrix, visited, false);   //right
            dfs(i+1, j, matrix, visited, false);   //down
            dfs(i, j-1, matrix, visited, false);   //left
            dfs(i-1, j, matrix, visited, true);    //up    
        }
    }
   
    /*

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        auto m = matrix[0].size();
        vector<vector<int>> visited {n,vector<int>(m, 0)};
       
        return ans;
    }
*/
int main(){
 int m,n;
 cin>>m>>n;
 vector<vector<int>> a(m,vector<int>(n,0));
 vector<vector<int>> mat{ { 1, 2, 3, 4 }};
 recurse(mat,m,n,1,0);
 iterate(mat);
  dfs(0, 0, mat, visited, false);

    return 0;
}