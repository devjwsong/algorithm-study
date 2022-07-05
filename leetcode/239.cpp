#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;


// Multiset: O(NlogN)
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms;
        
        vector<int> answer;
        for (int i=0; i<k; ++i) {
            ms.insert(nums[i]);
        }
        answer.push_back(*ms.rbegin());
        
        for (int i=1; i<=n-k; ++i) {
            int prev = nums[i-1], next = nums[i+k-1];
            multiset<int>::iterator iter = ms.find(prev);
            ms.erase(iter);
            ms.insert(next);
            answer.push_back(*ms.rbegin());
        }
        
        return answer;
    }
};


// Priority Queue(Deque): O(N)
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> answer;
        deque<int> dq;
        
        for (int i=0; i<n; ++i) {
            while (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            
            if (i >= k-1) answer.push_back(nums[dq.front()]);
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

    int k;
    scanf("%d", &k);

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->maxSlidingWindow(nums, k);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2* sol2 = new Solution2();
    answer = sol2->maxSlidingWindow(nums, k);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}