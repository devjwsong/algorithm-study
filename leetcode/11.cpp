#include <iostream>
#include <vector>

using namespace std;


/*
First candidate is the widest one, which is 0 ~ n-1.
Then we iteratively narrow down the width, and in order to make a larger container, the height must increase.
And the height is determined by the shorter wall.
So, we move the shorter one and check the change of the amount.
If the height are the same, then it doesn't matter if we move left or right, since it is bounded one of them anyway.
So anyway one of them should be moved, and if the moved one becomes higher, than the other wall will also be changed at the next step.
In fact, when I changed the code to make both left and right moved when the heights are the same, it also passed.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int answer = 0;

        while (left < right) {
            answer = max(answer, (right-left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return answer;
    }
};

int main () {

    int n;
    scanf("%d", &n);

    vector<int> height;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        height.push_back(val);
    }

    Solution *sol = new Solution();
    int answer = sol->maxArea(height);
    printf("%d\n", answer);

    return 0;
}