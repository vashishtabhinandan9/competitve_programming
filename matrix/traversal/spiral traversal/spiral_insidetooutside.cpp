/**
 * You start at the cell (rStart, cStart) of an rows x cols grid facing east. 
 *The northwest corner is at the first row and column in the grid, and the southeast corner is at 
 the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. 
Whenever you move outside the grid's boundary, we continue our walk outside the grid
 (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the
  grid.

Return an array of coordinates representing the positions of the grid in the order you visited 
them
.

/****soluition:***
https://leetcode.com/problems/spiral-matrix-iii/discuss/2166570/C%2B%2B-oror-Easy-Explanation-and-Solution

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method
vector<vector<int>> spiralMatrix(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart}); //Pushing the starting point in answer
        int topRow = rStart-1; //Row above starting point
        int bottomRow = rStart+1; //Row below starting point
        int leftCol = cStart-1; //Col left to starting point
        int rightCol = cStart+1; //Col right to starting point
        
        while(topRow != -1 || bottomRow != rows || leftCol != -1 || rightCol != cols){ //Untill all rows and columns are exhausted
            
            if(rightCol != cols){ //Checking if this col is exhausted
                for(int i = topRow+1; i < bottomRow;i++) ans.push_back({i, rightCol}); //Running loop from one bottom of top row till bottom row in right col
                rightCol++; //Incrementing the col forward
            }
            //Similar things are done below with different cols and rows
            if(bottomRow != rows){
                for(int j = rightCol-1; j > leftCol; j--) ans.push_back({bottomRow, j});
                bottomRow++;
            }
            
            if(leftCol != -1){
                for(int i = bottomRow-1; i > topRow; i--) ans.push_back({i, leftCol});
                leftCol--;
            }
            
            if(topRow != -1){
                for(int j = leftCol+1; j < rightCol; j++) ans.push_back({topRow, j});
                topRow--;
            }  
        }
        return ans;
    }
//2nd method
 vector<vector<int>> spiralMatrixII(int rows, int cols, int rStart, int cStart) {
        int result=rows*cols;
        int limit=1;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0;
        vector<vector<int>>ans={{rStart,cStart}};
        int no=1;
        while(ans.size()!=result)
        {
            for(int i=0;i<limit;i++)
            {
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                {
                    ans.push_back({rStart,cStart});
                }
            }
                
                
                d=(d+1)%4;
            if(no==2)
            {
                limit++;no=1;
            }
            else no++;
                
                
                
        }
        return ans;
        
    }


int main(){
#ifndef ONLINE_JUDGE

	// For getting input from input.txt file
	freopen("input.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);

#endif
    int rows,cols,rstart,cstart;
    cin>>rows>>cols>>rstart>>cstart;
   spiralMatrix(rows,cols,rstart,cstart);
   return 0;
}