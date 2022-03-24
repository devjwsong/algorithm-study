#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// hash
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i=0; i<nums.size(); ++i) {
            s.insert(nums[i]);
        }

        int answer = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (!s.count(nums[i]-1)) {
                int cur = nums[i];
                int count = 1;

                while(s.count(cur+1)) {
                    ++cur;
                    ++count;
                }

                answer = max(answer, count);
            }
        }

        return answer;
    }
};


// Union-Find
class Solution2 {
public:
    unordered_map<int, int> starts;
    unordered_map<int, int> seqLens;

    int Find(int num) {
        if (starts.find(num) == starts.end()) {
            starts[num] = num;
            return num;
        } else {
            if (starts[num] == num) return num;
            starts[num] = Find(starts[num]);
            return starts[num];
        }
    }

    void Union(int a, int b) {
        int startA = Find(a);
        int startB = Find(b);

        if (startA == startB) return;

        seqLens[startA] += seqLens[startB];
        starts[startB] = startA;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;

        for (int i=0; i<nums.size(); ++i) {
            if (seqLens.find(nums[i]) != seqLens.end()) continue;
            
            seqLens[nums[i]] = 1;
            if (seqLens.find(nums[i]-1) != seqLens.end()) {
                Union(nums[i]-1, nums[i]);
            }
            if (seqLens.find(nums[i]+1) != seqLens.end()) {
                Union(nums[i], nums[i]+1);
            }
        }

        int answer = 0;
        for (auto iter = seqLens.begin(); iter != seqLens.end(); ++iter) {
            answer = max(answer, iter->second);
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
        scanf("%d", &val);
        nums.push_back(val);
    }

    Solution1 *sol1 = new Solution1();
    int answer = sol1->longestConsecutive(nums);
    printf("%d\n", answer);

    Solution2 *sol2 = new Solution2();
    answer = sol2->longestConsecutive(nums);
    printf("%d\n", answer);

    return 0;
}