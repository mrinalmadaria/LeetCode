#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0]. size();

        vector<int> row_minimums(rows, INT_MAX);
        vector<int> col_maximums(cols, 0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int elem = matrix[i][j];
                row_minimums[i] = min(row_minimums[i], elem);
                col_maximums[j] = max(col_maximums[j], elem);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int elem = matrix[i][j];
                if(elem == row_minimums[i] && elem == col_maximums[j]){
                    return {elem};
                }
            }
        }

        return {};
    }
};