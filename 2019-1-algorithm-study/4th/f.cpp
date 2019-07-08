#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> hs;
int arrows[1000001];

int main() {

    scanf("%d", &N);
    
    for (int i=0; i<N; ++i) {
        int input;
        scanf("%d", &input);
        hs.push_back(input);
    }

    int count = 0;

    for (int i=0; i<hs.size(); ++i) {
        if (arrows[hs[i]] == 0) {
            arrows[hs[i]] += 1;
            ++count;
        }

        arrows[hs[i]] -= 1;
        arrows[hs[i]-1] += 1;
    }

    printf("%d\n", count);

    return 0;
}