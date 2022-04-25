#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;

        vector<int> answer (n, 0);
        for (int i=n-1; i>=0; --i) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (!s.empty()) {
                answer[i] = s.top() - i;
            }

            s.push(i);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> temperatures;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        temperatures.push_back(val);
    }

    Solution *sol = new Solution();
    vector<int> answer = sol->dailyTemperatures(temperatures);
    for (int i=0; i<n; ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}