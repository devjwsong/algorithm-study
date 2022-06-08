#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
Bit masking can be used to make a power set of given set.
For example, if the number of elements is 4, we can utilize four bits number to mark target elements to include.
In more detail, 0000 means that no element is included.
0001 means only first element is included.
1010 means first and third elements are include in the current subset.
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        set<vector<int>> st;

        int size = 1 << n;
        for (int s=0; s<size; ++s) {
            vector<int> subset;
            for (int i=0; i<n; ++i) {
                if (1 & (s >> i)) {
                    subset.push_back(nums[i]);
                }
            }
            sort(subset.begin(), subset.end());
            st.insert(subset);
        }
        
        for (auto iter=st.begin(); iter != st.end(); ++iter) {
            answer.push_back(*iter);
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

    Solution* sol = new Solution();
    vector<vector<int>> answer = sol->subsetsWithDup(nums);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}