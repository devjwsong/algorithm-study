#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int root[10001];

struct Edge {
    Edge(int _w, int _a, int _b) {
        w = _w;
        a = _a;
        b = _b;
    }

    int w;
    int a;
    int b;

    bool operator < (struct Edge& other) {
        return w < other.w;
    }
};

vector<struct Edge> edges;

int Find(int a) {
    if (root[a] == a) {
        return a;
    } else {
        root[a] = Find(root[a]);
        return root[a];
    }
}

void Union(int a, int b) {
    int root_a = Find(a);
    int root_b = Find(b);
    if (root_a != root_b) {
        root[root_b] = root_a;
    }
}

int main() {

    scanf("%d %d", &V, &E);

    for (int e=1; e<=E; ++e) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        struct Edge edge (w, a, b);
        edges.push_back(edge);
    }

    for (int v=1; v<=V; ++v) {
        root[v] = v;
    }

    sort(edges.begin(), edges.end());

    int answer = 0;
    int count = 0;

    for (int i=0; i<edges.size(); ++i) {
        struct Edge cur = edges[i];
        
        if (Find(cur.a) == Find(cur.b)) {
            continue;
        } else {
            answer += cur.w;
            ++count;
            Union(cur.a, cur.b);
        }

        if (count == V-1) {
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}