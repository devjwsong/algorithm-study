#include <iostream>
#include <vector>

using namespace std;


// O(nlogn): Binary search.
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int answer = n+1;

        vector<int> pSums (n+1, 0);
        for (int i=1; i<=n; ++i) {
            pSums[i] = pSums[i-1] + nums[i-1];
        }

        for (int i=0; i<n+1; ++i) {
            int newTarget = target + pSums[i];
            int left = i+1, right = n;

            while(left + 1 < right) {
                int mid = (left + right) / 2;
                if (pSums[mid] >= newTarget) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            if (pSums[right] >= newTarget) {
                if (pSums[left] >= newTarget) {
                    answer = min(answer, left-i);
                } else {
                    answer = min(answer, right-i);
                }
            }
        }

        if (answer == n+1) return 0;
        return answer;
    }
};

/*
O(n): Two pointers.
The idea is simple, just increasing & decreasing the range and check the sum.
This works because if right reaches somewhere and that point is the first point where the sum >= target with the fixed left,
we don't need to check other ranges inside of it.
There is no way that the sums of any inner range become larger than or the same as the target.
How can they be, considering that this moment barely made the sum >= target and inner range is always even smaller with the larger left point?
So, current range is the range with the shortest length in the condition of current left cursor.
So all we have to do is moving on to the next left cursor and search for other possibilities with shorter length.
*/
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int answer = n+1;

        vector<int> pSums (n+1, 0);
        for (int i=1; i<=n; ++i) {
            pSums[i] = pSums[i-1] + nums[i-1];
        }

        int left = 0, right = 1;
        while(left < right && right <= n) {
            int cur = pSums[right] - pSums[left];
            if (cur >= target) {
                answer = min(answer, right-left);
                ++left;
            } else {
                ++right;
            }
        }

        if (answer == n+1) return 0;
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    int target;
    scanf("%d", &target);

    Solution1* sol1 = new Solution1();
    int answer = sol1->minSubArrayLen(target, nums);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->minSubArrayLen(target, nums);
    printf("%d\n", answer);

    return 0;
}