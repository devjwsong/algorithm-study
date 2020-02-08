#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T_max;
vector<int> durations;

int getT(int k) {
  int t = 0;
  vector<int> dancing;

  for (int i=0; i<k; ++i) {
    dancing.push_back(durations[i]);
  }

  int next = k;

  while(1) {

    if (next >= N) {
      break;
    } else {
      vector<int>::iterator smallest = min_element(dancing.begin(), dancing.end());
      t = *smallest;
      dancing.erase(smallest);

      dancing.push_back(t + durations[next]);
      ++next;
    }
  }

  t = *max_element(dancing.begin(), dancing.end());

  return t;
}

int getK() {

  int start = 1;
  int end = N;

  int k = 0;

  while(1) {
    if (start >= end) {
      k = start;
      break;
    }

    int mid = (start + end) / 2;

    int t = getT(mid);

    if (t > T_max) {
      start = mid + 1;
    } else {
      end = mid;
    }
  } 

  return k;

}

int main() {

  scanf("%d %d", &N, &T_max);

  for (int i=0; i<N; ++i) {
    int input;
    scanf("%d", &input);
    durations.push_back(input);
  }

  printf("%d\n", getK());
  // cout<<getT(5)<<endl;
  // cout<<getT(4)<<endl;
  // cout<<getT(3)<<endl;
  // cout<<getT(2)<<endl;
  // cout<<getT(1)<<endl;

  return 0;
}