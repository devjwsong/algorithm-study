#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Recursive + Memoization.
class Solution1 {
public:
    unordered_map<long long, long long> dp;

    long long integerReplacement(long long n) {
        if (n == 1) return 0;
        if (dp.find(n) != dp.end()) return dp[n];

        if (n % 2 == 0) {
            dp[n] = 1 + integerReplacement(n/2);
        } else {
            dp[n] = 1 + min(integerReplacement(n+1), integerReplacement(n-1));
        }

        return dp[n];
    }

    int integerReplacement(int n) {
        return (int) integerReplacement((long long) n);
    }
};


/* Bit manipulation.
Idea: Make 0 as many as possible.
xxxxx11 -> xxxx100 
xxxxx01 -> xxxxx00
The only exception is 3, since 11->10->1 is much more optimal than 11->100->10->1.
*/
class Solution2 {
public:
    int integerReplacement(unsigned int n) {
        if (n == 1) return 0;
        
        int answer = 0;
        while (n > 1) {
            if (n == 3) {
                answer += 2;
                break;
            }

            if (n % 2 == 1) {
                if (n & 2) {
                    n += 1;
                } else {
                    n -= 1;
                }
            } else {
                n /= 2;
            }
            ++answer;
        }


        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution1* sol1 = new Solution1();
    int answer = sol1->integerReplacement(n);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->integerReplacement(n);
    printf("%d\n", answer);

    return 0;
}