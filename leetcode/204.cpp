#include <iostream>
#include <vector>

using namespace std;


// Sieve of Eratosthenes: O(nloglogn), in this case O(sqrt(n)loglogn)
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrimes (n, true);
        int k = 2;
        while (k * k < n) {
            if (isPrimes[k]) {
                int i = 2;
                while (k * i < n) {
                    isPrimes[k * i] = false;
                    ++i;
                }
            }
            ++k;
        }

        int answer = 0;
        for (int i=2; i<n; ++i) {
            if (isPrimes[i]) ++answer;
        }

        return answer;
    }
};


int main() {
    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    int answer = sol->countPrimes(n);
    printf("%d\n", answer);

    return 0;
}