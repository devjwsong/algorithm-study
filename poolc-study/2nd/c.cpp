#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<int> rules;
vector<int> results;

vector<int> reverse() {
  vector<int> prev (N+1, 0);

  for (int i=1; i<=N; ++i) {
    prev[i] = results[rules[i]];
  }

  return prev;
}

int main() {

  scanf("%d", &N);

  rules.push_back(-1);
  for (int i=1; i<=N; ++i) {
    int next;
    scanf("%d", &next);
    rules.push_back(next);
  }

  results.push_back(-1);
  for (int i=1; i<=N; ++i) {
    int id;
    scanf("%d", &id);
    results.push_back(id);
  }

  for (int i=0; i<3; ++i) {
    results = reverse();
  }

  for (int i=1; i<=N; ++i) {
    printf("%d\n", results[i]);
  }

  return 0;
}