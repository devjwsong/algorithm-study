#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_map<string, unordered_set<string>> mp;
        
        for (int i=0; i<n; ++i) {
            string email = emails[i];
            int idx = -1;
            for (int j=0; j<email.size(); ++j) {
                if (email[j] == '@') {
                    idx = j;
                    break;
                }
            }
            
            string localName = email.substr(0, idx);
            string domainName = email.substr(idx+1);
            
            string filtered = "";
            for (int j=0; j<localName.size(); ++j) {
                if (localName[j] == '+') {
                    break;    
                } else if (localName[j] != '.') {
                    filtered += localName[j];
                }
            }
            mp[domainName].insert(filtered);
        }
        
        int answer = 0;
        for (auto iter=mp.begin(); iter!=mp.end(); ++iter) {
            answer += iter->second.size();
        }
        
        return answer;
    }
};


int main() {

    int n;
    cin>>n;
    getchar();

    vector<string> emails;
    for (int i=0; i<n; ++i) {
        string email;
        getline(cin, email);
        emails.push_back(email);
    }

    Solution* sol = new Solution();
    int answer = sol->numUniqueEmails(emails);
    cout<<answer<<"\n";

    return 0;
}