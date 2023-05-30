#include <iostream>
#include <string>
#include <limits.h>

using namespace std;


// Using string. (A little bit more time and space, but manageable.)
class Solution1 {
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


// Only using integers. (A little bit more efficient.)
class Solution2 {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;

        int sign = 1;
        if (x < 0) {
            x *= -1;
            sign = -1;
        }

        int res = 0;
        while (x > 0) {
            if (res > INT_MAX/10) return 0;

            int digit = x % 10;
            if (res == INT_MAX/10 && digit > INT_MAX%10) return 0;

            res = 10 * res + digit;
            x /= 10;
        }

        return sign * res;
    }
};
