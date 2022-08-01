#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Time: O(m*n).
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size();
        unordered_map<string, int> dict;
        for (int i=0; i<m; ++i) {
            ++dict[words[i]];
        }

        vector<int> answer;
        int wordSize = words[0].size();
        for (int start=0; start<=n-(m * wordSize); ++start) {
            unordered_map<string, int> checked;
            for (int i=0; i<m; ++i) {
                string subStr = s.substr(start+i*wordSize, wordSize);
                
                if (dict.find(subStr) == dict.end()) break;
                ++checked[subStr];
                if (checked[subStr] > dict[subStr]) break;

                if (i + 1 == m) answer.push_back(start);
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    int n;
    cin>>n;
    getchar();

    vector<string> words;
    for (int i=0; i<n; ++i) {
        string word;
        getline(cin, word);
        words.push_back(word);
    }

    Solution *sol = new Solution();
    vector<int> answer = sol->findSubstring(s, words);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}