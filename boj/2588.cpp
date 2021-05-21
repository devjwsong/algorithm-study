#include <iostream>
#include <cmath>

using namespace std;

int main() {

  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  
  int result = 0;
  
  for (int i=0; i<3; ++i) {
    int digit = b % 10;
    b /= 10;

    printf("%d\n", a * digit);
    result += a * digit * (int) pow(10, i);
  }

  printf("%d\n", result);

  return 0;
}