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


// Space: O(n).
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


/*
Floyd's Tortoise & Hare algorithm.
Space: O(1).
The prove is well explained in https://fierycoding.tistory.com/45.
Also, after the tortoise and hare meets, the first point where they meet again 
after sending the tortoise to the head and making the hare move one step at a time
becomes the starting point of the cycle.
*/
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            
            if (tortoise == hare) return true;
        }
        
        return false;
    }
};
