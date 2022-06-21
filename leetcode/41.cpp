#include <iostream>
#include <vector>

using namespace std;


/*
The idea is to map the integer into indices. (value k -> index k-1)
Since zero and negative values are converted into n+1, they cannot make any difference.
If a positive integer k is found, make the element at index k-1 negative.
Eventually, the index of first positive element indicates the answer.
If all elements are negative, the answer is always n+1.
Why is it? Is there any case that all elements are negative and n+1 is in the array too? -> It is impossible.
If all elements are negative, that means 1 ~ n exist in the array and the size of array is also n.
If n+1 should be in the array, the size of the array should be n+1, which is contradiction.
On the other hand, if n+1 exist, then at least one of the integers from 1 to n does not exist in the array for all numbers to be fit into the array.
In this case, the first missing integer becomes the answer and we can also find it in the third loop.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            if (nums[i] <= 0) nums[i] = n+1;
        }
        
        for (int i=0; i<n; ++i) {
            int absVal = abs(nums[i]);
            if (absVal-1 < n && nums[absVal-1] > 0) {
                nums[absVal-1] *= -1;
            }
        }
        
        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) return i+1;
        }
        return n+1;
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
    int answer = sol->firstMissingPositive(nums);
    printf("%d\n", answer);

    return 0;
}