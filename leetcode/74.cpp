#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = -1;
        for (int r=0; r<m; ++r) {
            if (matrix[r][0] <= target && target <= matrix[r][n-1]) {
                row = r;
                break;
            }
        }

        if (row == -1) return false;

        // Binary search.
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (matrix[row][right] == target || matrix[row][left] == target) return true;
        return false;
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

    int target;
    scanf("%d", &target);

    Solution *sol = new Solution();
    bool answer = sol->searchMatrix(matrix, target);
    printf("%d\n", answer);

    return 0;
}