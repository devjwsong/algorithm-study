#include <iostream>

using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;

        ListNode *result = nullptr;
        ListNode *cur = nullptr;

        while(1) {
            if (cur1 == nullptr && cur2 == nullptr) {
                break;
            } 
            
            if (cur1 == nullptr) {
                if (result == nullptr) {
                    result = cur2;
                } else {
                    cur->next = cur2;
                }
                break;
            } else if (cur2 == nullptr) {
                if (cur == nullptr) {
                    result = cur1;
                } else {
                    cur->next = cur1;
                }
                break;
            }

            ListNode *next = new ListNode();

            if (cur1->val > cur2->val) {
                next->val = cur2->val;
                if (result == nullptr) {
                    result = next;
                    cur = result;
                } else {
                    cur->next = next;
                    cur = next;
                }
                cur2 = cur2->next;
            } else if (cur1->val < cur2->val) {
                next->val = cur1->val;
                if (result == nullptr) {
                    result = next;
                    cur = result;
                } else {
                    cur->next = next;
                    cur = next;
                }
                cur1 = cur1->next;
            } else {
                next->val = cur1->val;
                if (result == nullptr) {
                    result = next;
                    cur = result;
                } else {
                    cur->next = next;
                    cur = next;
                }
                ListNode *add = new ListNode(cur2->val);
                cur->next = add;
                cur = add;

                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }

        return result;
    }
};


int main () {

    int m, n;

    ListNode *list1 = nullptr;
    ListNode *cur = nullptr;
    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        int val = 0;
        scanf(" %d", &val);

        if (list1 == nullptr) {
            list1 = new ListNode(val);
            cur = list1;
        } else {
            ListNode *next = new ListNode(val);
            cur->next = next;
            cur = next;
        }
    }

    ListNode *list2 = nullptr;
    cur = nullptr;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int val = 0;
        scanf(" %d", &val);

        if (list2 == nullptr) {
            list2 = new ListNode(val);
            cur = list2;
        } else {
            ListNode *next = new ListNode(val);
            cur->next = next;
            cur = next;
        }
    }

    Solution *sol = new Solution();
    ListNode *result = sol->mergeTwoLists(list1, list2);

    cur = result;
    while(cur != nullptr) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }

    return 0;
}