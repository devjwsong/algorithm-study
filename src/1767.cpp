#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int numTest;
int n;
int map[12][12];
vector<pair<int,int>> cores;
vector<int> results;

struct State {
    int connected = 0;
    int line = 0;
    int checked[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //0: not connected, 1: 상,  2: 하, 3: 좌, 4: 우
};

bool allChecked(struct State current, int numCores) {
    for (int i=0; i<numCores; ++i) {
        if (current.checked[i] == -1) {
            return false;
        }
    }

    return true;
}

bool checkUp(struct State current, int currentCore, int numCore) {
    int myRow = cores[currentCore].first;
    int myCol = cores[currentCore].second;

    for (int i=0; i<numCore; ++i) {

        if (i != currentCore) {

            int row = cores[i].first;
            int col = cores[i].second;

            if (row < myRow) {
                if (col == myCol) {
                    return false;
                } else if (col < myCol) {
                    if (current.checked[i] == 4) {
                        return false;
                    }
                } else if (col > myCol) {
                    if (current.checked[i] == 3) {
                        return false;
                    }
                }
            }

        }
    }

    return true;
}

bool checkDown(struct State current, int currentCore, int numCore) {
    int myRow = cores[currentCore].first;
    int myCol = cores[currentCore].second;

    for (int i=0; i<numCore; ++i) {

        if (i != currentCore) {
            int row = cores[i].first;
            int col = cores[i].second;

            if (row > myRow) {
                if (col == myCol) {
                    return false;
                } else if (col < myCol) {
                    if (current.checked[i] == 4) {
                        return false;
                    }
                } else if (col > myCol) {
                    if (current.checked[i] == 3) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool checkLeft(struct State current, int currentCore, int numCore) {
    int myRow = cores[currentCore].first;
    int myCol = cores[currentCore].second;

    for (int i=0; i<numCore; ++i) {

        if (i != currentCore) {
            int row = cores[i].first;
            int col = cores[i].second;

            if (col < myCol) {
                if (row == myRow) {
                    return false;
                } else if (row < myRow) {
                    if (current.checked[i] == 2) {
                        return false;
                    }
                } else if (row > myRow) {
                    if (current.checked[i] == 1) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool checkRight(struct State current, int currentCore, int numCore) {
    
    int myRow = cores[currentCore].first;
    int myCol = cores[currentCore].second;

    for (int i=0; i<numCore; ++i) {

        if (i != currentCore) {
            int row = cores[i].first;
            int col = cores[i].second;

            if (col > myCol) {
                if (row == myRow) {
                    return false;
                } else if (row < myRow) {
                    if (current.checked[i] == 2) {
                        return false;
                    }
                } else if (row > myRow) {
                    if (current.checked[i] == 1) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}


int solve() {

    stack<struct State> s;
    struct State initial;

    for (int i=0; i<cores.size(); ++i) {
        if (cores[i].first == 0) {
            initial.checked[i] = 1;
            initial.connected += 1;
        } else if (cores[i].first == cores.size()-1) {
            initial.checked[i] = 2;
            initial.connected += 1;
        } else if (cores[i].second == 0) {
            initial.checked[i] = 3;
            initial.connected += 1;
        } else if (cores[i].second == cores.size()-1) {
            initial.checked[i] = 4;
            initial.connected += 1;
        }
    }

    s.push(initial);
    pair<int, int> max_value (initial.connected, initial.line);

    while(1) {

        if (s.empty()) {
            break;
        }

        struct State current = s.top();
        s.pop();

        if (allChecked(current, cores.size())) {
            if (max_value.first < current.connected) {
                max_value.first = current.connected;
                max_value.second = current.line;
            } else if (max_value.first == current.connected) {
                if (max_value.second > current.line) {
                    max_value.first = current.connected;
                    max_value.second = current.line;
                }
            }

            continue;
        }

        struct State next = current;
        int currentCore = -1;
        for (int i=0; i<cores.size(); ++i) {
            if (next.checked[i] == -1) {
                currentCore = i;
                break;
            }
        }

        struct State next_stay = next;
        next_stay.checked[currentCore] = 0;
        s.push(next_stay);

        if (checkUp(next, currentCore, cores.size())) {
            struct State next_up = next;
            next_up.checked[currentCore] = 1;
            next_up.connected += 1;
            next_up.line += (cores[currentCore].first-0);
            s.push(next_up);
        }

        if (checkDown(next, currentCore, cores.size())) {
            struct State next_down = next;
            next_down.checked[currentCore] = 2;
            next_down.connected += 1;
            next_down.line += (n-1-cores[currentCore].first);
            s.push(next_down);
        }

        if (checkLeft(next, currentCore, cores.size())) {
            struct State next_left = next;
            next_left.checked[currentCore] = 3;
            next_left.connected += 1;
            next_left.line += (cores[currentCore].second-0);
            s.push(next_left);
        }

        if (checkRight(next, currentCore, cores.size())) {
            struct State next_right = next;
            next_right.checked[currentCore] = 4;
            next_right.connected += 1;
            next_right.line += (n-1-cores[currentCore].second);
            s.push(next_right);
        }

    }

    return max_value.second;

}

int main() {
    scanf("%d", &numTest);

    for (int test=1; test<=numTest; ++test) {
        scanf("%d", &n);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int input = 0;
                scanf("%d", &input);
                map[i][j] = input;
                if (input == 1) {
                    cores.push_back(pair<int,int> (i, j));
                }
            }
        }

        results.push_back(solve());


        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                map[i][j] = 0;
            }
        }
        cores.clear();
        
    }

    for (int test=1; test<=numTest; ++test) {
        printf("#%d %d\n", test, results[test-1]);
    }

    return 0;
}