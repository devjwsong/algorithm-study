#include <iostream>
#include <vector>

using namespace std;


/*
Monotonic stack & Merge sort application.
Time: O(k*(m+n)^2)
Space: O(m+n)
The idea is extracting i numbers from nums1 and (k-i) numbers from nums2, merge them to become a maximum number, and repeat this process to find the best result.
Here, each vector to merge should be a composition of lexicographically maximum and monotonic stack is used for this.
And what we should think about is the case that two values are the same when merging.
In conventional merge sort, this does not matter but here we should combine two vectors lexicographically, 
so if we put one carelessly then later certain larger number cannot come forward.
To prevent this, we comsume the one which a higher number appear first with an additional loop.
*/
class Solution {
public:
    vector<int> findMax(vector<int>& nums, int k) {
        if (k > nums.size()) return {};
        int n = nums.size();
        vector<int> res;
        
        for (int i=0; i<n; ++i) {
            int m = res.size();
            while (m > 0 && res.back() < nums[i]) {
                if (n-i+m-1 >= k) {
                    res.pop_back();
                    --m;
                } else {
                    break;
                }
            }
            if (m < k) {
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
    
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        int i=0, j=0;
        int m = v1.size(), n = v2.size();
        vector<int> res;
        
        while (i < m && j < n) {
            if (v1[i] == v2[j]) {
                int ii = i, jj = j;
                while (ii < m && jj <n && v1[ii] == v2[jj]) ++ii, ++jj;
                if (ii == m) {
                    res.push_back(v2[j]);
                    ++j;
                } else if (jj == n) {
                    res.push_back(v1[i]);
                    ++i;
                } else if (v1[ii] > v2[jj]) {
                    res.push_back(v1[i]);
                    ++i;
                } else if (v2[jj] > v1[ii]) {
                    res.push_back(v2[j]);
                    ++j;
                }
            } else if (v1[i] > v2[j]) {
                res.push_back(v1[i]);
                ++i;
            } else {
                res.push_back(v2[j]);
                ++j;
            }
        }
        
        while (i < m) {
            res.push_back(v1[i]);
            ++i;
        }
        while (j < n) {
            res.push_back(v2[j]);
            ++j;
        }
        
        return res;
    }
    
    vector<int> compare(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > v2.size()) return v1;
        if (v1.size() < v2.size()) return v2;
        for (int i=0; i<v1.size(); ++i) {
            if (v1[i] > v2[i]) return v1;
            if (v1[i] < v2[i]) return v2;
        }
        
        return v1;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> answer;
        
        for (int i=0; i<=k; ++i) {
            vector<int> res1 = findMax(nums1, i);
            vector<int> res2 = findMax(nums2, k-i);
            vector<int> temp = merge(res1, res2);
            answer = compare(answer, temp);
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
        scanf(" %d", &val);
        nums1.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums2.push_back(val);
    }

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    vector<int> answer = sol->maxNumber(nums1, nums2, k);
    for (int i=0; answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}