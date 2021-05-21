#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<vector<int>> city;

int num_chick = 0;
int num_house = 0;
vector<int> comb; 

vector<pair<int, int>> houses;
vector<pair<int, int>> chicks;

int getDist(int r1, int c1, int r2, int c2) {
    return abs(r1-r2) + abs(c1-c2);
}

int getDist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int main() {

    scanf("%d %d", &N, &M);

    city.assign(N+1, vector<int> (N+1, 0));

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            scanf("%d", &city[r][c]);

            if (city[r][c] == 1) {
                ++num_house;
                houses.push_back({r,c});
            } else if (city[r][c] == 2) {
                ++num_chick;
                chicks.push_back({r,c});
            }
        }
    }

    for (int i=0; i<num_chick; ++i) {
        if (i < (num_chick-M)) {
            comb.push_back(0);
        } else {
            comb.push_back(1);
        }
    }

    int answer = INT_MAX;

    do {
        int city_dist = 0;

        for (int i=0; i<houses.size(); ++i) {
            int chick_dist = INT_MAX;
            for (int j=0; j<chicks.size(); ++j) {
                if (comb[j] == 1) {
                    chick_dist = min(chick_dist, getDist(houses[i], chicks[j]));
                }
            }
            city_dist += chick_dist;
        }

        answer = min(answer, city_dist);

    } while(next_permutation(comb.begin(), comb.end()));

    printf("%d\n", answer);

    return 0;
}