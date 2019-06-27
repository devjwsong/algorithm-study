#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N;
const int MAX_COUNT = 5;

int dirr[] = {-1, 1, 0, 0};
int dirc[] = {0, 0, -1, 1};

vector<vector<int>> move(vector<vector<int>> map, int d) {

  vector<vector<int>> after = map;
  stack<pair<bool, int>> store;

  if (d == 0) { // up

    for (int c=0; c<N; ++c) {
      stack<pair<bool, int>> line;

      for (int r=0; r<N; ++r) {
        if (map[r][c] != 0) {
          if (line.empty()) {
            line.push(pair<bool, int> (false, map[r][c]));
          } else {
            pair<bool, int> prev = line.top();

            if (!prev.first && prev.second == map[r][c]) {
              line.pop();
              line.push(pair<bool, int> (true, prev.second * 2));
            } else {
              line.push(pair<bool, int> (false, map[r][c]));
            }
          }
        }

        after[r][c] = 0;
      }

      for (int r=line.size()-1; r>=0; --r) {
        after[r][c] = line.top().second;
        line.pop();
      }
    }

  } else if (d == 1) { // down

    for (int c=0; c<N; ++c) {
      stack<pair<bool, int>> line;

      for (int r=N-1; r>=0; --r) {
        if (map[r][c] != 0) {
          if (line.empty()) {
            line.push(pair<bool, int> (false, map[r][c]));
          } else {
            pair<bool, int> prev = line.top();

            if (!prev.first && prev.second == map[r][c]) {
              line.pop();
              line.push(pair<bool, int> (true, prev.second * 2));
            } else {
              line.push(pair<bool, int> (false, map[r][c]));
            }
          }
        }

        after[r][c] = 0;
      }

      for (int r=N-line.size(); r<N; ++r) {
        after[r][c] = line.top().second;
        line.pop();
      }
    }

  } else if (d == 2) { // left

    for (int r=0; r<N; ++r) {
      stack<pair<bool, int>> line;

      for (int c=0; c<N; ++c) {
        if (map[r][c] != 0) {
          if (line.empty()) {
            line.push(pair<bool, int> (false, map[r][c]));
          } else {
            pair<bool, int> prev = line.top();

            if (!prev.first && prev.second == map[r][c]) {
              line.pop();
              line.push(pair<bool, int> (true, prev.second * 2));
            } else {
              line.push(pair<bool, int> (false, map[r][c]));
            }
          }
        }

        after[r][c] = 0;
      }

      for (int c=line.size()-1; c>=0; --c) {
        after[r][c] = line.top().second;
        line.pop();
      }
    }

  } else if (d == 3) { // right

    for (int r=0; r<N; ++r) {
      stack<pair<bool, int>> line;

      for (int c=N-1; c>=0; --c) {
        if (map[r][c] != 0) {
          if (line.empty()) {
            line.push(pair<bool, int> (false, map[r][c]));
          } else {
            pair<bool, int> prev = line.top();

            if (!prev.first && prev.second == map[r][c]) {
              line.pop();
              line.push(pair<bool, int> (true, prev.second * 2));
            } else {
              line.push(pair<bool, int> (false, map[r][c]));
            }
          }
        }

        after[r][c] = 0;
      }

      for (int c=N-line.size(); c<N; ++c) {
        after[r][c] = line.top().second;
        line.pop();
      }
    }

  }

  return after;

}

int play(vector<vector<int>> map) {
  int max_value = 0;

  stack<pair<int, vector<vector<int>>>> s;
  s.push(pair<int, vector<vector<int>>> (0, map));

  while(1) {

    if (s.empty()) {
      break;
    }

    pair<int, vector<vector<int>>> current = s.top();
    s.pop();

    if (current.first == MAX_COUNT) {
      
      for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
          if (current.second[r][c] >= max_value) {
            max_value = current.second[r][c];
          }
        }
      }

    } else {
      
      for (int d=0; d<4; ++d) {
              
        s.push(pair<int, vector<vector<int>>> (current.first + 1, move(current.second, d)));

      }

    }
  }

  return max_value;
}

int main() {

  scanf("%d", &N);

  vector<vector<int>> map;

  for (int r=0; r<N; ++r) {
    vector<int> row;
    for (int c=0; c<N; ++c) {
      int input = 0;
      scanf("%d", &input);
      row.push_back(input);
    }
    map.push_back(row);
  }

  printf("%d\n", play(map));

  return 0;
}