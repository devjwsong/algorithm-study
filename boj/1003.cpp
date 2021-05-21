#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int T;
pair<vector<int>, vector<int>> memo;

pair<int, int> fibonacci(int n) {
    if (n == 0) {
      if (memo.first[n] == 0) {
        ++memo.first[n];
      }
    } else if (n == 1) {
      if (memo.second[n] == 0) {
        ++memo.second[n];
      }
    } else {
      if (memo.first[n] == 0) {
        memo.first[n] = fibonacci(n-1).first + fibonacci(n-2).first;
      }

      if (memo.second[n] == 0) {
        memo.second[n] = fibonacci(n-1).second + fibonacci(n-2).second;
      }
    }

    return pair<int, int> (memo.first[n], memo.second[n]);
}

int main() {

  scanf("%d", &T);
  memo.first.assign(41, 0);
  memo.second.assign(41, 0);

  for (int test=0; test<T; ++test) {
    int n;
    scanf("%d", &n);

    pair<int, int> result = fibonacci(n);

    printf("%d %d\n", result.first, result.second);
  }

  return 0;
}