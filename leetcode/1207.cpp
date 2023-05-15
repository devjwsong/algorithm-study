#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();

        for (int i=0; i<n; ++i) {
            ++mp[arr[i]];
        }

        unordered_set<int> st;
        for (unordered_map<int, int>::iterator i = mp.begin(); i != mp.end(); ++i) {
            if (st.find(i->second) != st.end()) {
                return false;
            }
            st.insert(i->second);
        }
        return true;
    }
};
