#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
int input[11][11];
int map[11][11];

vector<pair<int, int>> islands[7];

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

int num_island;
bool checked[7][7];

int root[7];

struct Edge {
    Edge(int _idx1, int _idx2, int _len) {
        idx1 = _idx1;
        idx2 = _idx2;
        len = _len;
    }

    int idx1;
    int idx2;
    int len;

    bool operator < (struct Edge &other) {
        return len < other.len;
    }
};

vector<struct Edge> edges;

void check_island(int start_row, int start_col, int idx) {
    queue<pair<int, int>> q;
    q.push({start_row, start_col});
    map[start_row][start_col] = idx;
    islands[idx].push_back({start_row, start_col});

    while(1) {
        if (q.empty()) {
            break;
        }

        pair<int, int> cur = q.front();
        q.pop();

        for (int d=0; d<4; ++d) {
            int next_r = cur.first + dir_r[d];
            int next_c = cur.second + dir_c[d];

            if (next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= M) {
                if (map[next_r][next_c] != idx && input[next_r][next_c] == 1) {
                    map[next_r][next_c] = idx;
                    q.push({next_r, next_c});
                    islands[idx].push_back({next_r, next_c});
                }
            }
        }
    }
}

bool isRowClear(int col, int row1, int row2) {
    int start = min(row1, row2)+1;
    int end = max(row1, row2)-1;
    for (int r=start; r<=end; ++r) {
        if (map[r][col] != 0) {
            return false;
        }
    }

    return true;
}

bool isColClear(int row, int col1, int col2) {
    int start = min(col1, col2)+1;
    int end = max(col1, col2)-1;
    for (int c=start; c<=end; ++c) {
        if (map[row][c] != 0) {
            return false;
        }
    }

    return true;
}

void make_bridge(int idx1, int idx2) {
    if (checked[idx1][idx2] || checked[idx2][idx1]) {
        return;
    }

    int len = INT_MAX;
    for (int i=0; i<islands[idx1].size(); ++i) {
        for (int j=0; j<islands[idx2].size(); ++j) {
            pair<int, int> cell1 = islands[idx1][i];
            pair<int, int> cell2 = islands[idx2][j];

            if (cell1.first != cell2.first && cell1.second != cell2.second) {
                continue;
            } else {
                if (cell1.first == cell2.first) {
                    int cand = abs(cell1.second-cell2.second)-1;
                    if (isColClear(cell1.first, cell1.second, cell2.second) && cand >= 2) {
                        len = min(len, cand);
                    }
                } else if (cell1.second == cell2.second) {
                    int cand = abs(cell1.first-cell2.first)-1;
                    if (isRowClear(cell1.second, cell1.first, cell2.first) && cand >= 2) {
                        len = min(len, cand);
                    }
                }
            }
        }
    }

    if (len == INT_MAX) {
        return;
    } else {
        struct Edge edge (min(idx1, idx2), max(idx1, idx2), len);
        edges.push_back(edge);
    }

    checked[idx1][idx2] = true;
    checked[idx2][idx1] = true;
}

int find(int a) {
    if (root[a] == a) {
        return a;
    } else {
        root[a] = find(root[a]);
        return root[a];
    }
}

void Union(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    if (root_a != root_b) {
        root[root_b] = root_a;
    }
}

int kruskal() {
    int sum = 0;
    int count = 0;

    for (int i=0; i<edges.size(); ++i) {
        struct Edge edge = edges[i];

        if (find(edge.idx1) == find(edge.idx2)) {
            continue;
        } else {
            sum += edge.len;
            ++count;
            Union(edge.idx1, edge.idx2);
        }

        if (count == num_island-1) {
            break;
        }
    }

    if (count < num_island-1) {
        return -1;
    } else {
        return sum;
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=M; ++c) {
            scanf("%d", &input[r][c]);
        }
    }

    int idx = 0;
    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=M; ++c) {
            if (input[r][c] == 1 && map[r][c] == 0) {
                ++idx;
                check_island(r, c, idx);
            }
        }
    }
    num_island = idx;

    for (int i=1; i<=num_island; ++i) {
        for (int j=i+1; j<=num_island; ++j) {
            make_bridge(i, j);
        }
    }

    sort(edges.begin(), edges.end());

    for (int i=1; i<=num_island; ++i) {
        root[i] = i;
    }

    int answer = kruskal();

    printf("%d\n", answer);

    return 0;
}