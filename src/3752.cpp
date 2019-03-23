#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int numTest = 0;

void dfs(int scores[], int numQuestion, set<int>& sums) {
    stack<vector<int>> s;
    s.push(vector<int> {-1, 0, 0});

    while(1) {

        if (s.empty()) {
            break;
        }

        vector<int> current = s.top();
        s.pop();

        if (current[1]) {
            current[2] += scores[current[0]];
        }

        if (current[0] != numQuestion-1) {
            s.push(vector<int> {current[0]+1, true, current[2]});
            s.push(vector<int> {current[0]+1, false, current[2]});
        } else {
            sums.insert(current[2]);
        }
    }

}

int main() {

    scanf("%d", &numTest);

    for (int test=1; test<=numTest; ++test) {
        int numQuestion = 0;
        scanf("%d", &numQuestion);

        int problems[numQuestion];
        set<int> sums;

        bool scores[10001] = {false,};

        for (int i=0; i<numQuestion; ++i) {
            scanf(" %d", &problems[i]);
        }

        scores[0] = true;

        for (int i=0; i<numQuestion; ++i) {
            for (int j=10000; j>=0; --j) {
                if (scores[j]) {
                    if (j+problems[i] <= 10000) {
                        scores[j+problems[i]] = true;
                    }
                }
            }
        }

        int value = 0;

        for (int j=0; j<10001; ++j) {
            if (scores[j]) {
                ++value;
            }
        }

        printf("#%d %d\n", test, value);
    }

    return 0;
}