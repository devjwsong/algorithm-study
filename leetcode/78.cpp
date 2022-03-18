#include <iostream>
#include <vector>

using namespace std;

// Recursion
class Solution1 {
public:
    vector<vector<int>> answer;

    void search(vector<int>& nums, vector<int> cur, int curIdx) {
        if (curIdx == (nums.size()-1)) {
            answer.push_back(cur);
        } else {
            search(nums, cur, curIdx+1);
            vector<int> next = cur;
            next.push_back(nums[curIdx+1]);
            search(nums, next, curIdx+1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        answer.push_back(vector<int> {});
        for (int i=0; i<nums.size(); ++i) {
            vector<int> start {nums[i]};
            search(nums, start, i);
        }

        return answer;
    }
};


// Bit manipulation
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;

        for (int i=0; i<(1 << n); ++i) {
            vector<int> subset;
            for (int b=0; b<n; ++b) {
                if (i & (1 << b)) {
                    subset.push_back(nums[b]);
                }
            }
            answer.push_back(subset);
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

    Solution1 *sol1 = new Solution1();
    vector<vector<int>> answer = sol1->subsets(nums);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    Solution2 *sol2 = new Solution2();
    answer = sol2->subsets(nums);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}