#include <iostream>
#include <cmath>

using namespace std;


// Math
class Solution1 {
public:
    int findNthDigit(int n) {
        int numPrevs = 0, numDigits = 1;
        while(numDigits < 10) {
            long long num = pow(10, numDigits-1) * 9;
            if (n > numPrevs + num * numDigits) {
                numPrevs += num * numDigits;
                ++numDigits;
            } else {
                break;
            }
        }

        if (numDigits == 1) return n;

        n -= numPrevs;
        int q = n / numDigits, r = n % numDigits;

        if (r == 0) {
            return ((int) pow(10, numDigits-1) - 1 + q) % 10;
        } else {
            int cur = pow(10, numDigits-1) + q;
            int answer = 0;
            while (r > 0) {
                answer = cur / (int) pow(10, numDigits-1);
                --r;
                cur %= (int) pow(10, numDigits-1);
                --numDigits;
            }

            return answer;
        }
    }
};


// Binary search
class Solution2 {
public:
    long long getNumPrevDigits(int val) {
        int numDigits = 0, temp = val;
        while (temp > 0) {
            ++numDigits;
            temp /= 10;
        }
        
        if (numDigits == 1) return val-1;
        
        long long res = 0;
        for (int d=1; d<numDigits; ++d) {
            res += 9 * (long long) pow(10, d-1) * d;
        }
        res += (val - (long long) pow(10, numDigits-1)) * numDigits;
        
        return res;
    }
    
    int findNthDigit(int n) {
        int low = 1, high = 1e9;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            long long numPrevDigits = getNumPrevDigits(mid);
            if (n > numPrevDigits) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        int cur = 0;
        long long lowPrevDigits = getNumPrevDigits(low);
        long long highPrevDigits = getNumPrevDigits(high);
        if (n > highPrevDigits) {
            cur = high;
            n -= highPrevDigits;
        } else {
            cur = low;
            n -= lowPrevDigits;
        }
        
        return to_string(cur)[n-1] - '0';
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution1* sol1 = new Solution1();
    int answer = sol1->findNthDigit(n);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->findNthDigit(n);
    printf("%d\n", answer);

    return 0;
}