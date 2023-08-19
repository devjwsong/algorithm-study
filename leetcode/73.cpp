#include <iostream>
#include <vector>

using namespace std;


/*
Simple trick with matrix!
We use the first row and column as the marks.
First, if there is 0 in the first row or column, we set the boolean marks
since they will eventually become 0s.
Then, we now iterate the row 1~m-1 and column 1~n-1.
If there is 0, then we set matrix[r][0] and matrix[0][c] corresponding to the current position into 0.
Now those row and column should be set to 0 later.
It doesn't matter whether matrix[r][0] or matrix[0][c] is already 0 since that means that row or column should be 0 eventually.
After updating the matrix, then we finally update the first row and column according to the boolean flags.
*/
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
