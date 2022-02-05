#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// O(n) space
class Solution1 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, bool> check;
        for (int i=0; i<nums.size(); ++i) {
            check[nums[i]] = true;
        }

        vector<int> answer;
        for (int i=1; i<=nums.size(); ++i) {
            if (check.find(i) == check.end()) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};

// Without extra space
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
        }

        vector<int> answer;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) {
                answer.push_back(i+1);
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

    Solution1 *sol1 = new Solution1();
    vector<int> answer = sol1->findDisappearedNumbers(nums);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2 *sol2 = new Solution2();
    answer = sol2->findDisappearedNumbers(nums);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}