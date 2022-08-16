#include <iostream>

using namespace std;


// Simple solution
class Solution1 {
public:
    int mySqrt(int x) {
        int answer = 0;
        while(1) {
            long long  next = answer + 1;
            if (next * next > x) {
                return answer;
            }

            ++answer;
        }

        return answer;
    }
};


// Binary search
class Solution2 {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        while (low + 1 < high) {
            long long mid = (low + high) / 2;
            if (mid * mid > x) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (high * high <= x) return high;
        return low;
    }
};


int main() {
    
    int x;
    scanf("%d", &x);

    Solution1* sol1 = new Solution1();
    int answer = sol1->mySqrt(x);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->mySqrt(x);
    printf("%d\n", answer);

    return 0;
}