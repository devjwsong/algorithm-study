#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(1) space + two pointers.
class Solution {
public:
    void swaps(vector<int>& nums, int left, int right) {
        while(left <= right) {
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        swaps(nums, 0, nums.size()-1);
        swaps(nums, 0, k-1);
        swaps(nums, k, nums.size()-1);
    }
};

// Lazy O(n) space.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> temp (k, 0);

        int n = nums.size();
        for (int i=n-k; i<n; ++i) {
            temp[i-n+k] = nums[i];
        }

        for (int i=n-k-1; i>=0; --i) {
            nums[i+k] = nums[i];
        }
        for (int i=0; i<temp.size(); ++i) {
            nums[i] = temp[i];
        }
    }
};

// built_in rotate function.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::rotate(nums.begin(), nums.begin()+nums.size()-k, nums.end());
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

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    sol->rotate(nums, k);

    for (int i=0; i<nums.size(); ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");


    return 0;
}