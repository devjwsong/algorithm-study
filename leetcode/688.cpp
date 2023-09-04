#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming.
dp[r][c][i]: The probability of surviving at (r,c) after moving i times.
If the dp array counts the number of visits, it will cause the overflow.
And note that we need to add dp[r][c][i] / 8.0 because it need to distribute the probability from each 8 cases.
This would internally include the case where the knight goes out of the board.
Time: O(n*n*k).
Space: O(n*n*k).
*/
class Solution {
public:
    int rowMoves[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int colMoves[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) return  1.0;
        
        vector<vector<vector<double>>> dp (n, vector<vector<double>> (n, vector<double> (k+1, 0.0)));
        dp[row][column][0] = 1.0;
        for (int i=0; i<k; ++i) {
            for (int r=0; r<n; ++r) {
                for (int c=0; c<n; ++c) {
                    for (int d=0; d<8; ++d) {
                        int nextRow = r + rowMoves[d];
                        int nextCol = c + colMoves[d];
                        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n) {
                            dp[nextRow][nextCol][i+1] += (dp[r][c][i]/8.0);
                        }
                    }
                }
            }
        }

        double answer = 0.0;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<n; ++c) {
                answer += dp[r][c][k];
            }
        }
        return answer;
    }
};
