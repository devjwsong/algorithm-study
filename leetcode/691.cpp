#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Tricky backtracking & DP problem...
Since the current state is memorized as bit representations, it is not efficient to use target's index.
So here, the index is stickers list's index.
There are three cases.
1. If current sticker did nothing, just move the index to the next.
2. If current sticker erased some letters, ignore it and move to the next sticker.
3. If current sticker erased some letters, save the sticker which I used here and use this sticker again.
*/
class Solution {
public:
    vector<vector<int>> dp;

    int search(vector<string>& stickers, string& target, int i, int mask) {
        if (mask == 0) return 0;
        if (i == stickers.size()) return 100000000;
        if (dp[i][mask] != -1) return dp[i][mask];

        int dict[26] = {0};
        for (int j=0; j<stickers[i].size(); ++j) {
            ++dict[stickers[i][j]-'a'];
        }

        int newMask = 0;
        for (int j=0; j<target.size(); ++j) {
            int bit = (1 << j);
            if (mask & bit) {
                if (dict[target[j]-'a'] > 0) {
                    --dict[target[j]-'a'];
                } else {
                    newMask += bit;
                }
            }
        }

        if (mask == newMask) {
            int case1 = search(stickers, target, i+1, mask);
            return dp[i][mask] = case1;
        }
        int case2 = search(stickers, target, i+1, mask);
        int case3 = search(stickers, target, i, newMask) + 1;
        return dp[i][mask] = min(case2, case3);
    }

    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size(), m = target.size();
        dp.assign(n, vector<int> (1<<m, -1));

        int mask = (1 << m) - 1;
        int res = search(stickers, target, 0, mask);
        if (res == 100000000) return -1;
        return res;
    }
};


int main() {

    int n;
    cin>>n;
    getchar();

    vector<string> stickers;
    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        stickers.push_back(s);
    }

    string target;
    getline(cin, target);

    Solution* sol = new Solution();
    int answer = sol->minStickers(stickers, target);
    cout<<answer<<"\n";

    return 0;
}