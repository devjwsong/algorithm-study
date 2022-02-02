#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int MAX = INT_MAX;


class Solution {
public:
    bool isValid(string reversed, int pre) {
        string max = to_string(MAX);
        
        if (pre == -1) {
            max = max.substr(0, max.size()-1) + '8';
        }

        if (reversed.size() < max.size()) {
            return true;
        } else if (reversed.size() > max.size()) {
            return false;
        } else {
            for (int i=0; i<reversed.size(); ++i) {
                if (reversed[i] > max[i]) {
                    return false;
                } else if (reversed[i] < max[i]) {
                    return true;
                }
            }
            
            return true;
        }
    }

    int reverse(int x) {
        int result = 0;
        int pre = 0;
        if (x < 0) {
            pre = -1;
        } else {
            pre = 1;
        }

        string converted = to_string(x);
        if (pre == -1) {
            converted = converted.substr(1, converted.size());
        }
        string reversed = "";
        for (int i=converted.size()-1; i>=0; --i) {
            reversed += converted[i];
        }

        if (isValid(reversed, pre)) {
            return pre * stoi(reversed);
        }

        return 0;

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