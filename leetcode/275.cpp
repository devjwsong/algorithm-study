#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 1) {
            if (citations[0] >= 1) return 1;
            return 0;
        }

        int left = 0, right = n-1;
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            if (n - mid <= citations[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (n - left <= citations[left]) return n - left;
        if (n - right <= citations[right] )return n - right;
        return 0;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> citations;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        citations.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->hIndex(citations);
    printf("%d\n", answer);

    return 0;
}