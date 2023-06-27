#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


/*
Sorting + Priority Queue.
Time: O(nlogn)
Space: O(n)
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i=0; i<n; ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        vector<int> answer;
        answer.push_back(tasks[0][2]);

        int i=1;
        int curTime = tasks[0][0] + tasks[0][1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        while (i < n) {
            if (tasks[i][0] <= curTime) {
                pq.push({tasks[i][1], tasks[i][2]});
                ++i;
            } else {
                if (pq.empty()) {
                    answer.push_back(tasks[i][2]);
                    curTime = tasks[i][0] + tasks[i][1];
                    ++i;
                } else {
                    pair<int, int> task = pq.top();
                    pq.pop();
                    answer.push_back(task.second);
                    curTime += task.first;
                }
            }
        }

        while (!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
