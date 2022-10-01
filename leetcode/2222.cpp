#include <iostream>

using namespace std;


/*
Very intuitive way!
num0sAfter: # of 0s after the index i.
num1sAfter: # of 1s after the index i.
num0sBefore: # of 0s before the index i.
num1sBefore: # of 1s before the index i.
*/
class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        int num0sAfter = 0, num1sAfter = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '0') ++num0sAfter;
            if (s[i] == '1') ++num1sAfter;
        }

        long long answer = 0;
        int num0sBefore = 0, num1sBefore = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '0') {
                answer += (num1sBefore * num1sAfter);
                --num0sAfter;
                ++num0sBefore;
            } else {
                answer += (num0sBefore * num0sAfter);
                --num1sAfter;
                ++num1sBefore;
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    long long answer = sol->numberOfWays(s);
    cout<<answer<<"\n";

    return 0;
}