#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer (n+1, 0);
        for (int i=1; i<=n; ++i) {
            int prev = answer[i/2];
            if (i % 2 == 1) {
                answer[i] = prev + 1;
            } else {
                answer[i] = prev;
            }
        }

        return answer;
    }
};


int main() {
    
    int n;
    scanf("%d", &n);

    Solution *sol = new Solution();
    vector<int> answer = sol->countBits(n);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}