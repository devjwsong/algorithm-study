#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> answer;
    vector<int> cur;

    void search(vector<int>& candidates, int& target, int sum, int idx) {
        if (sum > target) return;
        if (sum == target) {
            answer.push_back(cur);
            return;
        }

        for (int i=idx; i<candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            search(candidates, target, sum + candidates[i], i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        for (int i=0; i<candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            search(candidates, target, candidates[i], i);
            cur.pop_back();
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> candidates;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        candidates.push_back(val);
    }

    int target;
    scanf("%d", &target);

    Solution *sol = new Solution();
    vector<vector<int>> answer = sol->combinationSum(candidates, target);

    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}