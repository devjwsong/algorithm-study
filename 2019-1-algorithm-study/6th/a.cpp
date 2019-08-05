#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int T;
vector<pair<int, int>> bases(3000);
vector<int> rs (3000);

vector<int> graph[3000];
bool checked[3000];

double getSquare(int r1, int c1, int r2, int c2) {
    return (r1-r2)*(r1-r2) + (c1-c2)*(c1-c2);
}

void dfs(int start) {
    stack<int> s;
    s.push(start);

    while(1) {
        if (s.empty()) {
            break;
        }

        int cur = s.top();
        s.pop();

        checked[cur] = true;

        for (int i=0; i<graph[cur].size(); ++i) {
            if (!checked[graph[cur][i]]) {
                s.push(graph[cur][i]);
            }
        }
    }
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int N;
        scanf("%d", &N);

        for (int i=0; i<N; ++i) {
            int r, c, R;
            scanf("%d %d %d", &r, &c, &R);

            bases[i] = {r, c};
            rs[i] = R;
        }

        int num = 0;


        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                if (getSquare(bases[i].first, bases[i].second, bases[j].first, bases[j].second)
                         <= (rs[i] + rs[j])*(rs[i] + rs[j])) {

                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int result = 0;

        for (int i=0; i<N; ++i) {
            if (!checked[i]) {
                ++result;
                dfs(i);
            }
        }    

        printf("%d\n", result);

        for (int i=0; i<3000; ++i) {
            checked[i] = false;
            graph[i].clear();
        }
    }

    return 0;
}