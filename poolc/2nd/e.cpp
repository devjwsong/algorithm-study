#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> scores;
vector<int> ks;

int main() {

  scanf("%d", &N);

  int sum = 0;
  int min_value = 10001;
  int min_index = -1;

  for (int i=0; i<N; ++i) {
    int input;
    scanf("%d", &input);
    scores.push_back(input);
    sum += input;

    if (input <= min_value) {
      min_value = input;
      min_index = i;
    }
  }

  double max_aver = (double) (sum - min_value) / (double) (N-1);
  int k = 0;
  int num = N - k;

  while(1) {
    ++k;
    --num;

    if (k == N-1) {
      break;
    }

    sum -= scores[k-1];

    if (min_index <= k-1) {
      vector<int>::iterator iter = min_element(scores.begin() + k, scores.end());
      min_index = iter - scores.begin();
      min_value = *iter;
    }

    double cur_aver = (double) (sum - min_value) / (double) (num-1);

    if (cur_aver > max_aver) {
      max_aver = cur_aver;
      ks.clear();
      ks.push_back(k);
    } else if (cur_aver == max_aver) {
      ks.push_back(k);
    }
  }

  for (int i=0; i<ks.size(); ++i) {
    printf("%d\n", ks[i]);
  }

  return 0;
}