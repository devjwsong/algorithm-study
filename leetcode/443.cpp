#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) return 1;

        int i = 0, idx = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[j] == chars[i]) {
                ++j;
            }

            chars[idx] = chars[i];
            ++idx;

            int count = j - i;
            if (count > 1) {
                string num = to_string(count);
                for (int k=0; k<num.size(); ++k) {
                    chars[idx] = num[k];
                    ++idx;
                }
            }

            i = j;
        }

        return idx;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<char> chars;
    for (int i=0; i<n; ++i) {
        char c;
        scanf(" %c", &c);
        chars.push_back(c);
    }

    Solution* sol = new Solution();
    int answer = sol->compress(chars);
    printf("%d\n", answer);

    return 0;
}