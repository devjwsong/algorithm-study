#include <iostream>
#include <vector>

using namespace std;


// https://engkimbs.tistory.com/623
// Binary search + fancy mathematics!
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;
        while (left <= right) {
            int midI = (left + right) / 2;
            int midJ = (m + n + 1) / 2 - midI;

            int maxLeft1 = INT32_MIN;
            int maxLeft2 = INT32_MIN;
            int minRight1 = INT32_MAX;
            int minRight2 = INT32_MAX;

            if (midI > 0) maxLeft1 = nums1[midI-1];
            if (midJ > 0) maxLeft2 = nums2[midJ-1];
            if (midI < m) minRight1 = nums1[midI];
            if (midJ < n) minRight2 = nums2[midJ];

            if ((maxLeft2 <= minRight1) && (maxLeft1 <= minRight2)) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                return (double) max(maxLeft1, maxLeft2);
            } else if (maxLeft2 > minRight1) {
                left = midI + 1;
            } else {
                right = midI - 1;
            }
        }

        return 0.0;
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
        int val;
        scanf(" %d", &val);
        nums2.push_back(val);
    }

    Solution* sol = new Solution();
    double answer = sol->findMedianSortedArrays(nums1, nums2);
    printf("%lf\n", answer);

    return 0;
}