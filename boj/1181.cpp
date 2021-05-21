#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> words;

bool compare(string str1, string str2) {

    if (str1.size() == str2.size()) {
        int result = str1.compare(str2);
        if (result < 0) {
            return true;
        } else if (result > 0) {
            return false;
        } else {
            return false;
        }
    } else {
        return str1.size() < str2.size();
    }
}

int main() {

    int N;
    scanf("%d", &N);
    getchar();

    for (int i=0; i<N; ++i) {
        char str[51];
        scanf("%s", str);
        string input = str;
        words.push_back(input);
    }

    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (int i=0; i<words.size(); ++i) {
        printf("%s\n", words[i].c_str());
    }

    return 0;
}