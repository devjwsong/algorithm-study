#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    map<int, string> val2sym = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    string intToRoman(int num) {
        string answer;

        while (num > 0) {
            int factor = 0;
            string s = "";
            for (auto iter=val2sym.rbegin(); iter!=val2sym.rend(); ++iter) {
                if (num >= iter->first) {
                    factor = iter->first;
                    s = iter->second;
                    break;
                }
            }

            answer += s;
            num -= factor;
        }

        return answer;
    }
};


int main() {

    int num;
    cin>>num;

    Solution* sol = new Solution();
    string answer = sol->intToRoman(num);
    cout<<answer<<"\n";

    return 0;
}