#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> rules;
vector<int> checked;

int main() {

  scanf("%d", &N);

  rules.assign(N+1, 0);
  checked.assign(N+1, 0); // 0: not checked
  for (int i=1; i<=N; ++i) {
    scanf("%d", &rules[i]);
  }

  int count = 0;
  int check_number = 0;

  for (int i=1; i<=N; ++i) {
    if (checked[i] == 0) {
      ++check_number;

      stack<int> s;

      int current = i;
      while(1) {
        if (checked[current] != 0) {
          break;
        }

        s.push(current);
        checked[current] = check_number;
        current = rules[current];
      }

      if (checked[current] == check_number) {
        while(1) {
          int value = s.top();
          s.pop();
          ++count;

          if (current == value) {
            break;
          }
        }
      }
    }
  }

  printf("%d\n", count);

  return 0;
}