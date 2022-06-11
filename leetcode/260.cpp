#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            return nums;
        }

        int bits = 0;
        for (int i=0; i<n; ++i) {
            bits ^= nums[i];
        }

        int mask = 1;
        while ((mask & bits) == 0) {
            mask <<= 1;
        }

        /*
        After finding the right most 1, conduct XOR differently according to this digit.
        The numbers included twice will disappear no matter what.
        The purpose of these XOR is to detect different two values which made current bits.
        Since 1 means that two numbers are different in this location first, 
        XOR makes the other value disapeear eventually.
        */
        vector<int> answer = {bits, bits};
        for (int i=0; i<n; ++i) {
            if ((nums[i] & mask) == 0) {
                answer[0] ^= nums[i];
            } else {
                answer[1] ^= nums[i];
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->singleNumber(nums);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}