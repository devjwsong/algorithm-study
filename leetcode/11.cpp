#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxValue = (min(height[left], height[right])) * (right-left);
        bool leftMove = true;
        if (height[left] > height[right]) {
            leftMove = false;
        }

        while(right > left) {
            if (leftMove) {
                ++left;
                if (height[left] > height[right]) {
                    leftMove = false;
                }
            } else {
                --right;
                if (height[right] > height[left]) {
                    leftMove = true;
                }
            }
            maxValue = max(maxValue, (min(height[left], height[right])) * (right-left));
        }

        return maxValue;
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