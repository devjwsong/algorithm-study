#include <iostream>
#include <vector>

using namespace std;

int N;
int col[16];
int answer = 0;

void NQueen(int cur) {
   if (cur == N+1) {
       ++answer;
   } else {
       for (int c=1; c<=N; ++c) {
           bool isPossible = true;
           for (int i=1; i<cur; ++i) {
               if (c == col[i] || abs(i-cur) == abs(col[i]-c)) {
                   isPossible = false;
               }
           }

           if (isPossible) {
               col[cur] = c;
               NQueen(cur+1);
           }
       }
   }
}

int main() {

    scanf("%d", &N);

    NQueen(1);

    printf("%d\n", answer);

    return 0;
}