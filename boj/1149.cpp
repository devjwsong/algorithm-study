#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// int dfs(int costs[][3], int num) {
//     int min = 1000*num;
//     vector<int> initial = {-1, -1, 0}; //0: index, 1: color, 2: current value

//     stack<vector<int>> s;
//     s.push(initial);

//     while(1) {
//         if (s.empty()) {
//             break;
//         }

//         vector<int> current = s.top();
//         s.pop();

//         if ((num-1) != current[0]) {
//             for (int i=0; i<3; ++i) {
//                 if (i == current[1]) {
//                     continue;
//                 } else {
//                     int new_index = current[0] + 1;
//                     int new_value = current[2] + costs[new_index][i];
//                     if (min >= new_value) {
//                         s.push(vector<int> {new_index, i, new_value});
//                     }
//                 }
//             }
//         } else {
//             if (min >= current[2]) {
//                 min = current[2];
//             }
//         }
//     }

//     return min;
// }

int num;
int memo[1000][3];
int costs[1000][3];

int solve(int num) {

    int index=0;
    memo[index][0] = costs[index][0];
    memo[index][1] = costs[index][1];
    memo[index][2] = costs[index][2];

    for(int index = 1; index < num; index++)
        for (int j=0; j<3; ++j) {
            if (j==0) {
                memo[index+1][j] = min(memo[index][1], memo[index][2]) + costs[index+1][j];
            } else if (j==1) {
                memo[index+1][j] = min(memo[index][0], memo[index][2]) + costs[index+1][j];
            } else if (j==2) {
                memo[index+1][j] = min(memo[index][0], memo[index][1]) + costs[index+1][j];
            }
        }
    return min(memo[num-1][0],min(memo[num-1][1], memo[num-1][2]));
}

int main() {

    scanf("%d", &num);

    for (int i=0; i<num; ++i) {
        for (int j=0; j<3; ++j) {
            int cost = 0;
            scanf(" %d", &cost);
            costs[i][j] = cost; 
        }
    }

    int result = 0;
    result = solve(num);

    printf("%d\n", result);

    return 0;

}