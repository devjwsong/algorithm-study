#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
vector<int> roots;
vector<int> ceils;

int main() {

    scanf("%d %d", &N, &H);
    roots.assign(N/2, 0);
    ceils.assign(N/2, 0);

    int max_h = 0;

    for (int i=0; i<N; ++i) {
        if (i % 2 == 0) {
            scanf("%d", &roots[i/2]);
            max_h = max(max_h, roots[i/2]);
        } else if (i % 2 == 1) {
            scanf("%d", &ceils[i/2]);
            max_h = max(max_h, ceils[i/2]);
        }
    }

    sort(roots.begin(), roots.end());
    sort(ceils.begin(), ceils.end());

    int count = 0;
    int result = 200001;

    for (int h=1; h<=H; ++h) {
        int root_idx = lower_bound(roots.begin(), roots.end(), h) - roots.begin();
        int ceil_idx = upper_bound(ceils.begin(), ceils.end(), H-h) - ceils.begin();

        int num_root = roots.size() - root_idx;
        int num_ceil = ceils.size() - ceil_idx;

        if (num_root < 0) {
            num_root = 0;
        }

        int value = num_root + num_ceil;
        if (result == value) {
            ++count;
        } else if (result > value) {
            count = 1;
            result = value;
        }
    }

    printf("%d %d\n", result, count);

    return 0;
}