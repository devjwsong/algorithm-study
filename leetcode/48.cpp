#include <iostream>
#include <vector>

using namespace std;


/*
We start from the outer layer to inner layers.
The blocks in the layer l should move by (n-1-l);
And each group of 4 blocks have a pattern for moving.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int l=0; l<n/2; ++l) {
            int k = n - 1 - l;
            for (int i=l; i<k; ++i) {
                int temp = matrix[l][i];
                matrix[l][i] = matrix[n-1-i][l];
                matrix[n-1-i][l] = matrix[n-1-l][n-1-i];
                matrix[n-1-l][n-1-i] = matrix[i][n-1-l];
                matrix[i][n-1-l] = temp;
            }
        }
    }
};
