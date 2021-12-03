#include <iostream>
#include <map>
#include <string>

using namespace std;


class Solution{
public:
    map<char, int> romanMap;
    Solution() {
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
    }

    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'I') {
                if (i < s.size()-1) {
                    if (s[i+1] == 'V') {
                        result += 4;
                        ++i;
                    } else if (s[i+1] == 'X') {
                        result += 9;
                        ++i;
                    } else {
                        result += 1;
                    }
                } else {
                    result += 1;
                }

            } else if (s[i] == 'X') {
                if (i < s.size()-1) {
                    if (s[i+1] == 'L') {
                        result += 40;
                        ++i;
                    } else if (s[i+1] == 'C') {
                        result += 90;
                        ++i;
                    } else {
                        result += 10;
                    }
                } else {
                    result += 10;
                }

            } else if (s[i] == 'C') {
                if (i < s.size()-1) {
                    if (s[i+1] == 'D') {
                        result += 400;
                        ++i;
                    } else if (s[i+1] == 'M') {
                        result += 900;
                        ++i;
                    } else {
                        result += 100;
                    }
                } else {
                    result += 100;
                }
            } else {
                result += romanMap[s[i]];
            }

            ++i;
        }

        return result;
    }

};


int main() {

    string input;
    getline(cin, input);

    Solution sol;
    int result = sol.romanToInt(input);

    cout<<result<<"\n";

    return 0;
}