#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution1 {
public:
    map<int, int> counts;

    int majorityElement(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            if (counts.find(nums[i]) == counts.end()) {
                counts[nums[i]] = 0;
            }
            counts[nums[i]] += 1;
        }

        int numMajor = 0;
        if (nums.size() % 2 == 0) {
            numMajor = nums.size() / 2;
        } else {
            numMajor = nums.size() / 2 + 1;
        }

        int answer = 0;
        for (auto iter=counts.begin(); iter != counts.end(); ++iter) {
            if (iter->second >= numMajor) {
                answer = iter->first;
            }
        }

        return answer;
    }
};

// Moore's voting algorithm
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != major) {
                --count;

                if (count == 0) {
                    major = nums[i];
                    count = 1;
                }
            } else {
                ++count;
            }
        }

        return major;
    }
};


int main () {
    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution1 *sol1 = new Solution1();
    int answer = sol1->majorityElement(nums);
    printf("%d\n", answer);

    
    Solution2 *sol2 = new Solution2();
    answer = sol2->majorityElement(nums);
    printf("%d\n", answer);

    return 0;
}