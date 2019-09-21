#include <iostream>

using namespace std;

int N, R, G, B;

long long memo[11][101][101][101];
int facs[11];

int factorial(int n) {
    if (facs[n] == 0) {
        if (n == 1) {
            facs[1] = 1;
        } else {
            facs[n] = n * factorial(n-1);
        }
    }

    return facs[n];
}

int main() {

    scanf("%d %d %d %d", &N, &R, &G, &B);

    memo[1][R-1][G][B] = 1;
    memo[1][R][G-1][B] = 1;
    memo[1][R][G][B-1] = 1;

    for (int i=2; i<=N; ++i) {
        int used = i * (i-1) / 2;
        for (int r=0; r<=R; ++r) {
            for (int g=0; g<=G; ++g) {
                for (int b=0; b<=B; ++b) {
                    if (r+g+b == (R+G+B-used) && memo[i-1][r][g][b] != 0) {
                        if (i % 1 == 0) {
                            if (r - i >= 0) {
                                memo[i][r-i][g][b] += memo[i-1][r][g][b];
                            }

                            if (g - i >= 0) {
                                memo[i][r][g-i][b] += memo[i-1][r][g][b];
                            }

                            if (b - i >= 0) {
                                memo[i][r][g][b-i] += memo[i-1][r][g][b];
                            }
                        }

                        if (i % 2 == 0) {
                            if ((r - (i/2) >= 0) && (g - (i/2) >= 0)) {
                                memo[i][r-(i/2)][g-(i/2)][b] 
                                    += memo[i-1][r][g][b] * (factorial(i) / factorial(i/2) / factorial(i/2));
                            }

                            if ((g - (i/2) >= 0) && (b - (i/2) >= 0)) {
                                memo[i][r][g-(i/2)][b-(i/2)] 
                                    += memo[i-1][r][g][b] * (factorial(i) / factorial(i/2) / factorial(i/2));
                            }

                            if ((b - (i/2) >= 0) && (r - (i/2) >= 0)) {
                                memo[i][r-(i/2)][g][b-(i/2)] 
                                    += memo[i-1][r][g][b] * (factorial(i) / factorial(i/2) / factorial(i/2));
                            }
                        }

                        if (i % 3 == 0) {
                            if ((r - (i/3) >= 0) && (g - (i/3) >= 0) && (b - (i/3) >= 0)) {
                                memo[i][r-(i/3)][g-(i/3)][b-(i/3)]
                                    += memo[i-1][r][g][b] * (factorial(i) / factorial(i/3) / factorial(i/3) / factorial(i/3));
                            }
                        }
                    }
                }
            }
        }
    }

    long long answer = 0;

    for (int r=0; r<=R; ++r) {
        for (int g=0; g<=G; ++g) {
            for (int b=0; b<=B; ++b) {
                answer += memo[N][r][g][b];
            }
        }
    }

    printf("%lld\n", answer);
    // for (int i=1; i<=N; ++i) {
    //     cout<<"n: "<<i<<endl;
    //     for (int r=0; r<=R; ++r) {
    //         for (int g=0; g<=G; ++g) {
    //             for (int b=0; b<=B; ++b) {
    //                 cout<<"red used: "<<R-r<<" | green used: "<<G-g<<" | blue used: "<<B-b<<" => "<<memo[i][r][g][b]<<endl;
    //             }
    //         }
    //     }
    // }

    return 0;
}