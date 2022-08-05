#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return vector<vector<string>> {vector<string>{""}};
        }

        unordered_map<string, vector<int>> table;
        for (int i=0; i<strs.size(); ++i) {
            string cpy = strs[i];
            sort(cpy.begin(), cpy.end());
            
            table[cpy].push_back(i);
        }

        vector<vector<string>> answer;
        string prev = "";
        for (auto iter = table.begin(); iter != table.end(); ++iter) {
            vector<string> anagrams;
            for (int i=0; i<iter->second.size(); ++i) {
                anagrams.push_back(strs[iter->second[i]]);
            }
            answer.push_back(anagrams);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);
    getchar();

    vector<string> strs;
    for (int i=0; i<n; ++i) {
        string val;
        getline(cin, val);
        strs.push_back(val);
    }

    Solution *sol = new Solution();
    vector<vector<string>> answer = sol->groupAnagrams(strs);

    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}