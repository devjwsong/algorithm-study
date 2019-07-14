#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
int isPrime[100001];
bool isChecked[100001];
int pSum1[100001]; // 홀수부터 시작
int pSum2[100001]; // 짝수부터 시작
int pNum[100001];

int main() {

    scanf("%d", &N);

    int point = (int) sqrt(100000);

    for (int i=2; i<=point; ++i) {
        int j = 2;
        if (!isChecked[i]) {
            while(1) {
                if (i * j > 100000) {
                    break;
                }

                isChecked[i * j] = true;
                ++j;
            }
        }
    }

    int count = 1;
    for (int i=2; i<=100000; ++i) {
        if (!isChecked[i]) {
            isPrime[i] = count;
            ++count;
        }
    }

    pSum1[2] = 0;
    pSum2[2] = 0;
    for (int i=3; i<=100000; ++i) {
        pSum1[i] = pSum1[i-1];
        pSum2[i] = pSum2[i-1];
        pNum[i] = pNum[i-1];

        if (isPrime[i-1] != 0) {
            if (isPrime[i-1] % 2 == 1) {
                pSum1[i] += (3 * (i-1));
                pSum2[i] -= (i-1);
            } else {
                pSum1[i] -= (i-1);
                pSum2[i] += (3 * (i-1));
            }
            ++pNum[i];
        }
    }

    for (int n=0; n<N; ++n) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int answer = 0;

        if (pNum[b] % 2 == 0 && pNum[a] % 2 == 0) {
            answer = pSum1[b] - pSum1[a];
            if (isPrime[b] != 0) {
                answer += (3*b);
            }
        } else if (pNum[b] % 2 == 0 && pNum[a] % 2 == 1) {
            answer = pSum2[b] - pSum2[a];
            if (isPrime[b] != 0) {
                answer -= b;
            }
        } else if (pNum[b] % 2 == 1 && pNum[a] % 2 == 0) {
            answer = pSum1[b] - pSum1[a];
            if (isPrime[b] != 0) {
                answer -= b;
            }
        } else if (pNum[b] % 2 == 1 && pNum[a] % 2 == 1) {
            answer = pSum2[b] - pSum2[a];
            if (isPrime[b] != 0) {
                answer += (3*b);
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}