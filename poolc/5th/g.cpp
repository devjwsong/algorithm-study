#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> seq;

int main() {

    scanf("%d", &N);

    seq.assign(N, 0);

    for (int i=0; i<N; ++i) {
        scanf("%d", &seq[i]);
    }

    int gNum = 1;
    int point = -1;
    for (int i=0; i<N-1; ++i) {
        if (seq[i+1] < seq[i]) {
            ++gNum;
            point = i;
        }
    }

    int count = 0;

    if (gNum > 2) {
        count = 0;
    } else {
        if (gNum == 1) {
            count = seq.size();
        } else {
            vector<int> left;
            vector<int> right;

            for (int i=0; i<N; ++i) {
                if (i <= point) {
                    left.push_back(seq[i]);
                } else {
                    right.push_back(seq[i]);
                }
            }

            if (left.size() == 1) {
                ++count;
            } else {
                if (left[left.size()-2] <= right[0]) {
                    ++count;
                }
            }
            
            if (right.size() == 1) {
                ++count;
            } else {
                if (left[left.size()-1] <= right[1]) {
                    ++count;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}