#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int answer = 0;
        int n = houses.size();
        for (int i=0; i<n; ++i) {
            auto iter = upper_bound(heaters.begin(), heaters.end(), houses[i]);
            int left = INT32_MAX, right = INT32_MAX;
            if (iter != heaters.end()) {
                right = *iter - houses[i];
            }
            if (iter != heaters.begin()) {
                left = houses[i] - *prev(iter);
            }
            answer = max(answer, min(left, right));
        }

        return answer;
    }
};


int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> houses, heaters;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        houses.push_back(val);
    }
    for (int i=0; i<m; ++i) {
        int val;
        scanf(" %d", &val);
        heaters.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->findRadius(houses, heaters);
    printf("%d\n", answer);

    return 0;
}