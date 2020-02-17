#include <iostream>
#include <map>
#include <vector>

using namespace std;

int T;
string input;
vector<map<char, long long>> memo;

int main() {

    cin>>T;
    for (int t=1; t<=T; ++t) {
        cin>>input;

        memo.assign(input.size(), map<char, long long> ());
        for (int i=0; i<input.size(); ++i) {
            if (i == 0) {
                ++memo[i][input[i]];
                if (i != input.size()-1) {
                    ++memo[i][input[i+1]];
                }
            } else if (i == input.size()-1) {
                ++memo[i][input[i-1]];
                ++memo[i][input[i]];
            } else {
                ++memo[i][input[i-1]];
                ++memo[i][input[i]];
                ++memo[i][input[i+1]];
            }
        }

        long long answer = memo[0].size();
        for (int i=1; i<input.size(); ++i) {
            answer *= memo[i].size();
            answer %= 1000000007;
        }

        printf("#%d %lld\n", t, answer);

        memo.clear();
    }

    return 0;
}