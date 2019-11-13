#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long X;
vector<int> seq;

int main() {

    scanf("%d %lld", &N, &X);

    long long maxSize = 0;

    if (N <= 2) {
      maxSize = 0;
    } else {
      maxSize = (long long) (N-1) * (long long) (N-2) / 2;
    }

    if (X > maxSize) {
      printf("%d\n", -1);
    } else {

      long long size = 0;

      seq.push_back(N);

      vector<int> out;
      vector<int> in;

      for (int i=1; i<=N-2; ++i) {
        if (size + (N - 1 - i) <= X) {
          in.push_back(i);
          size += (N - 1 - i);
        } else {
          out.push_back(i);
        }
      }

      for (int i=0; i<in.size(); ++i) {
        seq.push_back(in[i]);
      }

      seq.push_back(N-1);

      sort(out.begin(), out.end(), greater<int>());

      for (int i=0; i<out.size(); ++i) {
        seq.push_back(out[i]);
      }

      for (int i=0; i<seq.size(); ++i) {
        printf("%d ", seq[i]);
      }
      printf("\n");

    }

    return 0;
}