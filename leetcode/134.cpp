#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
The point is to find a first index where starting from it, the total sum of differences between gas and cost is larger than or equal to 0.
This is a greedy approach, since if the current sum is negative the current index cannot be starting point.
And the answer is unique if it exists, the only way to find it is iterating and finding the index where the sum of the values behind it is positive or 0.
Because it is obvious that stating from this index makes the sum >= 0.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for (int i=0; i<n; ++i) {
            sum += (gas[i] - cost[i]);
        }

        if (sum < 0) return -1;

        int cur = 0, answer = 0;
        for (int i=0; i<n; ++i) {
            cur += (gas[i] - cost[i]);
            if (cur < 0) {
                answer = i + 1;
                cur = 0;
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> gas, cost;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        gas.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        cost.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->canCompleteCircuit(gas, cost);
    printf("%d\n", answer);

    return 0;
}