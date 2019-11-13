#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Robo {
  int r;
  int c;
  int d;
  int checked = 0;
};

struct Robo robo;
int N, M;
vector<vector<pair<int, bool>>> map;
int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

int turn(int d) {
  if (d == 0) {
    return 3;
  } else {
    return d-1;
  }
}

int clean() {
  int count = 0;

  while(1) {

    if (!map[robo.r][robo.c].second) { //1
      map[robo.r][robo.c].second = true;
      ++count;
      continue;
    } else { // 2

      int next_d = turn(robo.d);
      int next_r = robo.r + dir_r[next_d];
      int next_c = robo.c + dir_c[next_d];

      if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M && 
          !map[next_r][next_c].second && map[next_r][next_c].first == 0) {
        robo.r = next_r;
        robo.c = next_c;
        robo.d = next_d;
        robo.checked = 0;
        continue;
      } else {
        robo.d = next_d;
        ++robo.checked;
      }
    }

    if (robo.checked == 4) {
      int back_d = turn(turn(robo.d));
      int back_r = robo.r + dir_r[back_d];
      int back_c = robo.c + dir_c[back_d];

      if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M && 
          map[back_r][back_c].first == 0) {
        robo.r = back_r;
        robo.c = back_c;
        robo.checked =0;
      } else {
        break;
      }
    }
  }

  return count;
}

int main() {

  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &robo.r, &robo.c, &robo.d);

  for (int r=0; r<N; ++r) {
    vector<pair<int, bool>> row;
    for (int c=0; c<M; ++c) {
      int input;
      scanf("%d", &input);
      row.push_back(pair<int, bool> (input, false));
    }
    map.push_back(row);
  }

  printf("%d\n", clean());

  return 0;
}