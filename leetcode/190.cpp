#include <iostream>
#include <math.h>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t digit = pow(2, 31);
        uint32_t answer = 0;
        for (int i=0; i<32; ++i) {
            if ((n >> i) & 1 == 1) {
                answer += digit;
            }
            digit /= 2;
        }

        return answer;
    }
};


int main() {

    uint32_t n;
    scanf("%u", &n);

    Solution* sol = new Solution();
    uint32_t answer = sol->reverseBits(n);
    printf("%u\n", answer);

    return 0;
}