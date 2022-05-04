#include <iostream>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string answer = "";

        string prev = countAndSay(n-1);
        int start = 0, len = prev.size();
        char cur = '\0';
        while (start < len) {
            if (prev[start] != cur) {
                cur = prev[start];
                int count = 1;
                for (int i=start+1; i<len; ++i) {
                    if (prev[i] == cur) {
                        ++count;
                    } else {
                        start = i;
                        break;
                    }
                }
                answer += (to_string(count) + cur);
            } else {
                ++start;
            }
        }
        return answer;
    }
};


int main() {

    int n;
    cin>>n;

    Solution* sol = new Solution();
    string answer = sol->countAndSay(n);
    cout<<answer<<"\n";

    return 0;
}