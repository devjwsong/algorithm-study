#include <iostream>
#include <vector>

using namespace std;

int C;
int N, M;
vector<vector<int>> seats;
int memo[11][1<<11];

const int INF = 100000000;

void update(int row, int state) {
    
}

int main() {

    scanf("%d", &C);

    for (int t=1; t<=C; ++t) {
        scanf("%d %d", &N, &M);
        getchar();

        seats.assign(N+1, vector<int> (M+1, 0));

        for (int r=1; r<=N; ++r) {
            for (int c=1; c<=M; ++c) {
                char p;
                scanf("%c", &c);

                if (C == '.') {
                    seats[r][c] = 1;
                }
            }
        }

        for (int r=1; r<=N; ++r) {
            update(r, 1<<(M+1));
        }
        
        seats.clear();
    }

    return 0;
}