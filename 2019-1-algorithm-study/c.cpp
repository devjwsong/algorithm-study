#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<int> first;
vector<int> second;

vector<char> ges = {'h', 's', 'p'};

bool isFirstWon(char g1, char g2) {
  if (g1 == 'h' && g2 == 's') {
    return true;
  } else if (g1 == 's' && g2 == 'p') {
    return true;
  } else if (g1 == 'p' && g2 == 'h') {
    return true;
  } else {
    return false;
  }
}

int main() {

  scanf("%d", &N);

  for (int i=0; i<N; ++i) {
    int n, m;
    scanf("%d %d", &n, &m);

    first.push_back(n);
    second.push_back(m);
  }

  int max_count = 0;

  vector<vector<char>> poss;

  do {

    poss.push_back(ges);

  } while(next_permutation(ges.begin(), ges.end()));

  for (int i=0; i<poss.size(); ++i) {
    int count = 0;

    for (int j=0; j<N; ++j) {
      if (isFirstWon(poss[i][first[j]-1], poss[i][second[j]-1])) {
        ++count;
      }
    }

    if (count >= max_count) {
      max_count = count;
    }
  }

  printf("%d\n", max_count);

  return 0;
}