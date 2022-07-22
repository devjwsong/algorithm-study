#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Segment Tree: O(NlogM).
Since we only want to check the smaller elements right to each certain target element,
pushing/updating and querying should be conducted simultaneously.
The details of segment tree is explained in https://songstudio.info/tech/tech-11.
*/
class Solution1 {
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


/*
Another version: Same with the problem 327.
More intuitive, but array version is much more faster.
*/
class Solution2 {
public:
    struct Node {
        int max;
        int min;
        int count;
        Node* left;
        Node* right;

        Node(int min, int max, int count) {
            this->min = min;
            this->max = max;
            this->count = count;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* build(vector<int>& nums, int start, int end) {
        Node* root = new Node(nums[start], nums[end], 0);
        if (start == end) return root;

        int mid = (start + end) / 2;
        root->left = build(nums, start, mid);
        root->right = build(nums, mid+1, end);
        return root;
    }

    void update(Node* root, int val) {
        if (!root || root->max < val || root->min > val) return;
        ++root->count;
        if (root->left && root->left->max >= val) {
            update(root->left, val);
        } else  {
            update(root->right, val);
        }
    }

    int query(Node* root, int min, int max) {
        if (!root || root->max < min || root->min > max) return 0;
        if (min <= root->min && max >= root->max) return root->count;
        return query(root->left, min, max) + query(root->right, min, max);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> cpy = nums;
        sort(cpy.begin(), cpy.end());

        Node* root = build(cpy, 0, n-1);
        vector<int> answer (n, 0);
        for (int i=n-1; i>=0; --i) {
            answer[i] = query(root, cpy[0], nums[i]-1);
            update(root, nums[i]);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums1;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums1.push_back(val);
    }
    vector<int> nums2 = nums1;

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->countSmaller(nums1);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    Solution2* sol2 = new Solution2();
    answer = sol2->countSmaller(nums2);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");


    return 0;
}