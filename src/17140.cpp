#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
vector<vector<int>> A;

void cal_row() {
    for (int r=1; r<A.size(); ++r) {
        vector<int> col = A[r];
        map<int, int> count;
        for (int c=1; c<A[r].size(); ++c) {
            if (A[r][c] != 0) {
                ++count[A[r][c]];
            }
        }

        vector<pair<int, int>> tmp;
        for (map<int, int>::iterator i=count.begin(); i != count.end(); ++i) {
            pair<int, int> cell (i->second, i->first);
            tmp.push_back(cell);
        }

        sort(tmp.begin(), tmp.end());
        vector<int> new_col;
        new_col.push_back(0);
        for (int i=0; i<tmp.size(); ++i) {
            new_col.push_back(tmp[i].second);
            new_col.push_back(tmp[i].first);
        }

        A[r] = new_col;
    }

    int max_num = 0;
    for (int r=0; r<A.size(); ++r) {
        max_num = max(max_num, (int) A[r].size());
        if (A[r].size() > 101) {
            max_num = 101;
            break;
        }
    }

    for (int r=0; r<A.size(); ++r) {
        if (A[r].size() < max_num) {
            int diff = max_num - A[r].size();
            while(diff-->0) {
                A[r].push_back(0);
            }
        } else {
            vector<int> new_col;
            for (int c=0; c<max_num; ++c) {
                new_col.push_back(A[r][c]);
            }
            A[r] = new_col;
        }
    }
}

void transpose() {
    vector<vector<int>> cpy;
    for (int c=0; c<A[0].size(); ++c) {
        vector<int> row;
        for (int r=0; r<A.size(); ++r) {
            row.push_back(A[r][c]);
        }
        cpy.push_back(row);
    }

    A = cpy;
}

void cal_col() {
    transpose();
    cal_row();
    transpose();
}

int main() {

    scanf("%d %d %d", &r, &c, &k);

    A.assign(4, vector<int> (4, 0));
    for (int r=1; r<=3; ++r) {
        for (int c=1; c<=3; ++c) {
            scanf("%d", &A[r][c]);
        }
    }

    int answer = 0;

    while(1) {
        if (r < A.size() && c < A[0].size() && A[r][c] == k) {
            break;
        }

        ++answer;
        if (answer > 100) {
            answer = -1;
            break;
        }

        if (A.size()-1 >= A[1].size()-1) {
            cal_row();
        } else {
            cal_col();
        }
    }

    printf("%d\n", answer);

    return 0;
}