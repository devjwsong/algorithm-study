/*
Highly difficult problem!
These algorighms are based on "Sweep line" algorithm, which models the problem as a group of sequential events.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;


/*
Priority Queue + hash map.
First, make another vector to contain each point in a shape of (position, height). 
And to mark the left point, multiply -1 to the height. 
Then sorting makes the points aligned in ascending order according to the position or left to right.
Then here are pq and map. 
The former takes the left points in ascending order by height and the latter counts the number of right points. 
The first point is included in the answer regardlessly.
Now, iterate from 1. If the current point is a left point, 
it is included if the current height is higher than the max height,
or the queue is empty, which indicates that this is another first point of additional skyline.
In the case of right points, which is more complicated, 
first pop all right points which have the max height. 
This means that we should exclude the finished building. 
If the left one already came out but the right one haven't then the left point is in the queue but the right point is not in the map. 
Additionally, if the right point also came out but that height is not the maximum, 
then in the queue there is the left one also and the right one is pended in the map. 
In either case, popping all points we can leads to the empty queue, which means that one skyline is over, 
or a building with maximum height, which is lower than the current height. So this height becomes a point in the skyline.
*/
class Solution1 {
public:
    struct compPQ {
        bool operator() (pair<int, int>& pair1, pair<int, int>& pair2) {
            int h1 = abs(pair1.second);
            int h2 = abs(pair2.second);
            return h1 < h2;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        
        vector<pair<int, int>> pairs;
        for (int i=0; i<n; ++i) {
            pairs.push_back({buildings[i][0], -buildings[i][2]});
            pairs.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int>> answer;
        answer.push_back(vector<int> {pairs[0].first, abs(pairs[0].second)});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compPQ> pq;
        pq.push(pairs[0]);
        
        unordered_map<int, int> counts;
        
        for (int i=1; i<pairs.size(); ++i) {
            if (pairs[i].second < 0) {  // left
                int prev = INT32_MAX;
                if (!pq.empty()) prev = abs(pq.top().second);
                pq.push(pairs[i]);
                int cur = abs(pq.top().second);
                
                if (cur > prev || pq.size() == 1) {
                    answer.push_back(vector<int> {pairs[i].first, abs(pairs[i].second)});
                }
            } else {  //right
                ++counts[pairs[i].second];
                int h = pairs[i].second, p = pairs[i].first;
                
                while (counts.find(abs(pq.top().second)) != counts.end()) {
                    int top = abs(pq.top().second);
                    --counts[top];
                    if (counts[top] == 0) counts.erase(top);
                    pq.pop();
                    if (counts.size() == 0) break;
                }
                
                int newH = 0;
                if (!pq.empty()) newH = abs(pq.top().second);
                
                if (newH < h) {
                    answer.push_back(vector<int> {p, newH});
                }
            }
        }
        
        return answer;
    }
};


/*
Multiset.
More easier version is with multiset. The idea is the same.
When the current point is a left one, put this in the set. 
And if it is a right one, then erase all the left points with the same height. 
Here, why do we have to erase all points with the current height, not the maximum height? 
It is actually the same as the previous approach, since we should calculate the lower maximum height but without the separate counter map. 
If there is a higher height than the current one, this makes no change, since the max height is still active. 
On the other hands, if there is a difference, that means the current height is also the maximum, 
and this means we can find the value we want by popping all of them. 
Even if all left points are erased, these buildings work as a huge single building, 
so after their right counterparts comes out, there is no difference.
Anyway, if the current height is difference from the max height, it is considered as a part of the answer. 
The meaning of difference between the maximum heights and the current maximum heights in the set is as follows. 
If the current point is left point, that means the maximum height should be updated and the updated height becomes the skyline. 
If the current case is a right one, the difference means the activation height changed and the current maximum height is the next maximum height after the current point, 
so this also becomes the skyline.
*/
class Solution2 {
public:
    struct compPQ {
        bool operator() (pair<int, int>& pair1, pair<int, int>& pair2) {
            int h1 = abs(pair1.second);
            int h2 = abs(pair2.second);
            return h1 < h2;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        
        vector<pair<int, int>> pairs;
        for (int i=0; i<n; ++i) {
            pairs.push_back({buildings[i][0], -buildings[i][2]});
            pairs.push_back({buildings[i][1], buildings[i][2]});
        }
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int>> answer;
        multiset<int> ms;
        ms.insert(0);
        int maxH = 0;
        for (int i=0; i<pairs.size(); ++i) {
            if (pairs[i].second < 0) {  // left
                ms.insert(abs(pairs[i].second));
            } else {  //right
                ms.erase(ms.find(pairs[i].second));
            }
            
            int cur = *ms.rbegin();
            if (maxH != cur) {
                answer.push_back(vector<int> {pairs[i].first, cur});
                maxH = cur;
            }
        }
        
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> buildings;
    for (int i=0; i<n; ++i) {
        int l, r, h;
        scanf(" %d %d %d", &l, &r, &h);
        buildings.push_back(vector<int> {l, r, h});
    }

    Solution1* sol1 = new Solution1();
    vector<vector<int>> answer = sol1->getSkyline(buildings);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }

    Solution2* sol2 = new Solution2();
    answer = sol2->getSkyline(buildings);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }

    return 0;
}