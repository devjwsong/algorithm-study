#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int start=0; start<n/2; ++start) {
            int end = n - 1 - start;
            for (int c=start; c<end; ++c) {
                int temp = matrix[start][c];
                matrix[start][c] = matrix[n-1-c][start];
                matrix[n-1-c][start] = matrix[n-1-start][n-1-c];
                matrix[n-1-start][n-1-c] = matrix[c][n-1-start];
                matrix[c][n-1-start] = temp;
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
    
    printf("##########\n");
    for (int r=0; r<n; ++r) {
        for (int c=0; c<n; ++c) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}