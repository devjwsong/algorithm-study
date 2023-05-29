#include <iostream>
#include <string>
#include <limits.h>

using namespace std;


class Solution {
public:
    bool isValid(string reversed, int sign) {
        string maxStr = to_string(INT_MAX);
        if (reversed.size() < maxStr.size()) return true;
        
        if (sign == 1 && reversed > maxStr) return false;
        if (sign == -1 && reversed > (maxStr.substr(0, maxStr.size()-1) + '8')) return false;

        return true;
    }

    int reverse(int x) {
        if (x == INT_MIN) return 0;

        int res = 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }

        string converted = to_string(x);
        string reversed = "";
        for (int i=converted.size()-1; i>=0; --i) {
            reversed += converted[i];
        }
        
        if (!isValid(reversed, sign)) return 0;

        return sign * stoi(reversed);
    }
};


int main() {

    int x = 0;
    scanf("%d", &x);

    Solution sol;
    int result = sol.reverse(x);

    printf("%d\n", result);

    return 0;
}