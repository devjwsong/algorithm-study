#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last (26, -1);

        for (int i=0; i<n; ++i) {
            last[s[i]-'a'] = i;
        }

        vector<int> answer;
        int start = 0, end = 0;
        for (int i=0; i<n; ++i) {
            end = max(end, last[s[i]-'a']);
            if (end == i) {
                answer.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    vector<int> answer = sol->partitionLabels(s);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}