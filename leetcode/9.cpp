#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Into a string.
class Solution1 {
public:
    bool isPalindrome(int x) {
        string digits = to_string(x);
        int num_digits = digits.size();

        bool result = true;
        for (int i=0; i<num_digits / 2; ++i) {
            if (digits[i] != digits[num_digits-i-1]) {
                return false;
            }
        }

        return result;
    }
};


// 2. Without a string, but with a vector.
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> digits;

        while(x > 0) {
            int r = x % 10;
            x /= 10;

            digits.push_back(r);
        }

        int result = true;
        for (int i=0; i<digits.size() / 2; ++i) {
            if (digits[i] != digits[digits.size()-i-1]) {
                return false;
            }
        }
        return true;
    } 
};


// 3. Without a string and without a vector.
class Solution3 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int dec = 1;
        int cpy = x;
        while (cpy >= 10) {
            cpy /= 10;
            dec *= 10;
        }
        
        while (x > 0) {
            int digit = x % 10;
            if (digit != x / dec) return false;

            x -= (digit * dec);
            x /= 10;
            dec /= 100;
        }

        return true;
    }
};


int main() {

    int x = 0;
    scanf("%d", &x);

    Solution1 sol1;
    int result = sol1.isPalindrome(x);
    printf("%d\n", result);

    Solution2 sol2;
    result = sol2.isPalindrome(x);
    printf("%d\n", result);

    return 0;
}