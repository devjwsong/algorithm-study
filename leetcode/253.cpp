#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
Priority Queue.
Time: O(nlogn).
Space: O(n).
*/
class Solution1 {
public:
    int minMeetingRooms(vector<vector<int>> intervals) {
        int n = intervals.size();
        if (n == 1) return 1;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int answer = 1;
        pq.push(intervals[0][1]);
        for (int i=1; i<n; ++i) {
            if (pq.top() > intervals[i][0]) {
                ++answer;
            } else {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return answer;
    }
};


/*
More intuitive solution!
This solution makes the problem into how many rooms are currently held!
Time: O(nlogn)
Space: O(n)
*/
class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>> intervals) {
        int n = intervals.size();
        if (n == 1) return 1;

        vector<pair<int, int>> pairs;
        for (int i=0; i<n; ++i) {
            pairs.push_back({intervals[i][0], 1});
            pairs.push_back({intervals[i][1], -1});
        }

        sort(pairs.begin(), pairs.end());

        int answer = 0;
        int count = 0;
        for (int i=0; i<2*n; ++i) {
            if (pairs[i].second == 1) {
                ++count;
            } else {
                --count;
            }

            answer = max(answer, count);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> intervals;
    for (int i=0; i<n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        intervals.push_back({a, b});
    }

    Solution1* sol1 = new Solution1();
    int answer = sol1->minMeetingRooms(intervals);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->minMeetingRooms(intervals);
    printf("%d\n", answer);

    return 0;
}