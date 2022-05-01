#include <iostream>
#include <vector>

using namespace std;



// O(n) space.
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bool check[10001] = {false};

        for (int i=0; i<n; ++i) {
            check[nums[i]] = true;
        }

        int answer = 0;
        for (int i=0; i<n+1; ++i) {
            if (!check[i]) {
                answer = i;
                break;
            }
        }

        return answer;
    }
};


// O(1) space;
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;

        for (int i=0; i<n; ++i) {
            sum -= nums[i];
        }

        return sum;
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
    int answer = sol1->missingNumber(nums);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->missingNumber(nums);
    printf("%d\n", answer);

    return 0;
}