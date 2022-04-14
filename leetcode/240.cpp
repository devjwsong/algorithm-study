#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0;
        while(r < m) {
            if (matrix[r][0] > target) return false;
            if (matrix[r][0] == target) return true;
            if (matrix[r][n-1] < target) {
                ++r;
                continue;
            }

            int left = 0, right = n;
            while(left + 1 < right) {
                int mid = (left + right) / 2;
                if (matrix[r][mid] > target) {
                    right = mid;
                } else {
                    left = mid;
                }

                if (matrix[r][left] == target) return true;
            }
            ++r;
        }

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

    Solution* sol = new Solution();
    bool answer = sol->searchMatrix(matrix, target);
    printf("%d\n", answer);

    return 0;
}