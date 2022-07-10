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

    bool isValid(int r, int c) {
        int n = cur.size();
        for (int rr=0; rr<n; ++rr) {
            if (cur[rr][c] == 'Q') return false;
        }

        for (int rr=r, cc=c; rr >= 0 && cc >= 0; --rr, --cc) {
            if (cur[rr][cc] == 'Q') return false;
        }

        for (int rr=r, cc=c; rr >= 0 && cc < n; --rr, ++cc) {
            if (cur[rr][cc] == 'Q') return false;
        }

        return true;
    }

    void search(int n, int numQueens) {
        if (numQueens == n) {
            answer.push_back(cur);
            return;
        }

        int r = numQueens;
        for (int c=0; c<n; ++c) {
            if (isValid(r, c)) {
                cur[r][c] = 'Q';
                search(n, numQueens+1);
                cur[r][c] = '.';
            }
        }
    }

    void initCur(int n) {
        string s;
        for (int i=0; i<n; ++i) {
            s += '.';
        }
        cur.assign(n, s);
    }

    vector<vector<string>> solveNQueens(int n) {
        initCur(n);
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