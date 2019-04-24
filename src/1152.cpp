#include <iostream>
#include <vector>

using namespace std;

int main() {

    string input;
    getline(cin, input);

    vector<string> words;
    string word = "";

    if (input[0] == ' ') {
        input.erase(0, 1);
    }

    if (input[input.size()-1] == ' ') {
        input.erase(input.size()-1, 1);
    }

    for (int i=0; i<input.size(); ++i) {
        if (input[i] == ' ' || i == input.size()-1) {
            words.push_back(word);
            word = "";
        } else {
            word.append(1, input[i]);
        }
    }

    cout<<words.size()<<"\n";

    return 0;
}