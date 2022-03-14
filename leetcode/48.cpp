#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; ++i) {
            int numHalf = 0;
            if (n % 2 == 0) {
                numHalf = n/2;
            } else {
                numHalf = n/2 + 1;
            }

            for (int j=0; j<numHalf; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> matrix;
    for (int r=0; r<n; ++r) {
        vector<int> row;
        for (int c=0; c<n; ++c) {
            int val;
            scanf(" %d", &val);
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    Solution *sol = new Solution();
    sol->rotate(matrix);

    for (int r=0; r<n; ++r) {
        for (int c=0; c<n; ++c) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}