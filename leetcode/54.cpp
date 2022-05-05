#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool avail(vector<vector<int>>& matrix, int m, int n, int r, int c) {
        return  r >= 0 && r < m && c >= 0 && c < n && matrix[r][c] != -101;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rowDirs[4] = {0, 1, 0, -1};
        int colDirs[4] = {1, 0, -1, 0};

        vector<int> answer;
        int row = 0, col = 0, d = 0;
        while(answer.size() < m * n) {
            answer.push_back(matrix[row][col]);
            matrix[row][col] = -101;
            if (!avail(matrix, m, n, row + rowDirs[d], col + colDirs[d])) {
                d = (d + 1) % 4;
            }
            row += rowDirs[d];
            col += colDirs[d];
        }

        return answer;
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
    vector<int> answer = sol->spiralOrder(matrix);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}