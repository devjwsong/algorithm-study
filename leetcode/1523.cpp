#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if (low == high) {
            if (low % 2 == 1) return 1;
            return 0;
        }

        if (low + 1 == high) {
            return 1;
        }

        if (low % 2 == 1 && high % 2 == 1) {
            return 2 + (high-low-1) / 2;
        } else if (low % 2 == 0 && high % 2 == 0) {
            return countOdds(low+1, high-1);
        } else if (low % 2 == 1 && high % 2 == 0) {
            return countOdds(low, high-1);
        } else {
            return countOdds(low+1, high);
        }
    }
};