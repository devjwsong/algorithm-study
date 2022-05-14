#include <iostream>
#include <vector>

using namespace std;

// O(NlogN)
class Solution1 {
public:
    int findVal(vector<int>& numbers, int val, int left, int right) {
        int n = numbers.size();
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] == val) {
                return mid;
            } else if (numbers[mid] > val) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (numbers[left] == val) return left;
        if (numbers[right] == val) return right;
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        for (int i=0; i<numbers.size(); ++i) {
            int idx = findVal(numbers, target-numbers[i], i+1, numbers.size()-1);
            if (idx != -1) {
                answer.push_back(i+1);
                answer.push_back(idx+1);
                break;
            }
        }

        return answer;
    }
};


// O(N)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left + 1 < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            }
            
            if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
        
        answer.push_back(left+1);
        answer.push_back(right+1);
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> numbers;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        numbers.push_back(val);
    }

    int target;
    scanf("%d", &target);

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->twoSum(numbers, target);
    printf("%d %d\n", answer[0], answer[1]);

    Solution2* sol2 = new Solution2();
    answer = sol2->twoSum(numbers, target);
    printf("%d %d\n", answer[0], answer[1]);

    return 0;
}