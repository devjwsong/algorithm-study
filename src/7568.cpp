#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> people;

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int w, h;
        scanf("%d %d", &w, &h);
        people.push_back({w, h});
    }

    vector<int> answer;

    for (int i=0; i<N; ++i) {
        int count = 0;
        for (int j=0; j<N; ++j) {
            if (i != j) {
                if (people[i].first < people[j].first && people[i].second < people[j].second) {
                    ++count;
                }
            }
        }

        answer.push_back(count+1);
    }

    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}