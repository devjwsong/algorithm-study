#include <iostream>
#include <vector>

using namespace std;


/*
Two methods are actually the same, but the the second solution is more efficient.
The idea is to keep the left max height and right max height.
No matter how tall other walls which are not left/right max,
we just have to calculate the amount of water according to current wall.
In the second solution, we can implement two pointers.
No matter which pointer moves, there is no loss, easily inferred from the description.
All we have to do is to keep the minimum height of left/right max wall to calcuate the water amount.
*/


// DP with two arrays.
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxs (n, 0), rightMaxs (n, 0);
        leftMaxs[0] = height[0];
        rightMaxs[n-1] = height[n-1];
        
        for (int i=1; i<n; ++i) {
            leftMaxs[i] = max(leftMaxs[i-1], height[i]);
        }
        
        for (int i=n-2; i>=0; --i) {
            rightMaxs[i] = max(rightMaxs[i+1], height[i]);
        }
        
        int answer = 0;
        for (int i=0; i<n; ++i) {
            answer += (min(leftMaxs[i], rightMaxs[i]) - height[i]);
        }
        
        return answer;
    }
};


// Min/Max two pointers without additional arrays.
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        
        int left = 0, right = n-1;
        int answer = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                answer += (leftMax - height[left]);
                ++left;
            } else {
                rightMax = max(rightMax, height[right]);
                answer += (rightMax - height[right]);
                --right;
            }
        }
        
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> height;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        height.push_back(val);
    }

    Solution1* sol1 = new Solution1();
    int answer = sol1->trap(height);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->trap(height);
    printf("%d\n", answer);

    return 0;
}