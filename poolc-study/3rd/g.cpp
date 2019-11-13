#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

int N, K, R;
int map[101][101];
set<pair<int, int>> roads[101][101];
vector<pair<int, int>> cows;

int gNum = 1;

int dir_r[4] = {-1, 1, 0, 0};
int dir_c[4] = {0, 0, -1, 1};

void dfs(int row, int col) {
  stack<pair<int, int>> s;
  s.push(pair<int, int> (row, col));

  while(1) {
    if (s.empty()) {
      break;
    }

    pair<int, int> cur = s.top();
    s.pop();

    if (map[cur.first][cur.second] != 0 && map[cur.first][cur.second] != gNum) {
      break;
    } else {
      map[cur.first][cur.second] = gNum;

      for (int d=0; d<4; ++d) {
        int next_r = cur.first + dir_r[d];
        int next_c = cur.second + dir_c[d];

        if (next_r > 0 && next_r <= N && next_c > 0 && next_c <= N) {
          if (roads[cur.first][cur.second].count(pair<int, int> (next_r, next_c)) == 0) {
            if (map[next_r][next_c] == 0) {
              s.push(pair<int, int> (next_r, next_c));
            }
          }
        }
      }
    }
  }
}

int main() {

  scanf("%d %d %d", &N, &K, &R);

  for (int i=0; i<R; ++i) {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    roads[r1][c1].insert(pair<int, int> (r2, c2));
    roads[r2][c2].insert(pair<int, int> (r1, c1));
  }

  cows.assign(K+1, pair<int, int> (0, 0));

  for (int i=1; i<=K; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    cows[i] = pair<int, int> (r, c);
  }

  for (int r=1; r<=N; ++r) {
    for (int c=1; c<=N; ++c) {
      dfs(r, c);
      ++gNum;
    }
  }

  int count = 0;

  for (int i=1; i<=K-1; ++i) {
    for (int j=i+1; j<=K; ++j) {
      if (map[cows[i].first][cows[i].second] != map[cows[j].first][cows[j].second]) {
        ++count;
      }
    }
  }

  printf("%d\n", count);  

  return 0;
}