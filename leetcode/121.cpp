#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int leftMin = prices[0];

        int answer = 0;
        for (int i=1; i<n; ++i) {
            leftMin = min(leftMin, prices[i-1]);
            answer = max(answer, prices[i] - leftMin);
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