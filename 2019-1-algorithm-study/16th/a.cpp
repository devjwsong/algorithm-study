#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> seq;
int M;

bool search(int target, int left, int right) {
    if (left == right || left+1 == right) {
        if (seq[left] == target) {
            return true;
        } else {
            return false;
        }
    }

    int mid = (left + right) / 2;

    if (seq[mid] == target) {
        return true;
    } else if (seq[mid] > target) {
        return search(target, left, mid);
    } else if (seq[mid] < target) {
        return search(target, mid, right);
    }
}

int main() {

    scanf("%d", &N);
    seq.assign(N, 0);

    for (int i=0; i<N; ++i) {
        scanf("%d", &seq[i]);
    }

    scanf("%d", &M);

    sort(seq.begin(), seq.end());

    for (int i=0; i<M; ++i) {
        int target;
        scanf("%d", &target);

        bool result = search(target, 0, N);
        if (result) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}