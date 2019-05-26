#include <iostream>
#include <deque>

using namespace std;

int main() {

    int T;
    cin>>T;
    getchar();

    for (int test=0; test<T; ++test) {
        string func;
        getline(cin, func);

        int n;
        cin>>n;
        getchar();

        string input;
        getline(cin, input);

        deque<int> dq;

        string temp = "";
        int index = 0;
        while(1) {
            if (dq.size() == n) {
                break;
            }

            if (input[index] == '[') {
                ++index;
                continue;
            }

            if (input[index] == ',' || input[index] ==']') {
                dq.push_back(atoi(temp.c_str()));
                temp = "";
            } else {
                temp += input.substr(index, 1);
            }

            ++index;
        }

        bool normal = true; // 순서가 정상. false면 반대
        bool error = false;

        for (int i=0; i<func.size(); ++i) {
            if (func[i] == 'R') {
                normal = !normal;
            } else if (func[i] == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                } else {
                    if (normal) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                }
            }
        }

        if (error) {
            cout<<"error\n";
        } else {
            cout<<"[";

            while(!dq.empty()) {
                if (normal) {
                    cout<<dq.front();
                    dq.pop_front();
                } else {
                    cout<<dq.back();
                    dq.pop_back();
                }

                if (!dq.empty()) {
                    cout<<",";
                }
            }

            cout<<"]\n";
        }

    }

    return 0;
}