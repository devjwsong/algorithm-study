#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


/*
Hash map + Priority Queue.
Time: O(nlogn).
The basic idea here is to consume letters which have more occurences.
e.g. aaabbccd => abacabcd.
*/
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i=0; i<n; ++i) {
            ++mp[s[i]];
        }

        priority_queue<pair<int, char>> pq;
        for (auto iter=mp.begin(); iter!=mp.end(); ++iter) {
            pq.push({iter->second, iter->first});
        }

        string answer = "";
        while (!pq.empty()) {
            char c = pq.top().second;
            answer += c;
            int cNum = pq.top().first;
            --cNum;
            pq.pop();

            if (cNum >= 1) {
                if (pq.empty()) {
                    return "";
                } else {
                    /*
                    The reason why the process occurs here again is that
                    if c's number becomes the same with the current top,
                    then it is possible for c to come out right after this iteration.
                    And this is not what we want.
                    */
                    char d = pq.top().second;
                    answer += d;
                    int dNum = pq.top().first;
                    --dNum;
                    pq.pop();

                    if (dNum >= 1) {
                        pq.push({dNum, d});
                    }
                }

                pq.push({cNum, c});
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    string answer = sol->reorganizeString(s);
    cout<<answer<<"\n";

    return 0;
}