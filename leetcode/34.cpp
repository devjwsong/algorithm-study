#include <iostream>
#include <vector>

using namespace std;


/*
Divide & Conquer.
Time: O(logn).
Space: O(nlogn).
*/
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
            return {leftPart[0], rightPart[1]};
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }

        return findPartialRange(nums, 0, nums.size(), target);
    }
};


/*
Binary Search.
Time: O(logn).
Space: O(1).
*/
class Solution2 {
public:
    int findFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid > 0 && nums[mid-1] == target) {
                    right = mid;
                } else {
                    return mid;
                }
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            }
        }

        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }

    int findLast(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid < n-1 && nums[mid+1] == target) {
                    left = mid;
                } else {
                    return mid;
                }
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            }
        }

        if (nums[right] == target) return right;
        if (nums[left] == target) return left;
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