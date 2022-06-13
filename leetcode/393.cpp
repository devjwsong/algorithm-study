#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int getNumBytes(int val) {
        if (val < 128) return 1;
        if (val >= 192 && val < 224) return 2;
        if (val >= 224 && val < 240) return 3;
        if (val >= 240 && val < 248) return 4;

        return -1;
    }

    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int numBytes = -1, count = 0;
        for (int i=0; i<n; ++i) {
            if (numBytes == -1) {
                numBytes = getNumBytes(data[i]);
                if (numBytes == -1) return false;
                
                if (numBytes == 1) {
                    numBytes = -1;
                    count = 0 ;
                } else {
                    ++count;
                }
            } else {
                if (data[i] >= 128 && data[i] < 192) {
                    ++count;
                } else {
                    return false;
                }

                if (count == numBytes) {
                    numBytes = -1;
                    count = 0;
                }
            }
        }

        if (numBytes > 0 && count > 0) return false;
        return true;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> data;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        data.push_back(val);
    }

    Solution* sol = new Solution();
    bool answer = sol->validUtf8(data);
    printf("%d\n", answer);

    return 0;
}