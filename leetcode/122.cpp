#include <iostream>
#include <vector>

using namespace std;


/*
Why is this working? The point is just iterating and adding the directly increasing part in the price graph.
Assume that the prices is increasing for certain range, 
then the profit we can get by subtracting the min value from the max value is actually the same with adding the adjacent increasing part continuously.
e.g. 1 -> 3 -> 4 -> 7 == 1 -> 7
On the other hand, if the price drops down at certain point,
then it is advantageous to sell the stock right before the price decreases, not waiting for later day where the price goes to the maximum.
e.g. 1 -> 3 -> 2 -> 5  < 1 -> 3 + 2 -> 5
This it because unless the dropped value is larger than the previous price, the sum of two differences is always larger than the difference produced by the total range.
And this is a contradiction since there is no way that the dropped value is larger than the previous value!
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        for (int i=1; i<prices.size(); ++i) {
            answer += max(0, prices[i]-prices[i-1]);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> prices;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        prices.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->maxProfit(prices);
    printf("%d\n", answer);

    return 0;
}