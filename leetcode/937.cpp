#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    pair<string, string> identify(string log) {
        int l = log.size();
        int idx = -1;
        for (int i=0; i<l; ++i) {
            if (log[i] == ' ') {
                idx = i;
                break;
            }
        }
        
        string identifier = log.substr(0, idx);
        string content = log.substr(idx+1, log.size()-idx-1);
        return {identifier, content};
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        if (n == 1) return logs;
        
        vector<vector<string>> v;
        for (int i=0; i<n; ++i) {
            vector<string> temp;
            pair<string, string> res = identify(logs[i]);
            string identifier = res.first;
            string content = res.second;
            
            string dataType;
            if (content[0] >= '0' && content[0] <= '9') {
                dataType = "1";
            } else {
                dataType = "0";
            }
            temp.push_back(dataType);
            
            if (dataType == "1") {
                string idx = to_string(i);
                while (idx.size() < 3) {
                    idx.insert(0, "0");
                }
                temp.push_back(idx);
            } else {
                temp.push_back("0");
            }
            
            temp.push_back(content);
            temp.push_back(identifier);
            
            v.push_back(temp);
        }
        
        sort(v.begin(), v.end());
        
        vector<string> answer;
        for (int i=0; i<n; ++i) {
            answer.push_back(v[i][3] + " " + v[i][2]);
        }
        
        return answer;
    }
};


int main() {

    int n;
    cin>>n;
    getchar();

    vector<string> logs;
    for (int i=0; i<n; ++i) {
        string log;
        getline(cin, log);
        logs.push_back(log);
    }

    Solution* sol = new Solution();
    vector<string> answer = sol->reorderLogFiles(logs);
    for (int i=0; i<n; ++i) {
        cout<<answer[i]<<"\n";
    }

    return 0;
}