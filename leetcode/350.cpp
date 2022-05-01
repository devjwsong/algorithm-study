#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Default
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> counts;

        for (int i=0; i<nums1.size(); ++i) {
            counts[nums1[i]]++;
        }

        vector<int> answer;
        for (int j=0; j<nums2.size(); ++j) {
            int val = nums2[j];
            if (counts[val] > 0) {
                answer.push_back(val);
                counts[val]--;
            }
        }

        return answer;
    }
};


// Sorted
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Considering this sorting is conducted beforehands.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size(), m = nums2.size();
        vector<int> answer;

        int i = 0, j = 0;
        while(i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                answer.push_back(nums1[i]);
                ++i, ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }

        return answer;
    }
};


/*
<Follow ups?>
2. If the size of nums1 is always smaller then that of nums2, 
  the sorted algorithm is better since it is always guaranteed the the iteration is conducted according to the size of smaller array.
3. If we cannot load all elements in nums2, make a hash map using nums1 first, then loading each element in nums2 from the disk during the iteration.
*/


int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> nums1, nums2;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums1.push_back(val);
    }
    for (int i=0; i<m; ++i) {
        int val;
        scanf(" %d", &val);
        nums2.push_back(val);
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->intersect(nums1, nums2);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");



    return 0;
}