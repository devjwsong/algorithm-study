#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int C, N;
vector<int> chickens;
vector<pair<int, int>> cows;

bool isSmaller(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second < p2.second) {
    return true;
  } else if (p1.second == p2.second) {
    return p1.first < p2.first;
  } else {
    return false;
  }
}

int main() {
  
  scanf("%d %d", &C, &N);

  chickens.assign(C+1, -1);
  for (int i=1; i<=C; ++i) {
    scanf("%d", &chickens[i]);
  }

  sort(chickens.begin(), chickens.end());

  cows.assign(N+1, pair<int, int> (-1, -1));
  for (int i=1; i<=N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    cows[i] = pair<int, int> (a, b);
  }

  sort(cows.begin(), cows.end(), isSmaller);

  int count = 0;

  for (int i=1; i<=N; ++i) {
    for (int j=1; j<=C; ++j) {
      if (cows[i].first <= chickens[j] && cows[i].second >= chickens[j]) {
        ++count;
        chickens[j] = -1;
        break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
