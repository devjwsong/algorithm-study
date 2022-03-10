#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = -1;
        for (int i=nums.size()-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) {
                start = i;
                break;
            }
        }

        if (start != -1) {
            for (int i=nums.size()-1; i>=0; --i) {
                if (nums[i] > nums[start]) {
                    swap(nums[i], nums[start]);
                    break;
                }
            }
        }
        
        reverse(nums.begin() + start + 1, nums.end());
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());
        vector<int> init = nums;
        while(1) {
            answer.push_back(nums);
            nextPermutation(nums);
            
            bool isInit = true;
            for (int i=0; i<nums.size(); ++i) {
                if (nums[i] != init[i]) {
                    isInit = false;
                    break;
                }
            }

            if (isInit) {
                break;
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
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution *sol = new Solution();
    vector<vector<int>> answer = sol->permute(nums);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}