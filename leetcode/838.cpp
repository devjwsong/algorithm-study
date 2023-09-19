#include <iostream>

using namespace std;


/*
Two pointers. (+ some tricks)
Since multiple dominoes do not add any additional force,
we only consider the 3 cases 
1. A vertical dominoe meets right falling dominoe on its left
and left falling dominoe on its right.
2. A vertical dominoe meets only right falling dominoe on its left.
3. A vertical dominoe meets only left falling dominoe on its right.
Time: O(n).
Space: O(1).
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int idx = 0, right = -1;
        while (idx < n) {
            if (dominoes[idx] == 'L') {
                if (right == -1) {
                    for (int i=idx-1; i>=0 && dominoes[i]=='.'; --i) {
                        dominoes[i] = 'L';
                    }
                } else {
                    int left = idx-1;
                    ++right;
                    while (right < left) {
                        dominoes[right] = 'R';
                        dominoes[left] = 'L';
                        ++right;
                        --left;
                    }
                    right = -1;
                }
            } else if (dominoes[idx] == 'R') {
                if (right != -1) {
                    for (int i=right; i<idx; ++i) {
                        dominoes[i] = 'R';
                    }
                }
                right = idx;
            }
            ++idx;
        }

        if (right != -1) {
            for (int i=right; i<idx; ++i) {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};
