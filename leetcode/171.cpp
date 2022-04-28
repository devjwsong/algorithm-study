#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        for (int i=0; i<columnTitle.size(); ++i) {
            int digit = columnTitle[i] - 'A' + 1;
            answer = answer * 26 + digit;
        }

        return answer;
    }
};


int main() {

    string columnTitle;
    getline(cin, columnTitle);

    Solution* sol = new Solution();
    int answer = sol->titleToNumber(columnTitle);
    cout<<answer<<"\n";

    return 0;
}