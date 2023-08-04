#include <iostream>

using namespace std;


/*
Greedy + Two pointers.
The conditions is that every left bracket has the paired right bracket.
And if the string is balanced, at least the number of left brackets should be larger than that of right brackets.
So if the balance of the numbers becomes broken, we conduct the swap.
For this, we track the right most right bracket using another pointer.
Time: O(n).
Space: O(1).
*/
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int left = 0, right = n-1;
        int answer = 0;
        int numBalanced = 0;
        while (left < n) {
            if (s[left] == '[') {
                ++numBalanced;
            } else {
                --numBalanced;
                if (numBalanced < 0) {
                    while (s[right] == ']') --right;
                    swap(s[left], s[right]);
                    ++answer;
                    numBalanced = 1;
                }
            }
            ++left;
        }

        return answer;
    }
};
