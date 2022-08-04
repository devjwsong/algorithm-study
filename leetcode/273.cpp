#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };

    string convertBelow1000(int num) {
        string res;
        for (int div=100; div>0; div /= 10) {
            if (div == 100 && num >= div) {
                res += (mp[num / div] + " Hundred ");
                num %= div;
            } else if (div == 10 && num >= div) {
                if (mp.find(num) != mp.end()) {
                    res += mp[num];
                    break;
                } else {
                    res += (mp[num / div * 10] + " ");
                    num %= div;
                }
            } else if (div == 1) {
                res += mp[num];
            }
        }

        if (res[res.size()-1] == ' ') res.pop_back();

        return res;
    }

    string numberToWords(int num) {
        string answer;
        if (num == 0) return "Zero";
        
        while (num > 0) {
            if (num >= 1000000000) {
                answer += (convertBelow1000(num / 1000000000) + " Billion ");
                num %= 1000000000;
            } else if (num >= 1000000) {
                answer += (convertBelow1000(num / 1000000) + " Million ");
                num %= 1000000;
            } else if (num >= 1000) {
                answer += (convertBelow1000(num / 1000) + " Thousand ");
                num %= 1000;
            } else {
                answer += convertBelow1000(num);
                num = 0;
            }
        }

        if (answer[answer.size()-1] == ' ') answer.pop_back();

        return answer;
    }
};


int main() {

    int num;
    cin>>num;

    Solution* sol = new Solution();
    string answer = sol->numberToWords(num);
    cout<<answer<<"\n";

    return 0;
}