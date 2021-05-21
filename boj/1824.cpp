#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int numTest;
bool checked[2020416] = {false, };
vector<string> results;

bool finished(int numRow, int numCol) {
    int length = numRow * 100000 + numCol * 1000 + 415;
    for (int i=0; i<length+1; ++i) {
        if (!checked[i]) {
            return false;
        }
    }

    return true;
}

void move(vector<vector<char>>& commands, vector<int>& state) {
    if (state[2] == 1) { //up
        if (state[0] == 0) {
            state[0] = commands.size() - 1;
        } else  {
            state[0] -= 1;
        }
    } else if (state[2] == 2) { // down
        if (state[0] == commands.size() - 1) {
            state[0] = 0;
        } else {
            state[0] += 1;
        }
    } else if (state[2] == 3) { // left
        if (state[1] == 0) {
            state[1] = commands[0].size() - 1;
        } else  {
            state[1] -= 1;
        }
    } else if (state[2] == 4) { // right
        if (state[1] == commands[0].size() - 1) {
            state[1] = 0;
        } else  {
            state[1] += 1;
        }
    }
}

bool execute(vector<vector<char>>& commands) {
    deque<vector<int>> q;

    bool value = false;
    int direction = 4; // up: 1, down: 2, left: 3, right: 4
    int memory = 0;
    vector<int> initial = {0, 0, direction, memory}; //{row, col, direction, memory}

    q.push_back(initial);

    while(1) {

        if (q.size() == 0) {
            break;
        }

        vector<int> state = q.front();
        q.pop_front();

        int index = state[0] * 100000 + state[1] * 1000 + state[2] * 100 + state[3];

        bool is_finished = finished(commands.size(), commands[0].size());

        if (checked[index]) {
            continue;
        } else {
            checked[index] = true;
        }

        if (commands[state[0]][state[1]] == '@') {
            value = true;
            break;
        }

        if (commands[state[0]][state[1]] != '.') {
            if (commands[state[0]][state[1]] == '<') {

                state[2] = 3;
                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '>') {

                state[2] = 4;
                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '^') {

                state[2] = 1;
                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == 'v') {

                state[2] = 2;
                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '_') {

                if (state[3] == 0) {
                    state[2] = 4;
                } else  {
                    state[2] = 3;
                }

                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '|') {

                if (state[3] == 0) {
                    state[2] = 2;
                } else  {
                    state[2] = 1;
                }

                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] >= 48 && commands[state[0]][state[1]] <= 57) {
                
                state[3] = commands[state[0]][state[1]] - '0';
                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '+') {

                if (state[3] == 15) {
                    state[3] = 0;
                } else {
                    state[3] += 1;
                }

                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '-') {

                if (state[3] == 0) {
                    state[3] = 15;
                } else {
                    state[3] -= 1;
                }

                move(commands, state);
                q.push_back(state);

            } else if (commands[state[0]][state[1]] == '?') {

                vector<int> up = state;
                vector<int> down = state;
                vector<int> left = state;
                vector<int> right = state;

                up[2] = 1;
                move(commands, up);
                q.push_back(up);

                down[2] = 2;
                move(commands, down);
                q.push_back(down);

                left[2] = 3;
                move(commands, left);
                q.push_back(left);

                right[2] = 4;
                move(commands, right);
                q.push_back(right);

            }
        } else  {
            move(commands, state);
            q.push_back(state);
        }

    }

    return value;
}

int main() {
    cin>>numTest;

    for (int test=1; test<=numTest; ++test) {
        int r, c;
        cin>>r>>c;

        vector<vector<char>> commands;
        int memory = 0;

        for (int i=0; i<r; ++i) {
            vector<char> row;
            for (int j=0; j<c; ++j) {
                char input;
                cin>>input;
                row.push_back(input);
            }
            commands.push_back(row);
        }

        bool result = execute(commands);

        if (result) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }

        for (int i=0; i<2020416; ++i) {
            checked[i] = false;
        }
    }

    for (int test=1; test<=numTest; ++test) {
        cout<<"#"<<test<<" "<<results[test-1]<<"\n";
    }

    return 0;
}