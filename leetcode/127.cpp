#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


/*
Simple BFS problem. But a few things to remind!
1. We can control the iteration by iterating separately according to the queue size,
in order to proceed level-by-level.
2. It is much faster to modify each letter than to compare string by string.
3. It is allowed to remove the string we checked immediately from the set,
because it is first accessed in this iteration, which means the minimum modification to this phase.
Therefore, by removing it, we can prevent repeated iterations.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (int i=0; i<wordList.size(); ++i) {
            st.insert(wordList[i]);
        }
        if (st.find(endWord) == st.end()) return 0;

        int answer = 0;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            ++answer;
            int qLen = q.size();

            for (int i=0; i<qLen; ++i) {
                string cur = q.front();
                q.pop();

                for (int j=0; j<cur.size(); ++j) {
                    char origin = cur[j];
                    for (int c='a'; c<='z'; ++c) {
                        cur[j] = c;
                        if (cur == endWord) return answer+1;
                        if (st.find(cur) == st.end()) continue;
                        st.erase(cur);
                        q.push(cur);
                    }
                    cur[j] = origin;
                }
            }
        }

        return 0;
    }
};


int main() {

    string beginWord, endWord;
    getline(cin, beginWord);
    getline(cin, endWord);

    int n;
    cin>>n;
    getchar();
    
    vector<string> wordList;
    for (int i=0; i<n; ++i) {
        string val;
        getline(cin, val);
        wordList.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->ladderLength(beginWord, endWord, wordList);
    cout<<answer<<"\n";

    return 0;
}