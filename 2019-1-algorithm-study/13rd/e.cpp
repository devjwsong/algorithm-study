#include <iostream>
#include <vector>

using namespace std;

int T;
string memo[10][81]; // 시작이 i이고 전체 자릿수가 d인 증가하는 수 개수

string add(string s1, string s2) {
    int N = max(s1.size(), s2.size());
    int s1Padding = N - s1.size();
    int s2Padding = N - s2.size();

    for (int i=1; i<=s1Padding; ++i) {
        s1 = "0" + s1;
    }

    for (int i=1; i<=s2Padding; ++i) {
        s2 = "0" + s2;
    }

    string answer = "";

    int next = 0;
    for (int i=N-1; i>=0; --i) {
        int value = (s1[i]-'0') + (s2[i]-'0');
        value += next;

        if (value >= 10) {
            next = value / 10;
            value %= 10;
        } else {
            next = 0;
        }

        answer = to_string(value) + answer;
    }

    if (next > 0) {
        answer = to_string(next) + answer;
    }

    return answer;
}

string getInc(int start, int digits) {
    string ret = "0";

    if (memo[start][digits] != "") {
        ret = memo[start][digits];
    } else {
        if (digits == 1) {
            ret = "1";
        } else {
            for (int i=start; i<10; ++i) {
                ret = add(ret, getInc(i, digits-1)); 
            }
        }
        memo[start][digits] = ret;
    }

    return ret;
}

bool isInc(string num) {
    for (int i=0; i<num.size()-1; ++i) {
        if (num[i] > num[i+1]) {
            return false;
        }
    }

    return true;
}

int main() {

    cin>>T;

    for (int t=1; t<=T; ++t) {
        string input;
        cin>>input;

        string answer = "-1";
        if (isInc(input)) {
            if (input.size() > 1) {
                answer = "1";
                for (int d=1; d<input.size(); ++d) {
                    for (int s=1; s<10; ++s) {
                        answer = add(answer, getInc(s, d));
                    }
                }

                for (int i=0; i<input.size(); ++i) {
                    int prev = 1;
                    if (i > 0) {
                        prev = input[i-1]-'0';
                    }

                    for (int s=prev; s<(input[i]-'0'); ++s) {
                        answer = add(answer, getInc(s, input.size()-i));
                    }
                }
            } else {
                answer = to_string(input[0]-'0');
            }
        }

        cout<<answer<<"\n";
    }

    return 0;
}