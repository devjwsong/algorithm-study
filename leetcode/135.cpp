#include <iostream>
#include <vector>

using namespace std;


/*
Greedy solution.
First, update the candies according to the left information.
As a greedy method, each child has the proper candies based on the left ratings.
Then update the candies again according to the right information.
Since the only two things matter is left & right children's ratings,
each update makes each candy increasing, not decreasing.
Therefore, minumally 2 updates make the answer into minimum sum.
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;

        vector<int> numCandies (n, 1);
        for (int i=1; i<n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                numCandies[i] = numCandies[i-1] + 1;
            }
        }
        int answer = numCandies[n-1];
        for (int i=n-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1] && numCandies[i] <= numCandies[i+1]) {
                numCandies[i] = numCandies[i+1] + 1;
            }
            answer += numCandies[i];
        }

        for (int i=0; i<n; ++i) {
            cout<<numCandies[i]<<" ";
        }
        cout<<endl;

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> ratings;
    for (int i=0; i<n; ++i) {
        int val;
        scanf("%d", &val);
        ratings.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->candy(ratings);
    printf("%d\n", answer);

    return 0;
}