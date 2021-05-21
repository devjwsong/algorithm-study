#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool nums[10000000] = {false, };

bool checked(vector<string>& found, string input) {
    bool value = false;

    for (int i=0; i<found.size(); ++i) {
        if (found[i] == input) {
            value = true;
            break;
        }
    }

    return value;
}

void count(vector<vector<string>>& map, bool nums[], int row, int col) {
    deque<vector<string>> q;
    vector<string> initial = {map[row][col], to_string(row), to_string(col)};

    q.push_front(initial);

    while(1) {
        if (q.size() == 0) {
            break;
        }

        string currentString = q.front()[0];
        int currentRow = stoi(q.front()[1]);
        int currentCol = stoi(q.front()[2]);
        q.pop_front();

        if (currentString.size() == 7) {
            if (!nums[stoi(currentString)]) {
                nums[stoi(currentString)] = true;
            }
            continue;
        }

        if (currentString.size() < 7) {
            if (currentRow != 0) {
                vector<string> next = {currentString + map[currentRow-1][currentCol], to_string(currentRow-1), to_string(currentCol)};
                q.push_front(next);
            }

            if (currentCol != 0) {
                vector<string> next = {currentString + map[currentRow][currentCol-1], to_string(currentRow), to_string(currentCol-1)};
                q.push_front(next);
            }

            if (currentRow != 3) {
                vector<string> next = {currentString + map[currentRow+1][currentCol], to_string(currentRow+1), to_string(currentCol)};
                q.push_front(next);
            }

            if (currentCol != 3) {
                vector<string> next = {currentString + map[currentRow][currentCol+1], to_string(currentRow), to_string(currentCol+1)};
                q.push_front(next);
            } 
        }
    }
}

int main() {

    vector<vector<string>> map;
    //vector<string> found;
    vector<int> results;

    int numTest = 0;
    cin>>numTest;

    for (int test=1; test<=numTest; ++test) {

        for (int row=0; row<4; ++row) {
            vector<string> line;
            for (int col=0; col<4; ++col) {
                string num;
                cin>>num;
                line.push_back(num);
            }
            map.push_back(line);
        }

        for (int i=0; i<map.size(); ++i) {
            for (int j=0; j<map[i].size(); ++j) {
                count(map, nums, i, j);
            }
        }

        int value = 0;
        for (int i=0; i<10000000; ++i) {
            if (nums[i]) {
                value += 1;
            }
        }

        results.push_back(value);

        map.clear();

        for (int i=0; i<10000000; ++i) {
            nums[i] = false;
        }
    }

    for (int test=1; test<=numTest; ++test) {
        cout<<"#"<<test<<" "<<results[test-1]<<"\n";
    }

    return 0;
}