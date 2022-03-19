#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int nums[20] = {};

    int numTrees(int n) {
        if (nums[n] != 0) return nums[n];

        if (n == 0) {
            nums[0] = 1;
            return 1;
        }
        if (n == 1) {
            nums[1] = 1;
            return 1;
        }

        int answer = 0;
        for (int root=1; root<=n; ++root) {
            int numLeft = numTrees(root-1);
            int numRight = numTrees(n-root);
            answer += (numLeft * numRight);
        }
        nums[n] = answer;

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution *sol = new Solution();
    int answer = sol->numTrees(n);
    printf("%d\n", answer);

    return 0;
}