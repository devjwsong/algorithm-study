#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool sortStart(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> answer;

        sort(intervals.begin(), intervals.end(), sortStart);
        int start = intervals[0][0], end = intervals[0][1];

        for (int i=1; i<n; ++i) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                answer.push_back(vector<int> {start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }

        if (answer.size() == 0 || !(answer[answer.size()-1][0] == start && answer[answer.size()-1][1] == end)) {
            answer.push_back(vector<int> {start, end});
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> intervals;
    for (int i=0; i<n; ++i) {
        vector<int> interval;
        int start, end;
        scanf("%d %d", &start, &end);
        interval.push_back(start);
        interval.push_back(end);

        intervals.push_back(interval);
    }

    Solution *sol = new Solution();
    vector<vector<int>> answer = sol->merge(intervals);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }

    return 0;
}