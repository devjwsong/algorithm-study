#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int extra = 0;
        for (int i=n-1; i>=0; --i) {
            int newDigit = digits[i] + extra;
            if (i == n-1) {
                newDigit += 1;
            }

            if (newDigit >= 10) {
                extra = 1;
                newDigit -= 10;
            } else {
                extra = 0;
            }

            digits[i] = newDigit;
        }

        if (extra == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() {

    int n;
    scanf("%d", &n);

    vector<int> digits;
    for (int i=0; i<n; ++i) {
        int digit;
        scanf(" %d", &digit);
        digits.push_back(digit);
    }

    Solution *sol = new Solution();
    vector<int> answer = sol->plusOne(digits);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}