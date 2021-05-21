#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dir_r[] = {0, -1, 0, 1};
int dir_c[] = {1, 0, -1, 0};

struct Curve {
    Curve (int _x, int _y, int _d, int _g) {
        x = _x;
        y = _y;
        d = _d;
        g = _g;
    }

    int x;
    int y;
    int d;
    int g;
};

int N;
vector<struct Curve> curves;
vector<vector<bool>> map;

int count() {
    int answer = 0;

    for (int r=0; r<100; ++r) {
        for (int c=0; c<100; ++c) {
            if (map[r][c] && map[r+1][c] && map[r][c+1] && map[r+1][c+1]) {
                ++answer;
            }
        }
    }

    return answer;
}

void draw(vector<pair<int, int>> spots, int cur_g, int g) {
    vector<pair<int, int>> next = spots;
    pair<int, int> anc;

    for (int i=spots.size()-1; i>=0; --i) {
        if (spots[i].first >= 0 && spots[i].first <= 100 && spots[i].second >= 0 && spots[i].second <= 100) {
            map[spots[i].first][spots[i].second] = true;
        }

        if (i != spots.size()-1) {
            int r = spots[i].first;
            int c = spots[i].second;
            int next_r = c - anc.second + anc.first;
            int next_c = -r + anc.first + anc.second;
            next.push_back({next_r, next_c});
        } else {
            anc = spots[i];
        }
    }

    if (cur_g == g) {
        return;
    } else {
        draw(next, cur_g+1, g);
    }
}

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        struct Curve curve (x, y, d, g);
        curves.push_back(curve);
    }

    map.assign(101, vector<bool> (101, false));

    for (int i=0; i<curves.size(); ++i) {
        int r = curves[i].y;
        int c = curves[i].x;
        int d = curves[i].d;
        int g = curves[i].g;
        draw(vector<pair<int, int>> {{r, c}, {r+dir_r[d], c+dir_c[d]}}, 0, g);
    }

    printf("%d\n", count());

    return 0;
}