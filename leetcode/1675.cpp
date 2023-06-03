#include <iostream>
#include <queue>
#include <climits>

using namespace std;


/*
Priority Queue + a little bit of idea!
1. Making all odd numbers into even numbers by multiplying 2.
=> If the number is maximum, that's ok because eventually it will become the original by divided by 2.
=> If the number is minimum, it is optimal because minimum value became larger.
2. Making a max heap and reducing the maximum value continuously.
=> If the maxmimum is even, dividing it is an optimal approach.
=> If the maxmimum is odd, then stop it. 
Since we've already made all values to even, we cannot multiply the minimum.
So reducing the maximum is the only way to approach to the optimal solution.
In other words, the minimum value can be increased at most once, when it is an odd number.
Time: O(nlogn)
Space: O(n)
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int curMin = INT_MAX;
        for (int i=0; i<n; ++i) {
            if (nums[i] % 2 == 1) {
                nums[i] *= 2;
            }

            pq.push(nums[i]);
            curMin = min(curMin, nums[i]);
        }

        int answer = pq.top();
        while (pq.top() % 2 == 0) {
            int curMax = pq.top();
            pq.pop();
            pq.push(curMax / 2);

            curMin = min(curMin, curMax/2);
            answer = min(answer, pq.top() - curMin);
        }

        return answer;
    }
};
