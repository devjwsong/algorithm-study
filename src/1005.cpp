#include <iostream>
#include <vector>

using namespace std;

int numTest = 0;
vector<int> results;

int getTime(vector<int> rules[], vector<int>& times, int memo[], int goal) {

    if (rules[goal].size() == 0) {
        return times[goal];
    }

    if (memo[goal] != -1) {
        return memo[goal];
    }

    int max_value = 0;

    for (int i=0; i<rules[goal].size(); ++i) {
        int value = getTime(rules, times, memo, rules[goal][i]);
        if (value > max_value) {
            max_value = value;
        }
    }

    memo[goal] = max_value + times[goal];

    return memo[goal];
}

int main() {

    scanf("%d", &numTest);

    for (int test=0; test<numTest; ++test) {

        int n = 0;
        int r = 0;
        scanf("%d", &n);
        scanf("%d", &r);

        vector<int> times;
        times.push_back(-1);

        for (int i=0; i<n; ++i) {
            int input = 0;
            scanf("%d", &input);
            times.push_back(input);
        }

        vector<int> rules[n+1];

        for (int i=0; i<r; ++i) {
            int prev = 0;
            int next = 0;
            scanf("%d", &prev);
            scanf("%d", &next);

            rules[next].push_back(prev);
        }

        int goal = 0;
        scanf("%d", &goal);

        int memo[n+1];
        for (int i=1; i<n+1; ++i) {
            memo[i] = -1;
        }

        int result = getTime(rules, times, memo, goal);
        results.push_back(result);
    }

    for (int i=0; i<results.size(); ++i) {
        printf("%d\n", results[i]);
    }

    return 0;
}