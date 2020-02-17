#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;
vector<pair<string, int>> win;
vector<string> bought;

bool isMatch(string jackpot, string mine) {
    for (int i=0; i<jackpot.size(); ++i) {
        if (jackpot[i] == '*' || mine[i] == '*' || jackpot[i] == mine[i]) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}

int main() {

    cin>>T;

    for (int t=1; t<=T; ++t) {
        cin>>N>>M;

        win.assign(N, {"", 0});
        bought.assign(M, "");
        for (int n=0; n<N; ++n) {
            string num;
            int amount;
            cin>>num>>amount;

            win[n] = {num, amount};
        }

        for (int m=0; m<M; ++m) {
            string num;
            cin>>num;

            bought[m] = num;
        }

        int sum = 0;

        for (int m=0; m<M; ++m) {
            for (int n=0; n<N; ++n) {
                if (isMatch(bought[m], win[n].first)) {
                    sum += win[n].second;
                }
            }
        }

        cout<<"#"<<t<<" "<<sum<<"\n";

        win.clear();
        bought.clear();
    }

    return 0;
}