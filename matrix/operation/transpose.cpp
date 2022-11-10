/* 
1st method inplace trasnpose
this is only possibel if matrix is n * n
*/

   int[][] Inplace(int[][] matrix) {
        int n = matrix.length;
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        return matrix;
    }
/**
 * 
 * 2nd method outplace matrix
 * thsi is possible with all kind of matrix 
 * n*n  and m* n
 * 
*/

 public int[][] Outplace(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[][] transposedMatrix = new int[m][n];
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                transposedMatrix[i][j] = matrix[j][i];
        
        return transposedMatrix;
    }

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1st method

int main(){

    return 0;
}
