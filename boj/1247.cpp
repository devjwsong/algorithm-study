#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <cmath>
#include <limits>
 
using namespace std;
 
int numTest = 0;
vector<int> results;
 
bool check(vector<int>& state, int index) {
    for (int i=2; i<state.size(); ++i) {
        if (index == state[i]) {
            return true;
        }
    }
 
    return false;
}
 
int dfs(pair<int, int>& company, pair<int, int>& home, pair<int, int> clients[], int numClient) {
    stack<vector<int>> s;
    s.push(vector<int> {-1, 0});

    int min = numeric_limits<int>::max();
 
    while (1) {
        if (s.empty()) {
            return min;
        }
 
        vector<int> current = s.top();
        s.pop();
         
        if (current.size() == numClient + 2) {
            current[1] += abs(home.first - clients[current[0]].first) + abs(home.second - clients[current[0]].second);
            if (min >= current[1]) {
                min = current[1];
            }
            continue;
        }
 
        for (int i=0; i<numClient; ++i) {
            if (!check(current, i)) {
                int value = 0;
                if (current[0] == -1) {
                    value = current[1] + abs(company.first - clients[i].first) + abs(company.second - clients[i].second);
                } else {
                    value = current[1] + abs(clients[i].first - clients[current[0]].first) + abs(clients[i].second - clients[current[0]].second);
                }

                if (min >= value) {
                    vector<int> next = current;
                    next[0] = i;
                    next[1] = value;
                    next.push_back(i);
                    s.push(next);
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &numTest);
 
    for (int test=1; test<=numTest; ++test) {
 
        int numClient = 0;
        scanf("%d", &numClient);
 
        pair<int,int> company;
        pair<int,int> home;
 
        pair<int,int> clients[numClient];
 
        for (int i=0; i<numClient+2; ++i) {
            if (i==0) {
                scanf(" %d %d", &company.first, &company.second);
            } else if (i==1) {
                scanf(" %d %d", &home.first, &home.second);
            } else {
                scanf(" %d %d", &clients[i-2].first, &clients[i-2].second);
            }
        }
 
        results.push_back(dfs(company, home, clients, numClient));
 
    }

    for (int test=1; test<=numTest; ++test) {
        printf("#%d %d\n", test, results[test-1]);
    }
 
    return 0;
}