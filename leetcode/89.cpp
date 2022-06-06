#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer = {0, 1};
        if (n == 1) return answer;

        int num = 1 << n;
        int curLen = 4, idx = answer.size()-1;
        while (curLen <= num) {
            answer.push_back((curLen / 2) | answer[idx]);
            --idx;

            if (answer.size() == curLen) {
                idx = answer.size()-1;
                curLen *= 2;
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    vector<int> answer = sol->grayCode(n);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}