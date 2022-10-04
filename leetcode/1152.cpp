#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        unordered_map<string, vector<pair<int, string>>> mp;
        for (int i=0; i<n; ++i) {
            mp[username[i]].push_back({timestamp[i], website[i]});
        }

        for (auto iter=mp.begin(); iter!=mp.end(); ++iter) {
            sort(iter->second.begin(), iter->second.end());
        }

        unordered_map<string, int> res;
        for (auto iter=mp.begin(); iter!=mp.end(); ++iter) {
            string user = iter->first;
            vector<pair<int, string>> logs = iter->second;
            unordered_set<string> st;

            int m = logs.size();
            for (int i=0; i<m-2; ++i) {
                for (int j=i+1; j<m-1; ++j) {
                    if (logs[i].first == logs[j].first) continue;

                    for (int k=j+1; k<m; ++k) {
                        if (logs[j].first == logs[k].first) continue;

                        string pattern = logs[i].second;
                        pattern += ' ';
                        pattern += logs[j].second;
                        pattern += ' ';
                        pattern += logs[k].second;

                        st.insert(pattern);
                    }
                }
            }

            for (auto iter2=st.begin(); iter2!=st.end(); ++iter2) {
                ++res[*iter2];
            }
        }

        vector<string> answer;
        int curMax = 0;
        for (auto iter=res.begin(); iter!=res.end(); ++iter) {
            string pattern = iter->first;
            vector<string> temp;
            string cur;
            for (int i=0; i<pattern.size(); ++i) {
                if (pattern[i] == ' ') {
                    temp.push_back(cur);
                    cur = "";
                } else {
                    cur += pattern[i];
                }
            }
            temp.push_back(cur);

            if (iter->second > curMax) {
                curMax = iter->second;
                answer = temp;
            } else if (iter->second == curMax) {
                if (temp < answer) {
                    answer = temp;
                }
            }
        }

        return answer;
    }
};


int main() {
    
    int n;
    cin>>n;
    getchar();

    vector<string> username, website;
    vector<int> timestamp;
    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        username.push_back(s);
    }
    for (int i=0; i<n; ++i) {
        int t;
        cin>>t;
        timestamp.push_back(t);
    }
    getchar();
    for (int i=0; i<n; ++i) {
        string w;
        getline(cin, w);
        website.push_back(w);
    }

    Solution *sol = new Solution();
    vector<string> answer = sol->mostVisitedPattern(username, timestamp, website);
    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2]<<"\n";
}