#include <iostream>
#include <cmath>

using namespace std;

// With loop.
class Solution1 {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;

        while(n > 1) {
            if (n % 3 != 0) {
                return false;
            }

            n /= 3;
        }

        return true;
    }
};


// Without loop.
class Solution2 {
public:
    bool isPowerOfThree(int n) {        
        int max = 1162261467;

        return n >= 1 && max % n == 0;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution1* sol1 = new Solution1();
    bool answer = sol1->isPowerOfThree(n);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->isPowerOfThree(n);
    printf("%d\n", answer);

    return 0;
}