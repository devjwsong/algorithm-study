#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    unordered_map<int, bool> bits2res;

    /*
    One iteration considers the next player's move.
    Therefore, if the number of 1's is even, (1) considers the next move, which is the first player's.
    And (2) considers the further move starting from the second player's, so if (2) returns false, that means it is success for the first player.
    The opposite case is the same.
    And if all (2)s are true, that means the current state eventually lead to the absolute failure of the first player.
    So the result is set to false.
    */
    bool dfs(int curBits, int maxChoosableInteger, int desiredTotal, int total) {
        if (total < desiredTotal) return false;
        if (bits2res.find(curBits) != bits2res.end()) return bits2res[curBits];

        for (int b=0; b<maxChoosableInteger; ++b) {
            int bit = (1 << b);
            if ((curBits & bit) == 0) {
                if ((b+1) >= desiredTotal) {  // (1)
                    bits2res[curBits] = true;
                    return true;
                }

                if (!dfs(curBits+bit, maxChoosableInteger, desiredTotal-(b+1), total-(b+1))) {  // (2)
                    bits2res[curBits] = true;
                    return true;
                }
            }
        }
        bits2res[curBits] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true; 
        
        int bits = 0;
        return dfs(bits, maxChoosableInteger, desiredTotal, maxChoosableInteger*(maxChoosableInteger+1)/2);
    }
};


int main() {

    int maxChooseableInteger, desiredTotal;
    scanf("%d %d", &maxChooseableInteger, &desiredTotal);

    Solution* sol = new Solution();
    bool answer = sol->canIWin(maxChooseableInteger, desiredTotal);
    printf("%d\n", answer);

    return 0;
}