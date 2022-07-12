#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


/*
Dynamic Programming.
Time: O(m*n)
Space: O(n)
The idea is a little bit complicated.
First, the vector heights contains the maximum height of index i.
And lefts has the farthest left index which has the same or higher height of the index i.
Likewise, rights has the farthest right indext that has the same or higher height of the index i.
Then the maximum area made at the index i is (rights[i]-lefts[i]+1) * heights[i].
*/
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights (n, 0);
        vector<int> lefts (n, 0);
        vector<int> rights (n, n-1);
        int answer = 0;
        
        for (int r=0; r<m; ++r) {
            int leftWall = 0, rightWall = n-1;
            
            for (int c=0; c<n; ++c) {
                if (matrix[r][c] == '1') {
                    ++heights[c];
                } else {
                    heights[c] = 0;
                }
            }
            
            /* 
            This is tricky part!
            If matrix[r][c] = 0, obviously lefts[c] = 0.
            If matrix[r][c] = 1, then there are two cases, either the above value is 1 or 0.
            If the latter is true, then lefts[c] has been 0 and now lefts[c] is updated into the current boundary.
            If the former is true, then previous lefts[c] already has the farthest left index.
            Since now the current 1 is connected to the previous one, the value is inherited.
            */
            for (int c=0; c<n; ++c) {
                if (matrix[r][c] == '1') {
                    lefts[c] = max(lefts[c], leftWall);
                } else {
                    lefts[c] = 0;
                    leftWall = c+1;
                }
            }
            
            for (int c=n-1; c>=0; --c) {
                if (matrix[r][c] == '1') {
                    rights[c] = min(rights[c], rightWall);
                } else {
                    rights[c] = n-1;
                    rightWall = c-1;
                }
            }
            
            for (int c=0; c<n; ++c) {
                answer = max(answer, heights[c] * (rights[c]-lefts[c]+1));
            }
        }
        
        return answer;
    }
};


/*
Monotonic stack.
Time: O(m*n)
Space: O(m*n)
Actually, this is almost same as the problem 84.
The only difference is that the condition of this problem has mutliple rows.
*/
class Solution2 {
public:
    vector<int> makeLefts(vector<int>& heights) {
        vector<int> lefts;
        stack<int> st;
        int n = heights.size();
        for (int i=0; i<n; ++i) {
            if (st.empty()) {
                lefts.push_back(-1);
            } else if (heights[st.top()] < heights[i]) {
                lefts.push_back(st.top());
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    lefts.push_back(-1);
                } else {
                    lefts.push_back(st.top());
                }
            }
            st.push(i);
        }
        
        return lefts;
    }
    
    vector<int> makeRights(vector<int>& heights) {
        vector<int> rights;
        stack<int> st;
        int n = heights.size();
        for (int i=n-1; i>=0; --i) {
            if (st.empty()) {
                rights.push_back(n);
            } else if (heights[st.top()] < heights[i]) {
                rights.push_back(st.top());
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    rights.push_back(n);
                } else {
                    rights.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(rights.begin(), rights.end());
        
        return rights;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> lefts = makeLefts(heights);
        vector<int> rights = makeRights(heights);
        
        int res = 0;
        for (int i=0; i<heights.size(); ++i) {
            res = max(res, heights[i] * (rights[i]-lefts[i]-1));
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> heights (m, vector<int> (n, 0));
        for (int c=0; c<n; ++c) {
            if (matrix[0][c] == '1') heights[0][c] = 1;
        }
        for (int r=1; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (matrix[r][c] == '1') {
                    heights[r][c] = heights[r-1][c] + 1;
                } else {
                    heights[r][c] = 0;
                }
            }
        }
        
        int answer = 0;
        for (int r=0; r<m; ++r) {
            answer = max(answer, largestRectangleArea(heights[r]));
        }
        
        return answer;
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<char>> matrix;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    Solution1* sol1 = new Solution1();
    int answer = sol1->maximalRectangle(matrix);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->maximalRectangle(matrix);
    printf("%d\n", answer);

    return 0;
}
