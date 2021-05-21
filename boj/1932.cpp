#include <iostream>
#include <vector>

using namespace std;

int num;
int triangle[500][500];
int memo[500][500];

int solve(int num) {

    int index = 0;
    memo[index][0] = triangle[index][0];

    while(1) {
        if (index == num-1) {
            int max_value = 0;
            for (int i=0; i<num; ++i) {
                if (max_value <= memo[index][i]) {
                    max_value = memo[index][i];
                }
            }
            return max_value;
        } else {
            for (int col=0; col<num+1; ++col) {
                if (col==0) {
                    memo[index+1][0] = memo[index][0] + triangle[index+1][0];
                } else if (col==num) {
                    memo[index+1][num] = memo[index][num-1] + triangle[index+1][num];
                } else {
                    memo[index+1][col] = max(memo[index][col-1], memo[index][col]) + triangle[index+1][col];
                }
            }
        }

        ++index;
    }

}

int main() {
    scanf("%d", &num);

    for (int i=0; i<num; ++i) {
        for (int j=0; j<i+1; ++j) {
            int input = 0;
            scanf(" %d", &input);
            triangle[i][j] = input;
        }
    }

    int result = 0;
    result = solve(num);

    printf("%d\n", result);

    return 0;
}