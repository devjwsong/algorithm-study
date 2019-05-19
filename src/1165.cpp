#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int t;

bool isLack(long long num, int prev, int next) {
    bool answer = false;
    int divisor = prev + 1;

    while(1) {
        if (divisor >= next) {
            break;
        }

        if (num % divisor == 0) {
            answer = true;
            break;
        } else {
            ++divisor;
        }
    }

    return answer;
}

int main() {

    scanf("%d", &t);

    for (int test=0; test<t; ++test) {
        int n = 0;
        scanf("%d", &n);

        vector<int> divisors;

        for (int i=0; i<n; ++i) {
            int input;
            scanf("%d", &input);
            divisors.push_back(input);
        }

        long long answer = -1;

        sort(divisors.begin(), divisors.end());

        long long num = (long long) divisors[0] * (long long) divisors[n-1];
        int start = 0;
        int end = n-1;
        
        while(1) {
            if (start > end) {
                answer = num;
                break;
            }

            if (num == (long long) divisors[start] * (long long) divisors[end]) {
                ++start;
                --end;
                continue;
            } else {
                answer = -1;
                break;
            }
        }

        bool cancel = false;

        for (int i=0; i<n; ++i) {

            if (i == 0) {
                cancel = isLack(num, 1, divisors[i]);
            } else {
                cancel = isLack(num, divisors[i-1], divisors[i]);
            }

            if (cancel) {
                answer = -1;
                break;
            }
        }

        printf("%lld\n", answer);

    }

    return 0;
}