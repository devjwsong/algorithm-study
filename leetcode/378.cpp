#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Time Complexity: O(n(logn)^3), Space Complexity: O(1)
class Solution {
public:
    int findSmaller(vector<vector<int>>& matrix, int target) {
        int res = 0;
        for (int r=0; r<matrix.size(); ++r) {
            res += lower_bound(matrix[r].begin(), matrix[r].end(), target) - matrix[r].begin();
        }
        return res;
    }

    int findIncluded(vector<vector<int>>& matrix, int target) {
        int res = 0;
        for (int r=0; r<matrix.size(); ++r) {
            res += upper_bound(matrix[r].begin(), matrix[r].end(), target) - matrix[r].begin();
        }
        return res;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while (low + 1 < high) {  // O(logn^2) = O(logn)
            int mid = (low + high) / 2;
            int numSmaller = findSmaller(matrix, mid);  // O(nlogn)
            int numIncluded = findIncluded(matrix, mid);  // O(nlogn)

            if (k > numSmaller && k <= numIncluded) return mid;
            if (k <= numSmaller) {
                high = mid;
            } else if (k > numIncluded) {
                low = mid;
            }
        }

        if (k > findSmaller(matrix, low) && k <= findIncluded(matrix, low)) return low;
        return high;
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

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    int answer = sol->kthSmallest(matrix, k);
    printf("%d\n", answer);

    return 0;
}