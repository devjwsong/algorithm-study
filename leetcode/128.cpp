#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
Hash table.
The reason why this runs in O(n) is because eventually while loop is executed only n times.
In other words, if nums[i] is not the first element of a certain consecutive array,
it will be ignored.
On the other hand, if nums[i] is the first element, it will run through the consecutive elements.
So eventually, the while loop's time complexity is another O(n).
Time: O(n).
Space: O(n).
*/
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


/*
Union-Find.
Union updates the relation between the number k and k+1.
=> mp[k+1] = k.
Find find the root of the relation, which is the smallest number among the consecutive sequence.
Note that mp[k] might not be the smallest value, because compression is not guaranteed to be the "real" root.
Time: O(n). (roughly... with compression)
Space: O(n).
*/
class Solution2 {
public:
    unordered_map<int, int> mp;

    int Find(int target) {
        if (mp[target] == target) return target;
        mp[target] = Find(mp[target]);
        return mp[target];
    }

    void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);

        mp[rootB] = rootA;
    } 

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            mp[nums[i]] = nums[i];
        }

        for (int i=0; i<n; ++i) {
            if (mp.find(nums[i]-1) != mp.end()) {
                Union(nums[i]-1, nums[i]);
            }
        }

        int answer = 0;
        for (unordered_map<int, int>::iterator i=mp.begin(); i!=mp.end(); ++i) {
            answer = max(answer, i->first - Find(i->first) + 1);
        }

        return answer;
    }
};
