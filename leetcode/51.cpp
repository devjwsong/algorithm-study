#include <iostream>
#include <vector>

using namespace std;


/*
BackTracking but delicate coding might be required!
We don't need to consider the row separately, since each row can have only one queen!
Therefore, dfs is conducted row by row.
This can drastically simplify the details!
*/
class Solution {
public:
    vector<vector<string>> answer;
    vector<string> cur;

    bool isValid(int n, int r, int c) {
        for (int rr=0; rr<r; ++rr) {
            if (cur[rr][c] == 'Q') return false;
        }

        int rr = r, cc = c;
        while (rr >= 0 && cc >= 0) {
            if (cur[rr][cc] == 'Q') return false;
            --rr;
            --cc;
        }

        rr = r, cc = c;
        while (rr >= 0 && cc < n) {
            if (cur[rr][cc] == 'Q') return false;
            --rr;
            ++cc;
        }

        return true;
    }

    void search(int n, int numQueens) {
        if (numQueens == n) {
            answer.push_back(cur);
            return;
        }

        for (int c=0; c<n; ++c) {
            if (isValid(n, numQueens, c)) {
                cur[numQueens][c] = 'Q';
                search(n, numQueens + 1);
                cur[numQueens][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string row;
        for (int i=0; i<n; ++i) {
            row += '.';
        }
        cur.assign(n, row);
        search(n, 0);

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    vector<vector<string>> answer = sol->solveNQueens(n);
    for (int i=0; i<answer.size(); ++i) {
        cout<<"##########\n";
        for (int r=0; r<answer[i].size(); ++r) {
            cout<<answer[i][r]<<"\n";
        }
    }

    return 0;
}