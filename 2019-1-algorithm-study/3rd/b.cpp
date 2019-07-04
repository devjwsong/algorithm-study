#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<pair<int, int>> locs;
vector<int> cowNotes;

int main() {
  
  scanf("%d", &N);

  for (int i=0; i<N; ++i) {
    int cow;
    int loc;
    scanf("%d %d", &cow, &loc);
    locs.push_back(pair<int, int> (cow, loc));
  }

  int count = 0;
  cowNotes.assign(11, -1);

  for (int i=0; i<N; ++i) {
    if (cowNotes[locs[i].first] == -1) {
      cowNotes[locs[i].first] = locs[i].second;
    } else {
      if (cowNotes[locs[i].first] != locs[i].second) {
        ++count;
        cowNotes[locs[i].first] = locs[i].second;
      } 
    }
  }

  printf("%d\n", count);

  return 0;
}
