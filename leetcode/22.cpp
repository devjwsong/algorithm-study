#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> answer;

    void dfs(string cur, int n, int numLeft, int numRight) {
        if (cur.size() == (2*n)) {
            answer.push_back(cur);
        } else {
            if (numLeft < n) {
                dfs(cur + '(', n, numLeft+1, numRight);
            }
            
            if (numLeft > 0 && numLeft > numRight) {
                dfs(cur + ')', n, numLeft, numRight+1);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs("(", n, 1, 0);
        return answer;
    }
};

int main() {

    int n;
    scanf("%d", &n);

    Solution *sol = new Solution();
    vector<string> answer = sol->generateParenthesis(n);
    
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<"\n";
    }

    return 0;
}