#include <iostream>
#include <vector>

using namespace std;


/*
Very smart trick!
If there is an update (i, j, k), then a[i] = +k and a[j+1] = -k.
Then conducting a[i] += a[i-1] for i<=j makes a[i:j] = +k  and a[j+1] = 0.
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> answer (length, 0);
        int u = updates.size();
        for (int i=0; i<u; ++i) {
            answer[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < length) answer[updates[i][1]+1] -= updates[i][2];
        }

        for (int i=1; i<length; ++i) {
            answer[i] += answer[i-1];
        }

        return answer;
    }
};


int main() {

    int length;
    scanf("%d", &length);

    int u;
    scanf("%d", &u);
    vector<vector<int>> updates;
    for (int i=0; i<u; ++i) {
        int start, end, inc;
        scanf("%d %d %d", &start, &end, &inc);
        updates.push_back({start, end, inc});
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->getModifiedArray(length, updates);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}