#include <iostream>
#include <unordered_set>

using namespace std;


bool knows(int a, int b);


/*
Hash set.
One for loop rules out at least half of the candidates.
knows(a, b): true ---> a cannot be a celebrity.
knows(a, b): false ---> b cannot be a celebrity.
So we can leave only one candidate by keeping doing this.
Time: O(2n + nlogn) API calls.
Space: O(n).
*/
class Solution1 {
public:
    int findCelebrity(int n) {
        unordered_set<int> cands;
        for (int i=0; i<n; ++i) {
            cands.insert(i);
        }

        while (cands.size() > 1) {
            int a = *(cands.begin());
            for (int b=0; b<n; ++b) {
                if (b != a) {
                    if (knows(a, b)) {
                        cands.erase(a);
                        break;
                    } else {
                        cands.erase(b);
                    }
                }
            }
        }

        if (cands.size() == 0) return -1;

        int a = *(cands.begin());
        for (int b=0; b<n; ++b) {
            if (a != b) {
                if (knows(a, b) || !knows(b, a)) return -1;
            }
        }
        return a;
    }
};


/*
Simple two pass solution.
Actually, we don't need a hash set to rule out all candidates.
We can just leave out only one candidate with one iteration.
If cand survives the iteration, that means it can be only one possible candidate.
If cand cannot survive to a new node i, that means the nodes which cand has won cannot be the celebrity,
and cand cannot be the celebrity either.
So updating cand is valid.
Time: O(3n) API calls.
Space: O(1).
*/
class Solution2 {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for (int i=1; i<n; ++i) {
            if (knows(cand, i)) cand = i;
        }

        for (int i=0; i<n; ++i) {
            if (i != cand) {
                if (knows(cand, i) || !knows(i, cand)) return -1;
            }
        }

        return cand;
    }
};
