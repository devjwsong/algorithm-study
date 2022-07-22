#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
This is another (actually more visually intuitive) implementation of segment tree.
Since it is actually built as a tree, there is no need to make an array as 2^n size.
*/
class Node {
public:
    long long min;
    long long max;
    int count;
    Node* left;
    Node* right;

    Node(long long min, long long max, int count) {
        this->min = min;
        this->max = max;
        this->count = count;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
public:
    Node* root;

    Node* build(vector<long long>& pSums, int start, int end) {
        Node* root = new Node(pSums[start], pSums[end], 0);
        if (start == end) {
            return root;
        } else {
            int mid = (start + end) / 2;
            root->left = build(pSums, start, mid);
            root->right = build(pSums, mid+1, end);
            return root;
        }
    }

    void update(Node* root, long long val) {
        if (root == nullptr || val < root->min || val > root->max) return;
        ++root->count;
        if (root->left && root->left->max >= val) {
            update(root->left, val);
        } else {
            update(root->right, val);
        }
    }

    int query(Node* root, long long min, long long max) {
        if (root == nullptr || root->max < min || root->min > max) return 0;
        if (min <= root->min && max >= root->max) return root->count;
        return query(root->left, min, max) + query(root->right, min, max);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> pSums (n+1, 0);
        for (int i=0; i<n; ++i) {
            pSums[i+1] = pSums[i] + nums[i];
        }
        vector<long long> cpy = pSums;
        sort(cpy.begin(), cpy.end());
        root = build(cpy, 0, n);

        int answer = 0;
        update(root, pSums[0]);
        for (int i=0; i<n; ++i) {
            answer += query(root, pSums[i+1]-upper, pSums[i+1]-lower);
            update(root, pSums[i+1]);
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

    int lower, upper;
    scanf("%d %d", &lower, &upper);

    Solution* sol = new Solution();
    int answer = sol->countRangeSum(nums, lower, upper);
    printf("%d\n", answer);

    return 0;
}