#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;

        ListNode* cur = head;
        while(cur != nullptr) {
            if (visited.find(cur) == visited.end()) {
                visited[cur] = true;
                cur = cur->next;
            } else {
                return true;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* rabbit = head;
        ListNode* turtle = head;

        while (rabbit != nullptr && rabbit->next != nullptr) {
            turtle = turtle->next;
            rabbit = rabbit->next->next;

            if (rabbit == turtle) {
                return true;
            }
        }

        return false;
    }
};


class Solution2 {
public:
    bool hasCycle(ListNode *head) {

    }
};
