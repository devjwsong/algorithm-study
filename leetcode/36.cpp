#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
Hash map.
Time: O(81).
Space: O(9).
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;
        
        // Checking each row.
        for (int r=0; r<9; ++r) {
            st.clear();
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') continue;
                if (st.find(board[r][c]) != st.end()) return false;
                st.insert(board[r][c]);
            }
        }

        // Checking each column.
        for (int c=0; c<9; ++c) {
            st.clear();
            for (int r=0; r<9; ++r) {
                if (board[r][c] == '.') continue;
                if (st.find(board[r][c]) != st.end()) return false;
                st.insert(board[r][c]);
            }
        }

        // Checking each section.
        for (int s=0; s<9; ++s) {
            st.clear();
            for (int r=(s/3)*3; r<(s/3+1)*3; ++r) {
                for (int c=(s%3)*3; c<(s%3+1)*3; ++c) {
                    if (board[r][c] == '.') continue;
                    if (st.find(board[r][c]) != st.end()) return false;
                    st.insert(board[r][c]);
                }
            }
        }

        return true;
    }
};
