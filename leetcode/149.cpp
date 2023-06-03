#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;


// Naive solution: O(N^3)
class Solution1 {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int answer = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                if (j == i) {
                    answer = max(answer, 1);
                    continue;
                }

                int a = points[i][1] - points[j][1];
                int b = points[i][0] * points[j][1] - points[j][0] * points[i][1];
                int c = points[i][0] - points[j][0];

                int num = 0;
                for (int k=0; k<n; ++k) {
                    if (c != 0) {
                        int numerator = a * points[k][0] + b;
                        if (numerator % c == 0 && numerator / c == points[k][1]) {
                            ++num;
                        }
                    } else {
                        if (points[k][0] == points[i][0]) ++num;
                    }
                }
                answer = max(answer, num);
            }
        }

        return answer;
    }
};


/*
Hash map: O(N^2)
Expressing the gradient as a double variable works!
And for simplicity, fixing one point and calculating the gradient to other points is useful,
since there is no need to consider the y-intercept.
*/
class Solution2 {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int answer = 1;
        for (int i=0; i<n; ++i) {
            vector<int> p1 = points[i];
            unordered_map<double, int> mp;

            for (int j=i+1; j<n; ++j) {
                vector<int> p2 = points[j];

                if (p2[0] == p1[0]) {
                    ++mp[INT_MAX];
                } else {
                    double slope = (double) (p2[1] - p1[1]) / (double) (p2[0] - p1[0]);
                    ++mp[slope];
                }
            }

            for (unordered_map<double, int>::iterator i=mp.begin(); i != mp.end(); ++i) {
                answer = max(answer, i->second+1);
            }
        }

        return answer;
    }
};

int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int>> points;
    for (int i=0; i<n; ++i) {
        int x, y;
        scanf(" %d %d", &x, &y);
        vector<int> point {x, y};
        points.push_back(point);
    }

    Solution1* sol1 = new Solution1();
    int answer = sol1->maxPoints(points);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->maxPoints(points);
    printf("%d\n", answer);

    return 0;
}