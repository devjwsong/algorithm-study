#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> nums;

int main() {

    scanf("%d", &n);

    for (int i=0; i<n; ++i) {
        int input;
        scanf("%d", &input);
        nums.push_back(input);
    }

    vector<int> ops;

    for (int i=0; i<4; ++i) {
        int num;
        scanf("%d", &num);

        for (int j=0; j<num; ++j) {
            if (i == 0) {
                ops.push_back(1);
            } else if (i == 1) {
                ops.push_back(2);
            } else if (i == 2) {
                ops.push_back(3);
            } else if (i == 3) {
                ops.push_back(4);
            }
        }
    }

    int maxVal = -1000000000;
    int minVal = 1000000000;

    do {
        int answer = nums[0];

        for (int i=0; i<ops.size(); ++i) {
            if (ops[i] == 1) {
                answer += nums[i+1];
            } else if (ops[i] == 2) {
                answer -= nums[i+1];
            } else if (ops[i] == 3) {
                answer *= nums[i+1];
            } else if (ops[i] == 4) {
                answer /= nums[i+1];
            }
        }

        if (answer >= maxVal && answer <= 1000000000) {
            maxVal = answer;
        }

        if (answer <= minVal && answer >= -1000000000) {
            minVal = answer;
        }
    } while(next_permutation(ops.begin(), ops.end()));

    printf("%d\n", maxVal);
    printf("%d\n", minVal);

    return 0;
}