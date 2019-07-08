#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    } else {
        vector<int> v1 (26, 0);
        vector<int> v2 (26, 0);
        for (int i=0; i<str1.length(); ++i) {
            v1[str1[i] - 'a'] += 1;
            v2[str2[i] - 'a'] += 1;
        }

        if (v1 == v2) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    string input;
    cin>>input;

    int totalLen = input.length();
    vector<int> dividers;
    
    int len = 1;
    while(1) {
        if (len > sqrt(totalLen)) {
            break;
        }

        if (totalLen % len == 0) {
            dividers.push_back(len);
            dividers.push_back(totalLen / len);
        }

        ++len;
    }
    
    sort(dividers.begin(), dividers.end());

    string answer = input;
    for (int i=0; i<dividers.size(); ++i) {
        string root = input.substr(0, dividers[i]);
        bool isSatisfied = true;
        for (int j=dividers[i]; j<=totalLen-dividers[i]; j+=dividers[i]) {
            string sub = input.substr(j, dividers[i]);
            if (!isAnagram(root, sub)) {
                isSatisfied = false;
                break;
            }
        }

        if (isSatisfied) {
            if (root.length() <= answer.length()) {
                answer = root;
            }
        }
    }

    if (answer.length() == input.length()) {
        cout<<-1<<"\n";
    } else {
        cout<<answer<<"\n";
    }

    return 0;
}