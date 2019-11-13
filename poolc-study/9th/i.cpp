#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<pair<int, int>> graph[10001];

pair<int, int> findMax(int start) {
    bool checked[n+1] = {false, };
    stack<pair<int, int>> s;
    s.push({start, 0});
    checked[start] = true;

    pair<int, int> result (1, 0);

    while(1) {
        if (s.empty()) {
            break;
        }

        pair<int, int> cur = s.top();
        s.pop();

        if (cur.second >= result.second) {
            result.second = cur.second;
            result.first = cur.first;
        }

        for (int i=0; i<graph[cur.first].size(); ++i) {
            if (!checked[graph[cur.first][i].first]) {
                s.push({graph[cur.first][i].first, cur.second + graph[cur.first][i].second});
                checked[graph[cur.first][i].first] = true;
            }
        }
    }

    return result;
}

int main() {

    scanf("%d", &n);

    for (int i=0; i<n-1; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    int max_node = findMax(1).first;
    int max_len = findMax(max_node).second;
    
    printf("%d\n", max_len);

    return 0;
}