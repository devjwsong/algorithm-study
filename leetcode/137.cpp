#include <iostream>
#include <vector>

using namespace std;


/*
Bit manipulation.
If the count can be divided by 3, that means the current bit has been counted 3*k times.
So thses counts belong to the numbers which appear 3 times.
If it cannot be, then one bit came from the number which appears only one time.
So we should keep it.
Time: O(n).
Space: O(1).
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();

        for (int b=0; b<32; ++b) {
            int count = 0;
            for (int i=0; i<n; ++i) {
                if (nums[i] & (1 << b)) {
                    ++count;
                }
            }

            if (count % 3 > 0) {
                answer |= (1 << b);
            }
        }

        return answer;
    }
};
