#include <iostream>
#include <vector>

using namespace std;


/*
Trie + DFS(Backtracking).
*/
class Solution {
public:
    struct Node {
        char cur;
        bool isEnd;  // For checking duplication.
        vector<Node*> nexts;

        Node(char c) {
            cur = c;
            isEnd = false;
            nexts.assign(26, nullptr);
        }
    };

    Node* root = new Node('@');
    vector<string> answer;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};

    bool isValid(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void insertWord(string word) {
        Node* cur = root;
        for (int i=0; i<word.size(); ++i) {
            if (cur->nexts[word[i]-'a'] == nullptr) {
                Node* next = new Node(word[i]);
                cur->nexts[word[i]-'a'] = next;
            }
            cur = cur->nexts[word[i]-'a'];
        }
        cur->isEnd = true;
    }

    void search(vector<vector<char>>& board, string& curStr, Node* curNode, int r, int c) {
        if (curNode && curNode->isEnd) {
            answer.push_back(curStr);
            curNode->isEnd = false;
        }

        if (!isValid(board.size(), board[0].size(), r, c) || board[r][c] == '-' || !curNode) return;
        if (!curNode->nexts[board[r][c]-'a']) return;
        
        char val = board[r][c];
        board[r][c] = '-';
        curStr.push_back(val);

        for (int d=0; d<4; ++d) {
            search(board, curStr, curNode->nexts[val-'a'], r + rowDirs[d], c + colDirs[d]);
        }

        curStr.pop_back();
        board[r][c] = val;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i=0; i<words.size(); ++i) {
            insertWord(words[i]);
        }

        for (int r=0; r<board.size(); ++r) {
            for (int c=0; c<board[r].size(); ++c) {
                string curStr;
                search(board, curStr, root, r, c);
            }
        }

        return answer;
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);
    
    vector<vector<char>> board;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        board.push_back(row);
    }

    int s;
    scanf("%d", &s);
    getchar();
    
    vector<string> words;
    for (int i=0; i<s; ++i) {
        string word;
        getline(cin, word);
        words.push_back(word);
    }

    Solution* sol = new Solution();
    vector<string> answer = sol->findWords(board, words);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}