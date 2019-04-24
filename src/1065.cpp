#include <iostream>
#include <vector>

using namespace std;

bool isCorrect(int n) {
    vector<int> digits;

    while(1) {
        digits.push_back(n % 10);
        n = (n - n % 10) / 10;

        if (n == 0) {
            break;
        }
    }

    int d = digits[0] - digits[1];
    for (int i=1; i<digits.size()-1; ++i) {
        if (d != (digits[i] - digits[i+1])) {
            return false;
        }
    }

    return true;
}

int main() {

    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i=N; i>=1; --i) {
        bool value = isCorrect(i);
        if (value) {
            ++count;
        }
    }

    printf("%d\n", count);

    return 0;
}