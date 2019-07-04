#include <iostream>
#include <map>
#include <set>

using namespace std;

int COW_NUM = 1e+9;

int N, G;
map<int, pair<int, int>> notes;
map<int, int> idAndValue;
map<int, int> valueAndNums;

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
  valueAndNums.insert(pair<int, int> (G, COW_NUM));

  for (map<int, pair<int, int>>::iterator i=notes.begin(); i!=notes.end(); ++i) {

    int cow = i->second.first;
    int change = i->second.second;

    if (change != 0) {
      int before = 0;
      map<int, int>::iterator ivIter = idAndValue.find(cow);
      if (ivIter == idAndValue.end()) {
        before = G;
      } else {
        before = ivIter->second;
      }
      int after = before + change;
      
      if (before == max_amount) {
        if (valueAndNums[before] > 1) {
          ++count;
        } else {
          int second = (--(--valueAndNums.end()))->first;
          if (after <= second) {
            ++count;
          }
        }
      } else {
        if (after >= max_amount) {
          ++count;
        }
      }

      if (ivIter == idAndValue.end()) {
        idAndValue.insert(pair<int, int> (cow, after));
      } else {  
        idAndValue[cow] = after;
      }
      map<int, int>::iterator vnIter = valueAndNums.find(before);
      if (vnIter->second == 1) {
        valueAndNums.erase(before);
      } else {
        --valueAndNums[before];
      }
      
      vnIter = valueAndNums.find(after);
      if (vnIter != valueAndNums.end()) {
        ++valueAndNums[after];
      } else {
        valueAndNums.insert(pair<int, int> (after, 1));
      }

      max_amount = valueAndNums.rbegin()->first;
    }
  }

  printf("%d\n", count);

  return 0;
}
