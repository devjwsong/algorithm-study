#include <iostream>

using namespace std;


class Solution {
public:
    int getSum(int a, int b) {
        int carry= 0, answer = 0;
        for (int i=0; i<32; ++i) {
            int aa = a & (1 << i) ? 1 : 0;
            int bb = b & (1 << i) ? 1 : 0;

            answer |= ((aa ^ bb ^ carry) << i);

            if (carry == 1) {
                if (aa || bb) {
                    carry = 1;
                } else {
                    carry = 0;
                }
            } else {
                if (aa && bb) {
                    carry = 1;
                } else {
                    carry = 0;
                }
            }
        }

        return answer;
    }
};


int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    Solution* sol = new Solution();
    int answer = sol->getSum(a, b);
    printf("%d\n", answer);
}