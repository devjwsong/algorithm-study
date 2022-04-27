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
        int answer = 0;
        int low = 0, high = x;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
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