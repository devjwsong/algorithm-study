#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> students;
int B, C;

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int input;
        scanf("%d", &input);
        students.push_back(input);
    }

    scanf("%d %d", &B, &C);

    long long count = 0;

    for (int i=0; i<students.size(); ++i) {
        int left = students[i] - B;
        ++count;

        if (left > 0) {
            if (left % C == 0) {
                count += (left/C);
            } else {
                count += (left/C + 1);
            }
        }
    }

    printf("%lld\n", count);

    return 0;
}