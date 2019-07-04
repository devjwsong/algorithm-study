#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> notes;

int stan(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first;
}

int main() {
  
  scanf("%d", &N);

  for (int i=0; i<N; ++i) {
    int arrival;
    int time;
    scanf("%d %d", &arrival, &time);
    notes.push_back(pair<int, int> (arrival, time));
  }

  sort(notes.begin(), notes.end(), stan);

  int count = notes[0].first + notes[0].second;

  for (int i=1; i<notes.size(); ++i) {
    if (notes[i].first >= count) {
      count = notes[i].first + notes[i].second;
    } else {
      count += notes[i].second;
    }
  }

  printf("%d\n", count);

  return 0;
}
