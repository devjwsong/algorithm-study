#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


/*
Hash map + Priority Queue + Greedy.
We use the priority queue to get the character which has the maximum number of occurrences.
This will minimize the chance of getting the same character consecutively.
After fetching the top, we do not re-push it because it might be able to be popped for the right next character.
So we copy the character into another variable for later use.
One case hard to catch is when the iteration is finished even if the answer is not completed.
This means that without using the current prevChar, we cannot finish the answer.
And the current prevChar actually came from the last popped character, which should be identical to the last character of the answer, which is repetitive.
Time: O(nlogn).
Space: O(n).
*/
class Solution1 {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for (int i=0; i<n; ++i) {
            ++mp[s[i]];
        }
        for (char c='a'; c<='z'; ++c) {
            if (mp.find(c) != mp.end()) {
                pq.push({mp[c], c});
            }
        }

        string answer;
        int prevNum = -1;
        char prevChar = '\0';
        while (!pq.empty()) {
            pair<int, char> cur = pq.top();
            pq.pop();
            if (answer.size() == 0 || answer.back() != cur.second) {
                answer.push_back(cur.second);
                if (prevNum > 0) {
                    pq.push({prevNum, prevChar});
                }
                if (cur.first > 1) {
                    prevNum = cur.first-1;
                    prevChar = cur.second;
                } else {
                    prevNum = -1;
                    prevChar = '\0';
                }
            } else {
                return "";
            }
        }

        if (answer.size() < n) return "";
        return answer;
    }
};


/*
Hash map + Greedy.
In this way, we fill the characters which has the larger number of occurences first,
by placing them into the non-adjacent indices.
So first, we fill 0, 2, 4, ... with the maximum appearing character.
Next we fill other character by avoiding placing any same character to the consecutive spots.
Why should we only think about the maximum character for the failing condition?
If the maximum character can fill all even indices, no matter how other characters occur, it cannot fail.
If the maximum character (x) fails to do so, a certain other character (y) will be placed into the rest of even indices.
Then the only scenarios that can fail is y has filled 1, 3, 5, ...., which is odd indices,
and finally reaches the point right adjacent to the same y.
But this is contradiction, because in order to do that, the maximum character cannot be x, since the number of ys should be larger than that of xs.
Time: O(n).
Space: O(n).
*/
class Solution2 {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> letters (26, 0);
        for (int i=0; i<n; ++i) {
            ++letters[s[i]-'a'];
        }

        int maxNum = 0, charIdx = 0;
        for (char c='a'; c<='z'; ++c) {
            if (letters[c-'a'] > maxNum) {
                maxNum = letters[c-'a'];
                charIdx = c-'a';
            }
        }

        if (maxNum > (n + 1) / 2) {
            return "";
        }

        string answer (n, '\0');
        int idx = 0;
        while (letters[charIdx] > 0) {
            answer[idx] = charIdx + 'a';
            --letters[charIdx];
            idx += 2;
        }

        for (char c='a'; c<='z'; ++c) {
            while (letters[c-'a'] > 0) {
                if (idx >= n) idx = 1;
                answer[idx] = c;
                --letters[c-'a'];
                idx += 2;
            }
        }

        return answer;
    }
};
