#include <iostream>
#include <vector>

using namespace std;


// O(n) space.
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ascProds (n, 1);
        vector<int> decProds (n, 1);
        for (int i=0; i<n; ++i) {
            if (i == 0) {
                ascProds[i] = nums[i];
            } else {
                ascProds[i] = ascProds[i-1] * nums[i];
            }
        }

        for (int i=n-1; i>=0; --i) {
            if (i == n-1) {
                decProds[i] = nums[i];
            } else {
                decProds[i] = decProds[i+1] * nums[i];
            }
        }

        vector<int> answer;
        for (int i=0; i<n; ++i) {
            if (i == 0) {
                answer.push_back(decProds[i+1]);
            } else if (i == n-1) {
                answer.push_back(ascProds[i-1]);
            } else {
                answer.push_back(ascProds[i-1] * decProds[i+1]);
            }
        }

        return answer;
    }
};


// O(1) space.
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;

        answer.push_back(nums[0]);
        for (int i=1; i<n; ++i) {
            answer.push_back(answer[i-1] * nums[i]);
        }

        int prod = 1;
        for (int i=n-1; i>=1; --i) {
            answer[i] = answer[i-1] * prod;
            prod *= nums[i];
        }
        answer[0] = prod;

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

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->productExceptSelf(nums);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2* sol2 = new Solution2();
    answer = sol2->productExceptSelf(nums);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}