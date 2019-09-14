#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> nodes[], bool checked[], int start) {
    deque<int> q;
    q.push_back(start);

    while(1) {
        if (q.size() == 0) {
            cout<<endl;
            return;
        }

        if (checked[q.front()]) {
            q.pop_front();
            continue;
        }

        int current = q.front();
        cout<<current<<" ";

        checked[current] = true;
        q.pop_front();
        
        for (int i=nodes[current].size()-1; i>=0; --i) {
            q.push_front(nodes[current][i]);
        }
    }

}

void bfs(vector<int> nodes[], bool checked[], int start) {
    deque<int> q;
    q.push_back(start);

    while(1) {
        if (q.size() == 0) {
            cout<<endl;
            return;
        }

        if (checked[q.front()]) {
            q.pop_front();
            continue;
        }

        int current = q.front();
        cout<<current<<" ";

        checked[current] = true;
        q.pop_front();
        
        for (int i=0; i<nodes[current].size(); ++i) {
            q.push_back(nodes[current][i]);
        }
    }

}

int main() {
    int n, m, start = 0;
    cin>>n>>m>>start;
    vector<int> nodes_dfs[n+1];
    vector<int> nodes_bfs[n+1];
    bool checked_dfs[n+1] = {false,};
    bool checked_bfs[n+1] = {false,};

    for (int i=0; i<m; ++i) {
        int a, b = 0;
        cin>>a>>b;
        nodes_dfs[a].push_back(b);
        nodes_dfs[b].push_back(a);
        nodes_bfs[a].push_back(b);
        nodes_bfs[b].push_back(a);
    }

    for (int i=1; i<n+1; ++i) {
        sort(nodes_dfs[i].begin(), nodes_dfs[i].end());
        sort(nodes_bfs[i].begin(), nodes_bfs[i].end());
    }

    dfs(nodes_dfs, checked_dfs, start);
    bfs(nodes_bfs, checked_bfs, start);

    return 0;
}