#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int N;
vector<vector<int>> map;

void flip(int r, int c) {
  for (int i=0; i<=r; ++i) {
    for (int j=0; j<=c; ++j) {
      if (map[i][j] == 0) {
        map[i][j] = 1;
      } else {
        map[i][j] = 0;
      }
    }
  }
}

int work() {

  int count = 0;

  for (int r=N-1; r>=0; --r) {
    for (int c=N-1; c>=0; --c) {
      if (map[r][c] == 1) {
        flip(r, c);
        ++count;
      }
    }
  }

  return count;

}

int main() {

  scanf("%d", &N);

  for (int i=0; i<N; ++i) {
    vector<int> row;

    for (int j=0; j<N; ++j) {
      int value = 0;
      scanf("%1d", &value);
      row.push_back(value);
    }

    map.push_back(row);
  }

  printf("%d\n", work());

  return 0;
}