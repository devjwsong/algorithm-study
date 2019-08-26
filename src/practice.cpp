#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
// int dist[100][100];
// const int INF = 100; // 99 + 1
int map[100][100];

// void floyd_warshall(){
//     for (int i=0 ; i<n ; i++){
//         for (int j=0 ;j<n ; j++){
//             if (map[i][j] == 0) dist[i][j] = INF;
//             else dist[i][j] = 1;
//         }
//     }
//     for (int k=0 ; k<n ; k++){
//         for (int i=0 ; i<n ; i++){
//             for (int j=0 ; j<n ; j++){
//                 if (dist[i][j] > dist[i][k] + dist[k][j]){
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }
//     for (int i=0 ; i<n ; i++){
//         for (int j=0 ; j<n ; j++){
//             if (dist[i][j] == INF) cout<<"0 ";
//             else cout<<"1 ";
//         }
//         cout<<"\n";
//     }
// }


vector<int> adj[100];
bool visited[100];
int component[100];
int temp_comp = 0;

void dfs(int x){
    component[x] = temp_comp;
    visited[x] = true;
    for (int next: adj[x]){
        dfs(next);
    }
}

void search(){
    for (int i=0 ; i<n ; i++){
        visited[i] = false;
        component[i] = 0;
        for (int j=0 ; j<n ; j++){
            if (map[i][j] == 1) adj[i].push_back(j);
        }
    }

    for (int i=0 ; i<n ; i++){
        if (!visited[i]){
            temp_comp++;
            dfs(i);
        }
    }
    for (int i=0; i<n; i++) {
        cout<<component[i]<<"\n";
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (component[j] == component[i]) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

int main(){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }

    // floyd_warshall();
    search();

    return 0;
}