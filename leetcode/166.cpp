#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        long long nu = numerator;
        bool isPositive = true;
        if (nu > 0 && denominator > 0) {
            nu *= -1;
            denominator *= -1;
        } else if (nu > 0) {
            nu *= -1;
            isPositive = false;
        } else if (denominator > 0) {
            denominator *= -1;
            isPositive = false;
        }

        long long intPart = nu / denominator;
        string answer = to_string(intPart);

        nu -= (intPart * denominator);
        if (nu == 0) {
            if (!isPositive) answer.insert(0, "-");
            return answer; 
        }
        
        answer += ".";
        int count = 0;
        unordered_map<int, int> m;
        while (nu != 0) {
            ++count;
            nu *= 10;
            if (m.find(nu) != m.end()) {
                int numRep = count - m[nu];
                answer.insert(answer.size()-numRep, "(");
                answer += ")";
                if (!isPositive) answer.insert(0, "-");
                return answer;
            }

            m[nu] = count;
            long long q = nu / denominator;
            answer += to_string(q);
        
            nu -= (q * denominator);
        }

        if (!isPositive) answer.insert(0, "-");
        return answer;
    }
};


int main() {

    int numerator, denominator;
    scanf("%d %d", &numerator, &denominator);

    Solution* sol = new Solution();
    string answer = sol->fractionToDecimal(numerator, denominator);
    cout<<answer<<"\n";

    return 0;
}