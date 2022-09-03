#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (t.size() != n) return false;
        
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for (int i=0; i<n; ++i) {
            if (mp.find(s[i]) == mp.end()) {
                if (st.find(t[i]) != st.end()) return false;
                mp[s[i]] = t[i];
                st.insert(t[i]);
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        
        return true;
    }
};


int main() {

    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution* sol = new Solution();
    bool answer = sol->isIsomorphic(s, t);
    cout<<answer<<"\n";

    return 0;
}