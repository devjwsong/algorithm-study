#include <iostream>
#include <vector>

using namespace std;

int N, K, B;
vector<int> partialSums;

int main() {

  scanf("%d %d %d", &N, &K, &B);

  partialSums.assign(N+1, 0);

  for (int i=1; i<=B; ++i) {
    int input;
    scanf("%d", &input);
    partialSums[input] = 1;
  }

  for (int i=0; i<N; ++i) {
    partialSums[i+1] += partialSums[i];
  }

  int count = N;

  for (int i=1; i<=N-K+1; ++i) {
    if (partialSums[i+K-1] - partialSums[i] <= count) {
      count = partialSums[i+K-1] - partialSums[i];
    }
  }

  printf("%d\n", count);

  return 0;
}