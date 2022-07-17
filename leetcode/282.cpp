#include <iostream>
#include <vector>

using namespace std;


/*
A few tricks! I don't need to calculate multiplication beforehand.
Subtracting previous value and then adding prev * current value can yield the same result.
Also, another trick is to handle a leading zero.
If the current location is '0', but there are another numbers behind it, the loop stops.
*/
class Solution {
public:
    vector<string> answer;
    string res;

    void solve(string& num, int target, int idx, long long soFar, long long prev) {
        if (idx == num.size()) {
            if (soFar == target) answer.push_back(res);
            return;
        }

        long long val = 0;
        string s;
        for (int i=idx; i<num.size(); ++i) {
            if (i > idx && num[idx] == '0') break;

            val = val * 10 + (num[i]-'0');
            s += num[i];

            if (idx == 0) {
                res += s;
                solve(num, target, i+1, val, val);
                res = res.substr(0, res.size()-s.size());
            } else {
                res += '+';
                res += s;
                solve(num, target, i+1, soFar + val, val);
                res = res.substr(0, res.size()-s.size());
                res.pop_back();

                res += '-';
                res += s;
                solve(num, target, i+1, soFar - val, -val);
                res = res.substr(0, res.size()-s.size());
                res.pop_back();

                res += '*';
                res += s;
                solve(num, target, i+1, soFar - prev + prev * val, prev * val);
                res = res.substr(0, res.size()-s.size());
                res.pop_back();
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0);
        return answer;
    }
};


int main() {

    string num;
    getline(cin, num);

    int target;
    cin>>target;

    Solution* sol = new Solution();
    vector<string> answer = sol->addOperators(num, target);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}