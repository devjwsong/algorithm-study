#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cur = strs[0];
        for (int i=1; i<strs.size(); ++i) {
            string str = strs[i];
            int num_iters = min(cur.size(), str.size());
            
            string next = "";
            for  (int j=0; j<num_iters; ++j) {
                if (cur[j] == str[j]) {
                    next += cur[j];
                } else {
                    break;
                }
            }

            cur = next;
        }

        return cur;
    }
};


int main() {

    vector<string> strs;

    int n = 0;
    scanf("%d", &n);\
    getchar();

    for (int i=0; i<n; ++i) {
        string input;
        getline(cin, input);

        strs.push_back(input);
    }

    Solution sol;
    string result = sol.longestCommonPrefix(strs);

    cout<<result<<"\n";

    return 0;
}