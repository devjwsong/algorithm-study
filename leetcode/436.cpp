#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool compare(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second < p2.second;
    }
    
    int findRightStart(vector<pair<int, int>>& starts, int start, int val) {
        if (start >= starts.size()) return -1;
        int left = start, right = starts.size()-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (starts[mid].second < val) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        if (starts[left].second >= val) return starts[left].first;
        if (starts[right].second >= val) return starts[right].first;
        return -1;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts (n, pair<int, int> (-1, -1));
        vector<pair<int, int>> ends (n, pair<int, int> (-1, -1));
        for (int i=0; i<n; ++i) {
            starts[i].first = i;
            starts[i].second = intervals[i][0];
            ends[i].first = i;
            ends[i].second = intervals[i][1];
        }
        sort(starts.begin(), starts.end(), compare);
        sort(ends.begin(), ends.end(), compare);
        
        vector<int> answer (n, -1);
        for (int i=0; i<n; ++i) {
            int end = ends[i].second;
            int idx = findRightStart(starts, i, end);
            answer[ends[i].first] = idx;
        }
                
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> intervals;
    for (int i=0; i<n; ++i) {
        int start, end;
        scanf(" %d %d", &start, &end);
        intervals.push_back(vector<int> {start, end});
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->findRightInterval(intervals);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}