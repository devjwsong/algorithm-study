#include <iostream>
#include <vector>

using namespace std;


/*
DFS + Backtracking.
There are 3 branches for each index.
1) Selecting s[i] as the next character for s1.
2) Selecting s[1] as the next character for s2.
3) Not selecting s[i].
Time: O(3^n).
Space: O(n).
*/
class Solution1 {
public:
    int answer = 0;
    string s1, s2;

    bool isPalindrome(string& ss) {
        int m = ss.size();
        for (int i=0; i<m/2; ++i) {
            if (ss[i] != ss[m-1-i]) return false;
        }

        return true;
    }

    void search(string& s, int idx) {
        int n = s.size();
        if (idx == n) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                answer = max(answer, (int) s1.size() * (int) s2.size());
            }
            return;
        }

        s1 += s[idx];
        search(s, idx+1);
        s1.pop_back();

        s2 += s[idx];
        search(s, idx+1);
        s2.pop_back();
        
        search(s, idx+1);
    }

    int maxProduct(string s) {
        search(s, 0);
        return answer;
    }
};


/*
Dynamic Programming + Bitmasking.
First, we calculate the length of each possible palindrome.
The point here is each subsequence is represented as bits.
If a certain integer is not a palindrome, the length will be 0.
Then we iterate the dp vector to multiply the lengths of two sequences.
Obviously, two sequences should be disjoint.
A small tip here is when iterating bits2, we don't have to check all bits2,
and taking only disjoint bits2 will increase the efficiency.
Time: O(4^n).
Space: O(2^n).
*/
class Solution2 {
public:
    int getLen(string& s, int bits) {
        int n = s.size();
        int res = 0;
        int i = 0, j = n-1;
        while (i <= j) {
            if ((bits & (1 << (n-1-i))) == 0) {
                ++i;
            } else if ((bits & (1 << (n-1-j))) == 0) {
                --j;
            } else if  (s[i] != s[j]) {
                return 0;
            } else {
                if (i != j) {
                    res += 2;
                } else {
                    ++res;
                }
                ++i;
                --j;
            }
        }
        return res;
    }

    int maxProduct(string s) {
        int n = s.size();
        int maxNum = (1 << n)-1;
        vector<int> lens (maxNum+1, 0);
        for (int bits=1; bits<=maxNum; ++bits) {
            lens[bits] = getLen(s, bits);
        }

        int answer = 0;
        for (int bits1=1; bits1<=maxNum; ++bits1) {
            if (lens[bits1] * (n - lens[bits1]) > answer) {
                for (int bits2=(maxNum ^ bits1); bits2 > 0; bits2 = (bits2-1) & (maxNum ^ bits1)) {
                    answer = max(answer, lens[bits1] * lens[bits2]);
                }
            }
        }

        return answer;
    }
};
