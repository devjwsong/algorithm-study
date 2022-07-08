#include <iostream>
#include <vector>

using namespace std;


/*
Segment Tree: O(NlogM).
Since we only want to check the smaller elements right to each certain target element,
pushing/updating and querying should be conducted simultaneously.
The details of segment tree is explained in https://songstudio.info/tech/tech-11.
*/
class Solution {
public:
    void update(vector<int>& tree, int leaf) {
        int index = leaf/2;
        while(true) {
            tree[index] = tree[index*2] + tree[index*2+1]; 

            if (index <= 1) {
                break;
            }

            index /= 2;
        }
    }
    
    int query(vector<int>& tree, int power, int left, int right) {
        if (left > right) return 0;
        
        int sum = 0;
        left += (power-1);
        right += (power-1);
        
        while(true) {
            if (left == right) break;
            
            if (left % 2 == 1) {
                sum += tree[left];
                ++left;
            }
            
            if (right % 2 == 0) {
                sum += tree[right];
                --right;
            }
            
            left /= 2;
            right /= 2;
        }
        
        sum += tree[left];
        
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for (int i=0; i<n; ++i) {
            nums[i] += (1e4 + 1);
            m = max(m, nums[i]);
        }
        
        int power = 1;
        while (power < m) {
            power *= 2;
        }
        vector<int> tree (power*2, 0);
        
        vector<int> answer (n, 0);
        for (int i=n-1; i>=0; --i) {
            ++tree[power + nums[i]-1];
            update(tree, power + nums[i]-1);
            answer[i] = query(tree, power, 1, nums[i]-1);
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

    Solution* sol = new Solution();
    vector<int> answer = sol->countSmaller(nums);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}