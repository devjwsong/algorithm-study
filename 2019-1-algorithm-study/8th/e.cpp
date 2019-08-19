#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<struct Cow> cows;
priority_queue<struct Cow, vector<struct Cow>, greater<struct Cow>> q;

struct Cow {
    Cow(int _a, int _t, int _p) {
        a = _a;
        t = _t;
        p = _p;
    }

    int a;
    int t;
    int p;

    bool operator >(const struct Cow& other) const {
        return p > other.p;
    }
};

bool isFirst(struct Cow cow1, struct Cow cow2) {
    if (cow1.a < cow2.a) {
        return true;
    } else {
        if (cow1.a == cow2.a && cow1.p < cow2.p) {
            return true;
        }
    }

    return false;
}

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        int a, t;
        scanf("%d %d", &a, &t);
        struct Cow cow(a, t, i);
        cows.push_back(cow);
    }

    sort(cows.begin(), cows.end(), isFirst);

    int wait = 0;
    int idx = 0;
    int end = 0;

    while(1) {

        if (idx >= N) {
            break;
        }

        if (end == 0) {
            end = cows[idx].a + cows[idx].t;
            ++idx;
        } else {
            if (cows[idx].a <= end) {
                q.push(cows[idx]);
                ++idx;
            } else {
                if (q.empty()) {
                    end = cows[idx].a + cows[idx].t;
                    ++idx;
                } else {
                    struct Cow next = q.top();
                    wait = max(wait, end - next.a);
                    end += next.t;
                    q.pop();
                }
            }
        }

    }


    printf("%d\n", wait);

    return 0;
}