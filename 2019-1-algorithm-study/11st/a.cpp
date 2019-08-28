#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> mats;

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        mats.push_back({a, b});
    } 

    

    return 0;
}