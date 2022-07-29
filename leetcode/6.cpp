#include <iostream>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n == 1 || numRows == 1) return s;

        string answer;
        int dist1 = 0, dist2 = 0;
        for (int start=0; start<numRows; ++start) {
            if (start == 0 || start == numRows-1) {
                dist1 = 2*numRows-2;
                dist2 = 0;
            } else {
                dist1 -= 2;
                dist2 += 2;
            }
            
            int i = start;
            bool isDist1 = true;
            while (i < n) {
                answer += s[i];
                if (dist2 == 0) {
                    i += dist1;
                } else {
                    if (isDist1) {
                        i += dist1;
                        isDist1 = false;
                    } else {
                        i += dist2;
                        isDist1 = true;
                    }
                }
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    int numRows;
    cin>>numRows;

    Solution* sol = new Solution();
    string answer = sol->convert(s, numRows);
    cout<<answer<<"\n";

    return 0;
}