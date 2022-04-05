#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


// Sorting
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<>());
        return nums[k-1];
    }
};


// Priority Queue
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,  less<int>> pq;
        for (int i=0; i<nums.size(); ++i) {
            pq.push(nums[i]);
        }

        int count = 1;
        while(count < k) {
            pq.pop();
            ++count;
        }

        return pq.top();
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

    Solution1* sol1 = new Solution1();
    int answer = sol1->findKthLargest(nums, k);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->findKthLargest(nums, k);
    printf("%d\n", answer);

    return 0;
}