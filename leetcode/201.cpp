#include <iostream>

using namespace std;


/*
Very Very simple idea!
If the number of bits are different, no matter what happened, the result is 0.
Because the moment that the number of digits changes, all digits before then becomes 0 due to and operation.
So we just have to think the integers in the range has the same number of digits.
We should find the common part between left and right.
This common part is answer, because the rest becomes 0 since at least one 0 exists in each position.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 || right == 0) return 0;
        if (left == right) return left;

        int count = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++count;
        }

        return left<<count;
    }
};


int main() {

    int left, right;
    scanf("%d %d", &left, &right);

    Solution* sol = new Solution();
    int answer = sol->rangeBitwiseAnd(left, right);
    printf("%d\n", answer);

    return 0;
}