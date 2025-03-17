#include<iostream>
#include<vector>
using namespace std;

//73. Set Matrix Zeros
//A simple algorithm with O(m+n) space: Scan the columns and the rows, store all the rows and columns that has 0.
//With constant space: Use the first column and row as the note. But we need to deal with the rest part first.
//Finally check if the first column/row should be 0.

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            bool flag1 = false;
            bool flag2 = false;
            for(int i = 0;i < m;i++) {
                if(matrix[i][0] == 0) {
                    flag1 = true;
                    break;
                }
            }
            for(int j = 0;j < n;j++) {
                if(matrix[0][j] == 0) {
                    flag2 = true;
                    break;
                }
            }
            for(int i = 1;i < m;i++){
                for(int j = 1;j < n;j++){
                    if(matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int j = 1;j < n; j++){
                if(matrix[0][j] == 0){
                    for(int i = 0;i < m;i++) matrix[i][j] = 0;
                }
            }
            for(int i = 1;i < m;i++){
                if(matrix[i][0] == 0){
                    for(int j = 0;j < n;j++) matrix[i][j] = 0;
                }
            }
            if(matrix[0][0] == 0){
                for(int i = 0;i < m;i++) matrix[i][0] = 0;
                for(int j = 0;j < n;j++) matrix[0][j] = 0;
            }
            if(flag1) {
                for(int i = 0;i < m;i++) matrix[i][0] = 0;
            }
            if(flag2) {
                for(int j = 0;j < n;j++) matrix[0][j] = 0;
            }
        }
};
