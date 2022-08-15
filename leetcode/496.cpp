#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


// Simple hash map: O(m * n)
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> idxs;
        for (int i=0; i<n; ++i) {
            idxs[nums2[i]] = i;
        }

        vector<int> answer;
        for (int i=0; i<m; ++i) {
            int idx = idxs[nums1[i]];
            int val = -1;
            for (int j=idx; j<n; ++j) {
                if (nums2[j] > nums1[i]) {
                    val = nums2[j];
                    break;
                }
            }
            answer.push_back(val);
        }

        return answer;
    }
};


// Stack + Hash map: O(m + n)
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i=n-1; i>=0; --i) {
            if (st.empty()) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            } else {
                while (!st.empty() && st.top() < nums2[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    mp[nums2[i]] = -1;
                } else {
                    mp[nums2[i]] = st.top();
                }

                st.push(nums2[i]);
            } 
        }

        vector<int> answer;
        int m = nums1.size();
        for (int i=0; i<m; ++i) {
            answer.push_back(mp[nums1[i]]);
        }

        return answer;
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<int> nums1, nums2;
    for (int i=0; i<m; ++i) {
        int val;
        scanf("%d", &val);
        nums1.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf("%d", &val);
        nums2.push_back(val);
    }

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->nextGreaterElement(nums1, nums2);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2* sol2 = new Solution2();
    answer = sol2->nextGreaterElement(nums1, nums2);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}
