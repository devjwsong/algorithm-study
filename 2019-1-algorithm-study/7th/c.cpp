#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

map<int, int> first;
map<int, int> second;
set<int> results;

struct State {
    State(int _first, int _day) {
        first = _first;
        day = _day;
    }

    int first;
    map<int, int> firstBuckets;
    map<int, int> secondBuckets;
    int day;
};

void dfs() {
    stack<struct State> s;
    struct State init (1000, 0);
    init.firstBuckets = first;
    init.secondBuckets = second;
    
    s.push(init);

    while(1) {
        if (s.empty()) {
            break;
        }

        struct State cur = s.top();
        s.pop();

        if (cur.day == 4) {
            results.insert(cur.first);
            continue;
        }

        if (cur.day % 2 == 1) {
            for (map<int, int>::iterator fiter=cur.firstBuckets.begin(); fiter!=cur.firstBuckets.end(); ++fiter) {
                if (cur.firstBuckets[fiter->first] > 0) {
                    int nextAmount = cur.first - fiter->first;
                    map<int, int> newF = cur.firstBuckets;
                    map<int, int> newS = cur.secondBuckets;
                    --newF[fiter->first];

                    if (newS.find(fiter->first) == newS.end() || newS[fiter->first] <= 0) {
                        newS[fiter->first] = 1;
                    } else {
                        ++newS[fiter->first];
                    }

                    struct State newState (nextAmount, cur.day+1);
                    newState.firstBuckets = newF;
                    newState.secondBuckets = newS;

                    s.push(newState);
                }
            }
        } else if (cur.day % 2 == 0) {
            for (map<int, int>::iterator siter=cur.secondBuckets.begin(); siter!=cur.secondBuckets.end(); ++siter) {
                if (cur.secondBuckets[siter->first] > 0) {
                    int nextAmount = cur.first + siter->first;
                    map<int, int> newF = cur.firstBuckets;
                    map<int, int> newS = cur.secondBuckets;
                    --newS[siter->first];

                    if (newF.find(siter->first) == newF.end() || newF[siter->first] <= 0) {
                        newF[siter->first] = 1;
                    } else {
                        ++newF[siter->first];
                    }

                    struct State newState (nextAmount, cur.day+1);
                    newState.firstBuckets = newF;
                    newState.secondBuckets = newS;

                    s.push(newState);
                }
            } 
        }
    }
}

int main() {

    for (int i=0; i<10; ++i) {
        int input;
        scanf("%d", &input);

        if (first.find(input) == first.end()) {
            first[input] = 1;
        } else {
            ++first[input];
        }
    }

    for (int i=0; i<10; ++i) {
        int input;
        scanf("%d", &input);

        if (second.find(input) == second.end()) {
            second[input] = 1;
        } else {
            ++second[input];
        }
    }

    
    results.insert(1000);

    dfs();

    printf("%lu\n", results.size());

    return 0;
}