#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> dp;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};
    
    bool isValid(int m, int n, int r, int c) {
        return r>=0 && r<m && c>=0 && c<n;
    }
    
    int search(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != -1) return dp[r][c];
        
        bool deadEnd = true;
        int res = 0;
        for (int d=0; d<4; ++d) {
            int nextR = r + rowDirs[d];
            int nextC = c + colDirs[d];
            if (isValid(matrix.size(), matrix[0].size(), nextR, nextC)) {
                if (matrix[nextR][nextC] > matrix[r][c]) {
                    deadEnd = false;
                    res = max(res, search(matrix, nextR, nextC));
                }
            }
        }
        
        if (deadEnd) {
            return dp[r][c] = 1;
        }
        return dp[r][c] = 1 + res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int> (n, -1));
        
        int answer = 0;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                answer = max(answer, search(matrix, r, c));
            }
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
    int answer = sol->longestIncreasingPath(matrix);
    printf("%d\n", answer);

    return 0;
}