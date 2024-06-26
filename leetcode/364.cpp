#include <iostream>
#include <vector>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


/*
Recursively, the first DFS gets the maximum depth.
Then, the second DFS calculate the result.
Time: O(N). (N: # of single integers.)
Space: O(1).
*/
class Solution {
public:
    int maxDepth = 0;
    int res = 0;

    void search(vector<NestedInteger> v, int curDepth) {
        int n = v.size();
        for (int i=0; i<n; ++i) {
            maxDepth = max(maxDepth, curDepth);
            if (!v[i].isInteger()) {
                search(v[i].getList(), curDepth+1);
            }
        }
    }

    void calculate(vector<NestedInteger> v, int curDepth) {
        int n = v.size();
        for (int i=0; i<n; ++i) {
            if (v[i].isInteger()) {
                int weight = maxDepth - curDepth + 1;
                res += (weight * v[i].getInteger());
            } else {
                calculate(v[i].getList(), curDepth+1);
            }
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        search(nestedList, 1);
        calculate(nestedList, 1);

        return res;
    }
};
