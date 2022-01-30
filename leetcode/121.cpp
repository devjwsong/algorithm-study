#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profits (prices.size());
        profits[0] = 0;
        int min_value = prices[0];

        for (int i=1; i<prices.size(); ++i) {
            min_value = min(min_value, prices[i-1]);
            profits[i] = prices[i] - min_value;
        }

        int answer = -10000;
        for (int i=0; i<profits.size(); ++i) {
            answer = max(answer, profits[i]);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> prices;
    for (int i=0; i<n; ++i) {
        int p;
        scanf(" %d", &p);
        prices.push_back(p);
    }

    Solution *sol = new Solution();
    int answer = sol->maxProfit(prices);

    printf("%d\n", answer);

    return 0;
}