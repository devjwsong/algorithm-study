#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<int> nums;
vector<int> colors;

bool possible = false;

bool is_set(vector<pair<int, int>> group) {
    sort(group.begin(), group.end());

    if (group[0].second == group[1].second && group[1].second == group[2].second) {
        if ((group[0].first == group[1].first && group[1].first == group[2].first) 
                || (group[0].first + 1 == group[1].first && group[1].first + 1 == group[2].first)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
} 

void make_set(int idx, vector<vector<pair<int, int>>> cur) {
    if (idx < 9) {
        for (int s=0; s<cur.size(); ++s) {
            if (cur[s].size() < 3) {
                vector<vector<pair<int, int>>> next = cur;
                next[s].push_back({nums[idx], colors[idx]});
                make_set(idx+1, next);
            }
        }
    } else {

        // for (int s=0; s<cur.size(); ++s) {
        //     for (int i=0; i<cur[s].size(); ++i) {
        //         cout<<"("<<cur[s][i].first<<", "<<cur[s][i].second<<")";
        //     }
        //     cout<<" | ";
        // }
        // cout<<endl;

        int num = 0;
        for (int s=0; s<cur.size(); ++s) {
            if (is_set(cur[s])) {
                ++num;
            }
        }

        if (num == 3) {
            possible = true;
        }
    }
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        nums.assign(9, 0);
        colors.assign(9, 0);

        for (int n=0; n<9; ++n) {
            scanf("%1d", &nums[n]);
        }

        for (int n=0; n<9; ++n) {
            cout<<nums[n]<<" ";
        }
        cout<<endl;

        for (int c=0; c<9; ++c) {
            char ch;
            scanf(" %c", &ch);
            if (ch == 'R') {
                colors[c] = 0;
            } else if (ch == 'G') {
                colors[c] = 1;
            } else {
                colors[c] = 2;
            }
        }

        for (int c=0; c<9; ++c) {
            cout<<colors[c]<<" ";
        }
        cout<<endl;

        vector<vector<pair<int, int>>> init (3, vector<pair<int, int>>());
        make_set(0, init);

        if (possible) {
            printf("#%d Win\n", t);
        } else {
            printf("#%d Continue\n", t);
        }

        nums.clear();
        colors.clear();
        possible = false;
    }

    return 0;
}