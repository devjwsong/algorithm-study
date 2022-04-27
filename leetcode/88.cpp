#include <iostream>
#include <vector>

using namespace std;

// O(m+n).
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int j=0; j<n; ++j) {
                nums1[j] = nums2[j];
            }
            return;
        }

        for (int i=m-1; i>=0; --i) {
            nums1[i+n] = nums1[i];
            nums1[i] = 0;
        }

        int i = n, j = 0;
        int cur = 0;
        while(i < m+n && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[cur] = nums1[i];
                ++i;
            } else {
                nums1[cur] = nums2[j];
                ++j;
            }

            ++cur;
        }

        while(i < m+n) {
            nums1[cur] = nums1[i];
            ++cur;
            ++i;
        }
        while(j < n) {
            nums1[cur] = nums2[j];
            ++cur;
            ++j;
        }
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<int> nums1, nums2;
    for (int i=0; i<m; ++i) {
        int val;
        scanf(" %d", &val);
        nums1.push_back(val);
    }

    for (int i=0; i<n; ++i) {
        nums1.push_back(0);
        int val;
        scanf(" %d", &val);
        nums2.push_back(val);
    }

    Solution* sol = new Solution();
    sol->merge(nums1, m, nums2, n);

    for (int i=0; i<m+n; ++i) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}