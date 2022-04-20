#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// O(nlogk)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            counts[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto iter: counts) {
            pq.push(pair<int, int> (iter.second, iter.first));
        }

        vector<int> answer;
        while(!pq.empty() && answer.size() < k) {
            answer.push_back(pq.top().second);
            pq.pop();
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

    Solution* sol = new Solution();
    vector<int> answer = sol->topKFrequent(nums, k);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}