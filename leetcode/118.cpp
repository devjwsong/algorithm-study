#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        answer.push_back(vector<int> {1});

        for (int r=2; r<=numRows; ++r) {
            vector<int> row;
            row.push_back(1);
            for (int i=0; i<answer[r-2].size()-1; ++i) {
                row.push_back(answer[r-2][i]+answer[r-2][i+1]);
            }
            row.push_back(1);
            answer.push_back(row);
        }

        return answer;
    }
};


int main() {

    int numRows;
    scanf("%d", &numRows);

    Solution* sol = new Solution();
    vector<vector<int>> answer = sol->generate(numRows);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}