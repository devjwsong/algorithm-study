#include <iostream>
#include <vector>

using namespace std;


class Solution1 {
public:
    vector<int> findPartialRange(vector<int>& nums, int left, int right, int target) {
        if (left + 1 == right) {
            if (nums[left] == target) {
                return vector<int> {left, left};
            } else {
                return vector<int> {-1, -1};
            }
        }

        int mid = (left + right) / 2;
        vector<int> leftPart = findPartialRange(nums, left, mid, target);
        vector<int> rightPart = findPartialRange(nums, mid, right, target);

        if (leftPart[0] == -1 && rightPart[0] == -1) {
            return vector<int> {-1, -1};
        } else if (leftPart[0] != -1 && rightPart[0] == -1) {
            return leftPart;
        } else if (leftPart[0] == -1 && rightPart[0] != -1) {
            return rightPart;
        } else {
            return vector<int> {leftPart[0], rightPart[rightPart.size()-1]};
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> {-1, -1};
        }

        return findPartialRange(nums, 0, nums.size(), target);
    }
};

// More efficient
class Solution2 {
public:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid-1] != target) {
                    return mid;
                }

                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (nums[left] == target) return left;
        return -1;
    }

    int findLast(vector<int>& nums, int target) {
        int left = -1, right = nums.size()-1;
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size()-1 || nums[mid+1] != target) {
                    return mid;
                }

                left = mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else  {
                left = mid;
            }
        }

        if (nums[right] == target) return right;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> {-1, -1};
        }
        
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return vector<int> {first, last};
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

    int target;
    scanf("%d", &target);

    Solution1 *sol1 = new Solution1();
    vector<int> answer = sol1->searchRange(nums, target);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2 *sol2 = new Solution2();
    answer = sol2->searchRange(nums, target);

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}