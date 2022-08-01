#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        while (idx < nums.size()) {
            if (nums[idx] == val) {
                int dist = 0;
                for (int i=idx+1; i<nums.size(); ++i) {
                    if (nums[i] != val) {
                        dist = i - idx;
                        break;
                    }
                }

                for (int i=idx; i<nums.size(); ++i) {
                    if (i+dist < nums.size()) {
                        nums[i] = nums[i+dist];
                        nums[i+dist] = -1;
                    } else {
                        nums[i] = -1;
                    }
                }
            }

            idx += 1;
        }

        int answer = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != -1) {
                answer += 1;
            }
        }

        return answer;
    }
};


int main() {
    
    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int e;
        scanf(" %d", &e);
        nums.push_back(e);
    }

    int val;
    scanf("%d", &val);

    Solution *sol = new Solution();
    int answer = sol->removeElement(nums, val);

    printf("%d\n", answer);

    return 0;
}