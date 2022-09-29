#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    long long getDist(vector<int>& point1, vector<int>& point2) {
        int diffX = point1[0] - point2[0];
        int diffY = point1[1] - point2[1];
        return diffX * diffX + diffY * diffY;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<long long, int>> pq;
        
        vector<int> base = {0, 0};
        for (int i=0; i<n; ++i) {
            long long dist = getDist(points[i], base);
            pq.push({dist, i});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> answer;
        while (!pq.empty()) {
            answer.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return answer;
    }
};


int main() {
    
    int n;
    scanf("%d", &n);

    vector<vector<int>> points;
    for (int i=0; i<n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        points.push_back({x, y});
    }

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    vector<vector<int>> answer = sol->kClosest(points, k);
    for (int i=0; i<n; ++i) {
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }

    return 0;
}