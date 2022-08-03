#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


// Topological sort.
class Solution {
public:
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> indegrees;

    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (int i=0; i<n; ++i) {
            for (int c=0; c<words[i].size(); ++c) {
                graph[words[i][c]] = {};
                indegrees[words[i][c]] = 0;
            }
        }

        /*
        We don't have to iterate two for loops here. Why??
        e.g. A < B < C < D. && A < B and B < C are valid...
        To make the dictionary [A, B, C, D], we only have to know one different part between two words.
        In other words, even if there are another connection, it can be ignored since without it we can still make [A, B, C, D].
        So, additional connections are indirectly included from other conncetions, or it does not affect the answer.
        */
        for (int i=0; i<n-1; ++i) {
            string first = words[i];
            string second = words[i+1];

            // If the first word is longer and first[:second_len] == second -> which is contradiction!
            if (first.size() > second.size() && first.compare(0, second.size(), second) == 0) {
                return "";
            }

            /*
            Here, we can use vectors, since duplicates do not affect the result.
            Since indegrees are also updated repeatedly, it is considered as one branch.
            */
            int minLen = min(first.size(), second.size());
            for (int j=0; j<minLen; ++j) {
                if (first[j] != second[j]) {
                    graph[first[j]].push_back(second[j]);
                    ++indegrees[second[j]];
                    break;
                }
            }
        }

        for (auto iter=graph.begin(); iter!=graph.end(); ++iter) {
            cout<<iter->first<<": ";
            for (int i=0; i<iter->second.size(); ++i) {
                cout<<iter->second[i]<<" ";
            }
            cout<<endl;
        }

        // Starting with the nodes which have indegree == 0.
        queue<char> q;
        for (auto iter=indegrees.begin(); iter!=indegrees.end(); ++iter) {
            if (iter->second == 0) q.push(iter->first);
        }

        string answer;
        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            answer += cur;
            for (int i=0; i<graph[cur].size(); ++i) {
                --indegrees[graph[cur][i]];
                if (indegrees[graph[cur][i]] == 0) q.push(graph[cur][i]);
            }
        }

        // If there is a cycle, the lengths are not the same. A cycle cannot get into the queue since indegree cannot be 0.
        if (answer.size() != graph.size()) return "";

        return answer;
    }
};


int main() {

    int n;
    cin>>n;

    vector<string> words;
    for (int i=0; i<n; ++i) {
        string word;
        getline(cin>>ws, word);
        words.push_back(word);
    }

    Solution* sol = new Solution();
    string answer = sol->alienOrder(words);
    cout<<answer<<"\n";

    return 0;
}
