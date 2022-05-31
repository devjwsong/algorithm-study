#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    vector<int> flattened;
    int idx;

    void flatten(vector<NestedInteger> &nestedList) {
        for (int i=0; i<nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                flattened.push_back(nestedList[i].getInteger());
            } else {
                vector<NestedInteger> v = nestedList[i].getList();
                flatten(v);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        idx = 0;
    }
    
    int next() {
        int res = flattened[idx];
        ++idx;
        return res;
    }
    
    bool hasNext() {
        return idx < flattened.size();
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */