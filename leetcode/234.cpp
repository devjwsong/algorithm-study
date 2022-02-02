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
        int num = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            ++num;
            cur = cur->next;
        }

        int mid_idx = -1;
        if (num % 2 == 0) {
            mid_idx = num / 2;
        } else {
            mid_idx = num / 2 + 1;
        }

        int count = 0;
        cur = head;
        while(cur != nullptr) {
            if (count == mid_idx) {
                return cur;
            }
            cur = cur->next;
            count += 1;
        }

        return cur;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head->next;
        cur->next = nullptr;
        while(cur != nullptr && next != nullptr) {
            ListNode* furtherNext = next->next;
            next->next = cur;
            cur = next;
            next = furtherNext;
        }

        return cur;
    }

    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) {
            return true;
        }

        ListNode* mid = getMid(head);
        ListNode* reversedHalf = reverseList(mid);

        while(1) {
            if (head->val != reversedHalf->val) {
                return false;
            }

            if (reversedHalf == mid) {
                break;
            }

            head = head->next;
            reversedHalf = reversedHalf->next;
        }
        
        return true;
    }
};