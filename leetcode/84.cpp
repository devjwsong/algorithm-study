#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


/*
Using monotonic stack -> O(N): The reason is explained in the proiblem 456.
The idea is that getting maximum areas according to each height.
To do this, the vector lefts and rights contains the next smaller height than index i.
So, (rights[i] - lefts[i] - 1) becomes the maxmimum width,
since if the range exceeds, we should lower the height.
And this case will be calculated at other iterations, so we do not consider as other maximum area at certain index position.
*/
class Solution {
public:
    vector<int> getLefts(vector<int>& h) {
        vector<int> lefts;
        stack<pair<int, int>> st;
        for (int i=0; i<h.size(); ++i) {
            if (st.empty()) {
                lefts.push_back(-1);
            } else if (st.top().first < h[i]) {
                lefts.push_back(st.top().second);
            } else {
                while (!st.empty() && st.top().first >= h[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    lefts.push_back(-1);
                } else {
                    lefts.push_back(st.top().second);
                }
            }
            st.push({h[i], i});
        }
        
        return lefts;
    }
    
    vector<int> getRights(vector<int>& h) {
        int n = h.size();
        vector<int> rights;
        stack<pair<int, int>> st;
        for (int i=h.size()-1; i>=0; --i) {
            if (st.empty()) {
                rights.push_back(n);
            } else if (st.top().first < h[i]) {
                rights.push_back(st.top().second);
            } else {
                while (!st.empty() && st.top().first >= h[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    rights.push_back(n);
                } else {
                    rights.push_back(st.top().second);
                }
            }
            st.push({h[i], i});
        }
        reverse(rights.begin(), rights.end());
        
        return rights;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> lefts = getLefts(heights);
        vector<int> rights = getRights(heights);
        
        int answer = 0;
        for (int i=0; i<heights.size(); ++i) {
            int width = rights[i] - lefts[i] - 1;
            answer = max(answer, width * heights[i]);
        }
        
        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> heights;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        heights.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->largestRectangleArea(heights);
    printf("%d\n", answer);

    return 0;
}