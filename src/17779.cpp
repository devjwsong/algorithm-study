#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> city;

int pSum[21][21];
int total = 0;

int split(int x, int y, int d1, int d2) {
    vector<int> sums;

    // 1
    int sum = 0;
    for (int r=1; r<x+d1; ++r) {
        if (r < x) {
            sum += (pSum[r][y] - pSum[r][0]);
        } else {
            int diff = r - x;
            sum += (pSum[r][y-diff-1] - pSum[r][0]);
        }
    }
    
    sums.push_back(sum);

    // 2
    sum = 0;
    for (int r=1; r<=x+d2; ++r) {
        if (r <= x) {
            sum += (pSum[r][N] - pSum[r][y]);
        } else {
            int diff = r - (x+1);
            sum += (pSum[r][N] - pSum[r][y+1+diff]);
        }
    }
    sums.push_back(sum);

    // 3
    sum = 0;
    for (int r=x+d1; r<=N; ++r) {
        if (r <= x+d1+d2) {
            int diff = (r - (x+d1));
            sum += (pSum[r][y-d1+(diff-1)] - pSum[r][0]);
        } else {
            sum += (pSum[r][y-d1+d2-1] - pSum[r][0]);
        }
    }
    sums.push_back(sum);

    // 4
    sum = 0;
    for (int r=x+d2+1; r<=N; ++r) {
        if (r > x+d1+d2) {
            sum += (pSum[r][N] - pSum[r][y+d2-d1-1]);
        } else {
            int diff = (r - (x+d2));
            sum += (pSum[r][N] - pSum[r][y+d2-diff]);
        }
    }
    sums.push_back(sum);

    int cur_sum = 0;
    for (int i=0; i<sums.size(); ++i) {
        cur_sum += sums[i];
    }

    sums.push_back(total - cur_sum);

    // cout<<"Sums"<<endl;
    // for (int i=0; i<sums.size(); ++i) {
    //     cout<<i+1<<": "<<sums[i]<<endl;
    // }

    sort(sums.begin(), sums.end());
    
    return sums[sums.size()-1] - sums[0];
}

int main() {

    scanf("%d", &N);

    city.assign(N+1, vector<int> (N+1, 0));
    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            scanf("%d", &city[r][c]);
            pSum[r][c] = city[r][c];
            total += city[r][c];
        }
    }

    for (int r=1; r<=N; ++r) {
        for (int c=0; c<N; ++c) {
            pSum[r][c+1] += pSum[r][c];
        }
    }

    int answer = INT_MAX;

    for (int x=1; x<=N-2; ++x) {
        for (int y=2; y<=N-1; ++y) {
            for (int d1=1; d1<=N; ++d1) {
                for (int d2=1; d2<=N; ++d2) {
                    if (x+d1+d2 <= N && (y-d1 >= 1 && y+d2 <= N)) {
                        // cout<<x<<" "<<y<<" "<<d1<<" "<<d2<<" "<<endl;
                        int result = split(x ,y, d1, d2);
                        if (result < answer) {
                            answer = result;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}