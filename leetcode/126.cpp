#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


/*
Upgraded version of the problem 127!
BFS makes the shortest graph from endWord to startWord.
And by DFS(Backtracking), find all shortest paths.
Most submissions in Leetcode are subject to TLE, but this solution has passed.
I think the difference is BFS, which reduces the number of loops as much as possible.
However, the main ideas are similar, so the test cases might be too rough...
*/
class Solution {
public:
    unordered_map<string, int> dict;
    unordered_map<string, int> level;
    unordered_map<string, vector<string>> graph;
    vector<vector<string>> answer;
    vector<string> path;

    vector<string> getChildren(string s) {
        vector<string> res;
        for (int i=0; i<s.size(); ++i) {
            string temp = s;
            for (char c='a'; c<='z'; ++c) {
                temp[i] = c;
                if (temp == s) continue;
                if (dict.find(temp) != dict.end()) {
                    res.push_back(temp);
                }
            }
        }

        return res;
    }

    void bfs(string& beginWord) {
        queue<string> q;
        q.push(beginWord);
        dict[beginWord] = 1;
        level[beginWord] = 1;
        
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                string cur = q.front();
                q.pop();

                vector<string> children = getChildren(cur);
                for (int i=0; i<children.size(); ++i) {
                    string child = children[i];
                    if (dict[child] == 0) {
                        q.push(child);
                        ++dict[child];
                        level[child] = level[cur] + 1;
                        graph[child].push_back(cur);
                    } else {
                        if (level[child] == level[cur] + 1) {
                            graph[child].push_back(cur);
                        }
                    }
                }

                --size;
            }
        }
    }

    void dfs(string& start, string& vertex) {
        if (vertex == start) {
            path.push_back(vertex);
            vector<string> res = path;
            reverse(res.begin(), res.end());
            answer.push_back(res);
            path.pop_back();
            return;
        }

        path.push_back(vertex);
        for (int i=0; i<graph[vertex].size(); ++i) {
            dfs(start, graph[vertex][i]);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (int i=0; i<wordList.size(); ++i) {
            dict[wordList[i]] = 0;
        }
        bfs(beginWord);
        dfs(beginWord, endWord);

        return answer;
    }
};


int main() {

    string beginWord, endWord;
    getline(cin, beginWord);
    getline(cin, endWord);

    int n;
    scanf("%d", &n);
    vector<string> wordList;
    for (int i=0; i<n; ++i) {
        string word;
        getline(cin, word);
        wordList.push_back(word);
    }

    Solution* sol = new Solution();
    vector<vector<string>> answer = sol->findLadders(beginWord, endWord, wordList);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}