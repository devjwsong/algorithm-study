#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

int N;
vector<vector<int>> table;
vector<int> graph[21];

int getScore(vector<int> group) {
    int count = 0;

    for (int i=0; i<group.size(); ++i) {
        for (int j=i+1; j<group.size(); ++j) {
            count += (table[group[i]][group[j]] + table[group[j]][group[i]]);
        }
    }

    return count;

}

struct State {

    int count;
    int last;
    vector<int> group;

};

int dfs() {
    int answer = INT_MAX;

    vector<int> group (N+1, 0);
    group[1] = 1;

    stack<struct State> s;
    struct State init;
    init.count = 1;
    init.group = group;
    init.last = 1;
    s.push(init);

    while(1) {
        if (s.empty()) {
            break;
        }

        struct State cur = s.top();
        s.pop();

        if (cur.count == N/2) {
            vector<int> start;
            vector<int> link;
            for (int i=1; i<=N; ++i) {
                if (cur.group[i] == 1) {
                    start.push_back(i);
                } else {
                    link.push_back(i);
                }
            }

            int value = abs(getScore(start) - getScore(link));

            if (value <= answer) {
                answer = value;
            }
        } else {
            for (int i=0; i<graph[cur.last].size(); ++i) {
                struct State next;
                next.count = cur.count + 1;
                next.last = graph[cur.last][i];
                next.group = cur.group;
                next.group[graph[cur.last][i]] = 1;

                s.push(next);
            }
        }
    }

    return answer;
}

int main() {
    scanf("%d", &N);

    table.assign(N+1, vector<int> (N+1, 0));
    int sum = 0;

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            int input;
            scanf("%d", &input);
            table[i][j] = input;
        }
    }
    
    for (int i=1; i<=N; ++i) {
        for (int j=i+1; j<=N; ++j) {
            graph[i].push_back(j);
        }
    }

    int answer = dfs();
    
    printf("%d\n", answer);

    return 0;
}