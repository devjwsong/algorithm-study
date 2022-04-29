#include <iostream>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        uint32_t cur = 1;
        for (int i=0; i<32; ++i) {
            if ((n >> i) & 1 == 1) {
                ++answer;
            }
            cur *= 2;
        }

        return answer;
    }
};


int main() {

    uint32_t n;
    scanf("%u", &n);

    Solution* sol = new Solution();
    int answer = sol->hammingWeight(n);
    printf("%d\n", answer);

    return 0;
}