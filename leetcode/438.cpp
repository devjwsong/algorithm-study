#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSame(vector<int>& a, vector<int>& b) {
        for (int i=0; i<a.size(); ++i) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if (s.size() < p.size()) {
            return answer;
        }

        vector<int> goal (26, 0);
        vector<int> cur (26, 0);

        for (int i=0; i<p.size(); ++i) {
            goal[p[i] - 'a'] += 1;
        }

        for (int i=0; i<=s.size()-p.size(); ++i) {
            if (i == 0) {
                for (int j=i; j<p.size(); ++j) {
                    cur[s[j]-'a'] += 1;
                }
            } else {
                char prev = s[i-1], next = s[i+p.size()-1];
                cur[prev-'a'] -= 1;
                cur[next-'a'] += 1;
            }

            if (isSame(goal, cur)) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};


int main() {

    string s, p;
    getline(cin, s);
    getline(cin, p);

    Solution* sol = new Solution();
    vector<int> answer = sol->findAnagrams(s, p);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}