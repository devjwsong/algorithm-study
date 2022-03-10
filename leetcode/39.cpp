#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> answer;

    void search(vector<int>& candidates, vector<int> cur, int minIdx, int remain) {
        if (remain == 0) {
            answer.push_back(cur);
        } else if (remain > 0) {
            for (int i=minIdx; i<candidates.size(); ++i) {
                if (candidates[i] <= remain) {
                    vector<int> next = cur;
                    next.push_back(candidates[i]);
                    search(candidates, next, i, remain-candidates[i]);
                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());

        for (int i=0; i<candidates.size(); ++i) {
            search(candidates, vector<int> {candidates[i]}, i, target-candidates[i]);
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