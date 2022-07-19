#include <iostream>
#include <vector>

using namespace std;


/*
Very simple and intuitive solution!
The rightMins has the minimum value among [i, n-1].
And leftMax is the maximum value among [0, i].
Therefore, if leftMax <= rightMins[i+1], that means max[0,i] <= min[i+1,n-1].
So i is the last point of the chunk.
And when i=n-1, rightMins[i+1] is infinity, so this is always be the end of the chunk.
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        vector<int> rightMins (n+1, INT32_MAX);
        for (int i=n-1; i>=0; --i) {
            rightMins[i] = min(rightMins[i+1], arr[i]);
        }

        int answer = 0;
        int leftMax = INT32_MIN;
        for (int i=0; i<n; ++i) {
            leftMax = max(leftMax, arr[i]);
            if (leftMax <= rightMins[i+1]) {
                ++answer;
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> arr;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        arr.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->maxChunksToSorted(arr);
    printf("%d\n", answer);

    return 0;
}