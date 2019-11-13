#include <iostream>

using namespace std;

int L, D, X;

int getSumDigit(int n) {
  int sum = 0;
  while(1) {
    if (n == 0) {
      break;
    }

    sum += (n%10);
    n /= 10;
  }

  return sum;
}

int main() {
  scanf("%d", &L);
  scanf("%d", &D);
  scanf("%d", &X);

  int N = 0;
  for (int i=L; i<=D; ++i) {
    if (getSumDigit(i) == X) {
      N = i;
      break;
    }
  }

  int M = 0;
  for (int i=D; i>=L; --i) {
    if (getSumDigit(i) == X) {
      M = i;
      break;
    }
  }

  printf("%d\n", N);
  printf("%d\n", M);

  return 0;
}