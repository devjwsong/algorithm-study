#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i=1; i<=n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
            } else if (i % 5 == 0) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(to_string(i));
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    vector<string> answer = sol->fizzBuzz(n);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}