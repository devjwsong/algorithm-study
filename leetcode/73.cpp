#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool isRowZero = false, isColZero = false;

        for (int c=0; c<n; ++c) { 
            if (matrix[0][c] == 0) {
                isRowZero = true;  // The first row is all zero anyway.
                break;
            }
        }

        for (int r=0; r<m; ++r) {
            if (matrix[r][0] == 0) {
                isColZero = true;  // The first column is all zero anyway.
                break;
            }
        }

        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;  // Using the first row and column as marks.
                    matrix[r][0] = 0;
                }
            }
        }

        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                if (matrix[r][c] != 0 && (matrix[0][c] == 0 || matrix[r][0] == 0)) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (isRowZero) {
            for (int c=0; c<n; ++c) {
                matrix[0][c] = 0;
            }
        }

        if (isColZero) {
            for (int r=0; r<m; ++r) {
                matrix[r][0] = 0;
            }
        }
    }
};


int main() {
    
    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<int>> matrix;
    for (int r=0; r<m; ++r) {
        vector<int> row;
        for (int c=0; c<n; ++c) {
            int val;
            scanf(" %d", &val);
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    Solution* sol = new Solution();
    sol->setZeroes(matrix);

    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}