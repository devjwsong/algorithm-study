#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    stack<int> s;
    vector<char> answer;
    int check = 0;

    for (int i=0; i<n; ++i) {
        int input;
        scanf("%d", &input);

        if (s.size() == 0) {
            if (check < input) {
                for (int i=check+1; i<=input; ++i) {
                    s.push(i);
                    answer.push_back('+');
                    ++check;
                }
                s.pop();
                answer.push_back('-');
            } else {
                answer.clear();
                answer.push_back('X');
                break;
            }
        } else {
            if (s.top() == input) {
                s.pop();
                answer.push_back('-');
            } else {
                if (check < input) {
                    for (int i=check+1; i<=input; ++i) {
                        s.push(i);
                        answer.push_back('+');
                        ++check;
                    }
                    s.pop();
                    answer.push_back('-');
                } else {
                    answer.clear();
                    answer.push_back('X');
                    break;
                }
            }
        }
    }

    if (answer.size() == 1 && answer[0] == 'X') {
        printf("NO\n");
    } else {
        for (int i=0; i<answer.size(); ++i) {
            printf("%c\n", answer[i]);
        }
    }


    return 0;
}