#include <iostream>
#include <string>

using namespace std;

string a;
string b;
int memo[1001][1001];

int main() {

    cin>>a>>b;

    for (int i=1; i<=a.size(); ++i) {
        for (int j=1; j<=b.size(); ++j) {
            if (a[i-1] == b[j-1]) {
                memo[i][j] = memo[i-1][j-1] + 1;
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    printf("%d\n", memo[a.size()][b.size()]);

    return 0;
}