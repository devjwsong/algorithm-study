#include <iostream>

using namespace std;

int main() {

  int h, m;
  scanf("%d %d", &h, &m);

  int total = h * 60 + m;

  if (total < 45) {
    total += 1440;
  }

  total -= 45;

  if (total >= 1440) {
    total %= 1440;
  }

  h = total / 60;
  m = total % 60;

  printf("%d %d\n", h, m);

  return 0;
}