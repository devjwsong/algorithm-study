#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Two pointers: O(nlogn)
class Solution1 {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 0;
        sort(nums.begin(), nums.end());

        int answer = 0;
        int left = 0, right = 1;
        while (left < n && right < n) {
            if (left > 0 && nums[left-1] == nums[left]) {
                ++left;
                if (left == right) ++right;
                continue;
            }

            if (left == right) {
                ++right;
            } else {
                if (nums[left] + k == nums[right]) {
                    ++answer;
                    ++left;
                } else if (nums[left] + k > nums[right]) {
                    ++right;
                } else {
                    ++left;
                }
            }
        }

        return answer;
    }
};


// Hash map: O(n).
class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        unordered_map<int, bool> checked;
        for (int i=0; i<n; ++i) {
            ++counts[nums[i]];
        }

        int answer = 0;
        for (int i=0; i<n; ++i) {
            int cur = nums[i];
            if (checked.find(cur) != checked.end()) continue;
            
            if (k == 0) {
                int count = counts[cur];
                if (count > 1) ++answer;
            } else {
                if (counts.find(cur+k) != counts.end()) {
                    ++answer;
                }
            }

            checked[cur] = true;
        }

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

    int k;
    scanf("%d", &k);

    Solution1* sol1 = new Solution1();
    int answer = sol1->findPairs(nums, k);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->findPairs(nums, k);
    printf("%d\n", answer);

    return 0;
}