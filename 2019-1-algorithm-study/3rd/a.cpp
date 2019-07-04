#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int, int>> max_coords;

int dir_r[] = {-1, 0, 1, 0}; // 상, 좌, 하, 우
int dir_c[] = {0, 1, 0, -1};

int oppositeDir(int d) {
  return (d+2)%4;
}

int getMaxValue(int row, int col) {
  stack<vector<int>> s;
  s.push(vector<int> {map[row][col], 1, row, col, -1});

  int answer = 0;

  while(1) {
    if (s.empty()) {
      break;
    }

    vector<int> current = s.top();
    s.pop();

    if (current[1] == 4) {
      if (current[0] >= answer) {
        answer = current[0];
      }
    } else {
      for (int i=0; i<4; ++i) {
        if (current[4] != i) {
          int next_r = current[2] + dir_r[i];
          int next_c = current[3] + dir_c[i];

          if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) {
            continue;
          } else {
            vector<int> next = {current[0] + map[next_r][next_c], current[1]+1, next_r, next_c, oppositeDir(i)};
            s.push(next);
          }
        }
      }
    }
  }

  int count = 0;
  int value = map[row][col];
  for (int i=0; i<4; ++i) {
    int next_r = row + dir_r[i];
    int next_c = col + dir_c[i];

    if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) {
      continue;
    } else {
      value += map[next_r][next_c];
      ++count;
    }
  }

  if (count == 4) {
    for (int i=0; i<4; ++i) {
      int new_value = value - map[row+dir_r[i]][col+dir_c[i]];
      if (new_value >= answer) {
        answer = new_value;
      } 
    }
  } else if (count == 3) {
    if (value >= answer) {
      answer = value;
    }
  }

  return answer;
}

int main() {
  
  scanf("%d %d", &N, &M);

  int max_value = 0;
  for (int r=0; r<N; ++r) {
    vector<int> row;
    for (int c=0; c<M; ++c) {
      int input;
      scanf("%d", &input);
      row.push_back(input);

      if (input >= max_value) {
        max_value = input;
      }
    }
    map.push_back(row);
  }

  for (int r=0; r<N; ++r) {
    for (int c=0; c<M; ++c) {
      if (map[r][c] == max_value) {
        max_coords.push_back(pair<int, int> (r, c));
      }
    }
  }

  int answer = 0;
  int result = 0;
  for (int r=0; r<N; ++r) {
    for (int c=0; c<M; ++c) {
      result = getMaxValue(r, c);

      if (result >= answer) {
        answer = result;
      }
    }
  }

  printf("%d\n", answer);

  return 0;
}
