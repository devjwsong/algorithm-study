#include <iostream>
#include <map>
#include <set>

using namespace std;

int COW_NUM = 1e+9;

int N, G;
map<int, pair<int, int>> notes;
map<int, int> idAndValue;
map<int, set<int>> valueAndIds;

int main() {
  
  scanf("%d %d", &N, &G);

  for (int i=0; i<N; ++i) {
    int day;
    int cow;
    int change;
    scanf("%d %d %d", &day, &cow, &change);
    notes.insert(pair<int, pair<int, int>> (day, pair<int, int> (cow, change)));
  }

  int count = 0;
  int max_amount = G;

  

  for (map<int, pair<int, int>>::iterator i=notes.begin(); i!=notes.end(); ++i) {
  }

  printf("%d\n", count);

  return 0;
}
