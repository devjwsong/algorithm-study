#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int numTest = 0;
vector<int> results;

int tx[] = {0, -1, 0, 1}; // 0: 상, 1: 좌, 2: 하, 3: 우
int ty[] = {1, 0, -1, 0}; 

int dfs(vector<vector<int>>& map) {

    stack<vector<int>> s;

    int min_value = 9*map.size()*map.size();
    vector<int> initial = {0, 0, 2, 0};

    s.push(initial);

    while(!s.empty()) {

        vector<int> current = s.top();
        s.pop();

        cout<<current[0]<<" "<<current[1]<<" "<<current[2]<<" "<<current[3]<<" "<<min_value<<"\n";
        if (current[3]>100) {
            return 0;
        }

        if (current[0] == map.size()-1 && current[1] == map.size()-1) {
            if (min_value >= current[3]) {
                min_value = current[3];
            }
            continue;
        } else {
            for (int i=0; i<4; ++i) {
                if (i == (current[2]+2)%4) {
                    continue;
                } else {
                    int new_row = current[0] + ty[i];
                    int new_col = current[1] + tx[i];

                    if (!(new_row >= 0 && new_row <= 3) || !(new_col >= 0 && new_col <= 3)) {
                        continue;
                    } else {
                        int new_value = current[3] + map[new_row][new_col];
                        if (min_value >= new_value) {
                            vector<int> next = {new_row, new_col, i, new_value};
                            s.push(next);
                        }
                    }
                }
            }
        }
    }

    return min_value;
}

int main() {

    cin>>numTest;

    for (int test=1; test<=numTest; ++test) {
        int size = 0;
        cin>>size;

        vector<vector<int>> map;
        vector<int> values;

        for (int i=0; i<size; ++i) {
            vector<int> row;
            for (int j=0; j<size; ++j) {
                char input;
                cin>>input;
                row.push_back(input-'0');
            }
            map.push_back(row);
        }

        int result = dfs(map);
        results.push_back(result);
    }

    // for (int test=1; test<=numTest; ++test) {
    //     cout<<"#"<<test<<" "<<results[test-1]<<"\n";
    // }

    return 0;

}