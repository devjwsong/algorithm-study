#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while (left <= right) {
            swap(s[left++], s[right--]);
        }
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<char> s;
    for (int i=0; i<n; ++i) {
        char c;
        scanf(" %c", &c);
        s.push_back(c);
    }

    Solution* sol = new Solution();
    sol->reverseString(s);
    for (int i=0; i<n; ++i) {
        printf("%c ", s[i]);
    }
    printf("\n");

    return 0;
}