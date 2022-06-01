#include <iostream>
#include <vector>
#include <random>

using namespace std;


// Knuth Shuffle: Improved Fisher-Yates shuffle algorithm: O(n).
class Solution {
private:
    vector<int> init;
    vector<int> rands;

public:
    Solution(vector<int>& nums) {
        init = nums;
        rands = nums;
    }
    
    vector<int> reset() {
        return init;
    }
    
    vector<int> shuffle() {
        int n = init.size();
        for (int i=0; i<n; ++i) {
            int idx = i + (rand() % (n-i));
            swap(rands[i], rands[idx]);
        }

        return rands;
    }
};