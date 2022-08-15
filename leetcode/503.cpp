#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {-1};

        stack<int> st;
        vector<int> answer (n, -1);
        for (int i=n-2; i>=0; --i) {
            if (nums[i] > nums[n-1]) st.push(nums[i]);
        }

        for (int i=n-1; i>=0; --i) {
            if (st.empty()) {
                answer[i] = -1;
                st.push(nums[i]);
            } else {
                while (!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    answer[i] = -1;
                } else {
                    answer[i] = st.top();
                }
                st.push(nums[i]);
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
        scanf("%d", &val);
        nums.push_back(val);
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->nextGreaterElements(nums);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}