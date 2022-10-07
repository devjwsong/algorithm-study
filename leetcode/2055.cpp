#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Prefix sum with some tricks!
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prevCandles, nextCandles, prefixSums (n, 0);
        
        int prev = -1;
        for (int i=0; i<n; ++i) {
            if (s[i] == '|') {
                prev = i;
            }
            prevCandles.push_back(prev);
        }
        int next = n;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == '|') {
                next = i;
            }
            nextCandles.push_back(next);
        }
        reverse(nextCandles.begin(), nextCandles.end());

        int sum = 0;
        if (s[0] == '*') sum = 1;
        for (int i=1; i<n; ++i) {
            if (s[i] == '|') {
                prefixSums[i] = sum;
            } else {
                ++sum;
                prefixSums[i] = sum;
            }
        }

        vector<int> answer;
        int m = queries.size();
        for (int i=0; i<m; ++i) {
            int start = queries[i][0];
            int end = queries[i][1];

            int startCandle = nextCandles[start];
            int endCandle = prevCandles[end];

            // This is an exception handling since there can be no candle in this range.
            if (endCandle >= startCandle && startCandle >= 0 && endCandle < n) {
                answer.push_back(prefixSums[endCandle] - prefixSums[startCandle]);
            } else {
                answer.push_back(0);
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    int m;
    cin>>m;
    vector<vector<int>> queries;
    for (int i=0; i<m; ++i) {
        int start, end;
        cin>>start>>end;
        queries.push_back({start, end});
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->platesBetweenCandles(s, queries);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}