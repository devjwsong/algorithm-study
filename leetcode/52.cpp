#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int answer = 0;
    vector<string> board;
    
    bool isValid(int r, int c) {
        int n = board.size();
        for (int rr=r; rr>=0; --rr) {
            if (board[rr][c] == 'Q') return false;
        }
        
        int rr=r, cc=c;
        while (rr >= 0 && cc >= 0) {
            if (board[rr][cc] == 'Q') return false;
            --rr;
            --cc;
        }
        
        rr=r, cc=c;
        while (rr >= 0 && cc < n) {
            if (board[rr][cc] == 'Q') return false;
            --rr;
            ++cc;
        }
        
        return true;
    }
        
    void solve(int n, int r) {
        if (r == n) {
            ++answer;
            return;
        }
        
        for (int c=0; c<n; ++c) {
            if (isValid(r, c)) {
                board[r][c] = 'Q';
                solve(n, r+1);
                board[r][c] = '.';
            }
        }
    }
    
    void initBoard(int n) {
        string init;
        for (int i=0; i<n; ++i) {
            init += '.';
        }
        board.assign(n, init);
    }
    
    int totalNQueens(int n) {        
        initBoard(n);
        solve(n, 0);
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    int answer = sol->totalNQueens(n);
    printf("%d\n", answer);

    return 0;
}