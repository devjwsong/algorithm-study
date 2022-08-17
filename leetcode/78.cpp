#include <iostream>
#include <vector>

using namespace std;

// Recursion
class Solution1 {
public:
    vector<vector<int>> answer;
    vector<int> cur;

    void search(vector<int>& nums, int idx) {
        int n = nums.size();
        if (idx == n) {
            answer.push_back(cur);
            return;
        }
        
        search(nums, idx+1);
        cur.push_back(nums[idx]);
        search(nums, idx+1);
        cur.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        search(nums, 0);

        return answer;
    }
};


// Bit manipulation
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;

        for (int b=0; b<(1 << n); ++b) {
            vector<int> subset;
            for (int i=0; i<n; ++i) {
                if (b & (1 << i)) {
                    subset.push_back(nums[i]);
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