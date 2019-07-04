#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int noteNum = 52;
int cowNum = 26;
vector<pair<int, int>> notes;

int charToInt(char c) {
  return c - 'A';
}

int main() {
  
  notes.assign(cowNum, pair<int, int> (-1, -1));
  string input;
  cin>>input;

  for (int i=0; i<input.size(); ++i) {
    if (notes[charToInt(input[i])].first == -1) {
      notes[charToInt(input[i])].first = i;
    } else {
      notes[charToInt(input[i])].second = i;
    }
  }

  int count = 0;

  for (int cow=0; cow<cowNum; ++cow) {
    set<int> check;
    for (int i=notes[cow].first+1; i<notes[cow].second; ++i) {
      if (charToInt(input[i]) > cow) {
        if (check.find(charToInt(input[i])) != check.end()) {
          check.erase(charToInt(input[i]));
        } else {
          check.insert(charToInt(input[i]));
        }
      }
    }
    count += check.size();
  }

  cout<<count<<"\n";

  return 0;
}
