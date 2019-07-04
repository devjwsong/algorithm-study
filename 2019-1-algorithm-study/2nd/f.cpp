#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int COW_NUM = 1e+9;

int N;
int G;
map<int, pair<int, int>> notes;
map<int, int> valueAndNum;
vector<int> amounts;

int main() {

  scanf("%d %d", &N, &G);

  for (int i=0; i<N; ++i) {
    int day, cow, change;
    scanf("%d %d %d", &day, &cow, &change);
    notes.insert(pair<int, pair<int, int>> (day, pair<int, int> (cow, change)));
  }

  amounts.assign(COW_NUM+1, G);
  valueAndNum.insert(pair<int, int> (G, COW_NUM));

  int count = 0;

  for (map<int, pair<int, int>>::iterator i=notes.begin(); i!=notes.end(); ++i) {
    int curValue = amounts[i->second.first];
    int nextValue = amounts[i->second.first] + i->second.second;
    int cow = i->second.first;

    map<int, int>::iterator max_iter = valueAndNum.end();
    --max_iter;

    if (curValue == max_iter->first) {
      if (nextValue > curValue) {
        if (valueAndNum[curValue] > 1) {
          ++count;
        }
      } else if (nextValue < curValue) {
        ++count;
      }
    } else {
      if (nextValue >= max_iter->first) {
        ++count;
      }
    }

    --valueAndNum[curValue];
    if (valueAndNum[curValue] == 0) {
      valueAndNum.erase(curValue);
    }

    if (valueAndNum[nextValue] != 0) {
      ++valueAndNum[nextValue];
    } else {
      valueAndNum.insert(pair<int, int> (nextValue, 1));
    }
    
  }

  printf("%d\n", count);

  return 0;
}