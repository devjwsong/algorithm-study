#include <iostream>
#include <vector>

using namespace std;


// Trie + Bit manipulation.
class Solution {
public:
    struct Node {
        Node* nodes[2];
        Node() {
            nodes[0] = nullptr;
            nodes[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int val) {
        Node* cur = root;
        for (int b=31; b>=0; --b) {
            int bit = (val >> b) & 1;
            if (cur->nodes[bit] == nullptr) {
                cur->nodes[bit] = new Node();
            }
            cur = cur->nodes[bit];
        }
    }

    int findXor(int val) {
        Node* cur = root;
        int res = 0;
        for (int b=31; b>=0; --b) {
            int bit = (val >> b) & 1;
            if (cur->nodes[1-bit] != nullptr) {
                res += (1 << b);
                cur = cur->nodes[1-bit];
            } else {    
                cur = cur->nodes[bit];
            }
        }

        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; ++i) {
            insert(nums[i]);
        }

        int answer = 0;
        for (int i=0; i<n; ++i) {
            answer = max(answer, findXor(nums[i]));
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
    int answer = sol->findMaximumXOR(nums);
    printf("%d\n", answer);

    return 0;
}