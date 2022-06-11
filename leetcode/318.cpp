#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int makeNum(string word) {
        int num = 0;
        for (int c=0; c<word.size(); ++c) {
            num |= (1 << (word[c]-'a'));
        } 

        return num;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> nums (n, 0);
        for (int i=0; i<n; ++i) {
            nums[i] = makeNum(words[i]);
        }

        int answer = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if ((nums[i] & nums[j]) == 0) {
                    answer = max(answer, (int) words[i].size() * (int) words[j].size());
                }
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);
    getchar();

    vector<string> words;
    for (int i=0; i<n; ++i) {
        string val;
        getline(cin, val);
        words.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->maxProduct(words);
    printf("%d\n", answer);

    return 0;
}