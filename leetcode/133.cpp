#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


/*
DFS + Hash map.
Note that even if the next value is already cloned, the cloned node should be connected without re-visited.
Time: O(V + E). => Visiting functions V times & Iterating edges E times.
Space: O(V).
*/
class Solution {
public:
    unordered_map<int, Node*> cloned;

    Node* travel(int val, vector<Node*>& neighbors) {
        Node* newNode = new Node(val);
        cloned[val] = newNode;

        for (int i=0; i<neighbors.size(); ++i) {
            Node* next = neighbors[i];
            if (cloned.find(next->val) == cloned.end()) {
                newNode->neighbors.push_back(travel(next->val, next->neighbors));
            } else {
                newNode->neighbors.push_back(cloned[next->val]);
            }
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return node;
        Node* answer = travel(node->val, node->neighbors);

        return answer;
    }
};
