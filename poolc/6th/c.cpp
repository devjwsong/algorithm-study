#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int T;
int N;
vector<int> coins;
int M;


int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        
        scanf("%d", &N);

        for (int i=0; i<N; ++i) {
            int input;
            scanf("%d", &input);
            coins.push_back(input);
        }
        
        scanf("%d", &M);

        int amount[M+1] = {0, };
        amount[0] = 1;

        for (int i=0; i<coins.size(); ++i) {
            int coin = coins[i];

            for (int j=coin; j<=M; ++j) {
                amount[j] += amount[j-coin];
            }
        }

        printf("%d\n", amount[M]);

        coins.clear();
    }

    return 0;
}