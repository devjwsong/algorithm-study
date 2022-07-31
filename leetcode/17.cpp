#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"}, 
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        if (n == 1) {
            string options = map[digits[0]];
            vector<string> results (options.size(), "");
            for (int i=0; i<options.size(); ++i) {
                results[i] = options.substr(i, 1);
            }
            return results;
        }

        vector<string> results;
        string options = map[digits[0]];
        for (int i=0; i<options.size(); ++i) {
            char first = options[i];
            vector<string> subResults = letterCombinations(digits.substr(1, n-1));
            for (int j=0; j<subResults.size(); ++j) {
                results.push_back(subResults[j].insert(0, 1, first));
            }
        }

        return results;
    }
};

int main() {

    string digits;
    getline(cin, digits);

    Solution *sol = new Solution();
    vector<string> answer = sol->letterCombinations(digits);

    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}