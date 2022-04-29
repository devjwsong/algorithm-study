#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;

        unordered_map<int, bool> hists;
        while(1) {
            if (hists.find(n) != hists.end()) break;
            if (n == 1) return true;
            hists[n] = true;

            int val = 0;
            while (n > 0) {
                val += ((n % 10) * (n % 10));
                n /= 10;
            }

            n = val;
        }

        return false;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    bool answer = sol->isHappy(n);
    printf("%d\n", answer);

    return 0;
}