#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/*
Using two lists.
Time: O(n).
Space: O(n).
*/
class Solution1 {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> numLeftOnes (n, 0);
        vector<int> numRightZeros (n, 0);

        if (s[0] == '1') numLeftOnes[0] = 1;
        for (int i=1; i<n; ++i) {
            numLeftOnes[i] = numLeftOnes[i-1];
            if (s[i] == '1') numLeftOnes[i] += 1;
        }

        if (s[n-1] == '0') numRightZeros[n-1] = 1;
        for (int i=n-2; i>=0; --i) {
            numRightZeros[i] = numRightZeros[i+1];
            if (s[i] == '0') numRightZeros[i] += 1;
        }

        if (numRightZeros[0] == 0 || numLeftOnes[n-1] == 0) return 0;

        int answer = INT_MAX;
        for (int i=0; i<n; ++i) {
            answer = min(answer, numLeftOnes[i] + max(numRightZeros[i]-1, 0));
        }

        return answer;
    }
};


/*
With constant space.
Time: O(n).
Space: O(1).
The variable countFlipOnes contains the number of 1s which has been flipped to 0.
On the other hands, answer counts the number of 0s so far.
So answer keeps track of number of 0s to keep for making the number as monotone increasing.
If countFlipOnes is smaller, this means two cases:
answer already has the minimum number of 1s to flip into 0 which is from countFlipOnes before.
or answer keeps the number of 0s to flip into 1 which will become a new part of right 1's part 
forgetting other 0's which are located in the left part.
*/
class Solution2 {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int answer = 0, countFlipOnes = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '1') {
                ++countFlipOnes;
            } else {
                ++answer;
            }

            answer = min(answer, countFlipOnes);
        }

        return answer;
    }
};
