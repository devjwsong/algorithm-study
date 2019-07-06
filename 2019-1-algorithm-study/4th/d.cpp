#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> prices;

int main() {
  scanf("%d", &N);
  
  for (int i=0; i<N; ++i) {
    int price;
    scanf("%d", &price);
    prices.push_back(price);
  }

  sort(prices.begin(), prices.end(), greater<int>());

  int canErase = prices.size() / 3;
  int count = 0;

  for (int i=0; i<prices.size(); ++i) {
    count += prices[i];
  }

  for (int i=0; i<canErase; ++i) {
    count -= prices[i * 3 + 2];
  }

  printf("%d\n", count);

  return 0;
}