#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n) space
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* cur = head;
        while(cur != nullptr) {
            values.push_back(cur->val);
            cur = cur->next;
        }

        for (int i=0; i<values.size()/2; ++i) {
            if (values[i] != values[values.size()-i-1]) {
                return false;
            }
        }

        return true;
    }
};

// O(1) space
class Solution2 {
public:
    ListNode* getMid(ListNode* head) {
        int size = 0;
        ListNode* cur = head;
        while (cur) {
            ++size;
            cur = cur->next;
        }
        
        int idx = 0;
        if (size % 2 == 0) {
            idx = size / 2;
        } else {
            idx = size / 2 + 1;
        }
        
        cur = head;
        int curIdx = -1;
        while (cur) {
            ++curIdx;
            if (curIdx == idx) break;
            cur = cur->next;
        }
        
        return cur;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = cur->next;
        while (cur && next) {
            ListNode* nn = next->next;
            next->next = cur;
            cur = next;
            next = nn;
        }
        head->next = nullptr;
        
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        
        ListNode* mid = getMid(head);
        ListNode* rightHalf = reverseList(mid);
        
        ListNode* left = head;
        ListNode* right = rightHalf;
        while (left && right) {
            if (left->val != right->val) return false;
            
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};