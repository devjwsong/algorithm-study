#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<char>> map;

int main() {

    cin>>T;

    for (int t=1; t<=T; ++t) {

        for (int r=0; r<3; ++r) {
            vector<char> row;
            string line;
            cin>>line;
            for (int c=0; c<3; ++c) {
                row.push_back(line[c]);
            }
            map.push_back(row);
        }

        char key;
        cin>>key;

        for (int r=0; r<3; ++r) {
            bool isFinished = false;
            for (int c=0; c<3; ++c) {
                if (map[r][c] == '-') {
                    map[r][c] = key;

                    bool checkRow = true;
                    for (int subC=0; subC<3; ++subC) {
                        if (map[r][subC] != key) {
                            checkRow = false;
                            break;
                        }
                    }
                    if (checkRow) {
                        isFinished = true;
                        break;
                    }

                    bool checkCol = true;
                    for (int subR=0; subR<3; ++subR) {
                        if (map[subR][c] != key) {
                            checkCol = false;
                            break;
                        }
                    }
                    if (checkCol) {
                        isFinished = true;
                        break;
                    }

                    bool checkCrsRight = true;
                    int subR = 0;
                    int subC = 0;
                    while(1) {
                        if (subR > 2 || subC > 2) {
                            break;
                        }

                        if (map[subR][subC] != key) {
                            checkCrsRight = false;
                            break;
                        }

                        ++subR;
                        ++subC;
                    }
                    if (checkCrsRight) {
                        isFinished = true;
                        break;
                    }

                    bool checkCrsLeft = true;
                    subR = 0;
                    subC = 2;
                    while(1) {
                        if (subR > 2 || subC < 0) {
                            break;
                        }

                        if (map[subR][subC] != key) {
                            checkCrsLeft = false;
                            break;
                        }

                        ++subR;
                        --subC;
                    }
                    if (checkCrsLeft) {
                        isFinished = true;
                        break;
                    }

                    map[r][c] = '-';
                }
            }

            if (isFinished) {
                break;
            }
        }

        cout<<"Case "<<t<<":"<<"\n";
        for (int r=0; r<3; ++r) {
            for (int c=0; c<3; ++c) {
                cout<<map[r][c];
            }
            cout<<"\n";
        }

        map.clear();

    }

    return 0;
}