#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;


// Ordered Set + Binary Search: O(NlogN).
class Solution1 {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        set<int> st;
        vector<int> mins (n, 1e9+1);
        for (int i=1; i<n; ++i) {
            mins[i] = min(mins[i-1], nums[i-1]);
        }

        st.insert(nums[n-1]);
        for (int i=n-2; i>=1; --i) {
            int left = mins[i];
            if (left < nums[i]) {
                auto iter = st.upper_bound(left);
                if (iter != st.end()) {
                    if (*iter < nums[i]) return true;
                }
            }

            st.insert(nums[i]);
        }

        return false;
    }
};


/* 
Monotonic stack: O(N).
Why does this algorithm run in O(N)?
In the beginning, only pushing occurs until the top value becomes smaller or same with the left.
Then, when smaller value comes up, popping iteration is executed for one time.
After that, if the left becomes smaller, the top number is always larger than the left, 
so there is no need to additional popping.
*/
class Solution2 {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        vector<int> mins (n, 1e9+1);
        for (int i=1; i<n; ++i) {
            mins[i] = min(mins[i-1], nums[i-1]);
        }

        st.push(nums[n-1]);
        for (int i=n-2; i>=1; --i) {
            int left = mins[i];
            if (left < nums[i]) {
                while (!st.empty() && st.top() <= left) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top() > left && st.top() < nums[i]) return true;
                }
            }
            st.push(nums[i]);
        }

        return false;
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

    Solution1* sol1 = new Solution1();
    bool answer = sol1->find132pattern(nums);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->find132pattern(nums);
    printf("%d\n", answer);

}