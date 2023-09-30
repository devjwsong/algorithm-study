#include <iostream>

using namespace std;


/*
Dynamic Programming.
First, we need to know that the final string should be 1111...000 form.
Thus, the problem is changed into finding how many time it takes to push all 1s to the left side.
By DP, we assume that we have calculated the total seconds to move all 1's in the range [0, i-1].
And we keep tracking the number of zeros.
Now when we reach the ith element and it is 1, there are two cases.
First, if the previous sequence is quite dense and there is another 1 right before the ith element,
the current 1 cannot be moved until the left 1 is moved at least once.
So, it has to wait one more second after the previously calcuated seconds.
On the other hands, if there is 0 in the left side of current 1, the number of steps is bounded by the number of 0s,
since the current element can move right now and eventually there should be numZeros steps to move it to the left.
Time: O(n).
Space: O(1).
*/
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int numZeros = 0, answer = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '0') {
                ++numZeros;
            } else {
                if (numZeros > 0) {
                    answer = max(answer + 1, numZeros);
                }
            }
        }

        return answer;
    }
};
