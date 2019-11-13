#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int N;
map<int, pair<string, int>> notes;
map<string, int> amounts;
set<string> display;

set<string> setDisplay() {
  int max_value = 0;
  for (map<string, int>::iterator i=amounts.begin(); i!=amounts.end(); ++i) {
    if (i->second >= max_value) {
      max_value = i->second;
    }
  }

  set<string> answer;

  for (map<string, int>::iterator i=amounts.begin(); i!=amounts.end(); ++i) {
    if (i->second == max_value) {
      answer.insert(i->first);
    }
  }

  return answer;
}

int main() {
  cin>>N;

  for (int i=0; i<N; ++i) {
    int day;
    string cow;
    int change;
    cin>>day>>cow>>change;

    notes.insert(pair<int, pair<string, int>> (day, pair<string, int> (cow, change)));
  }

  amounts.insert(pair<string, int> ("Bessie", 7));
  amounts.insert(pair<string, int> ("Elsie", 7));
  amounts.insert(pair<string, int> ("Mildred", 7));
  display.insert("Bessie");
  display.insert("Elsie");
  display.insert("Mildred");

  int max_amount = 7;
  int count = 0;

  for (map<int, pair<string, int>>::iterator iter=notes.begin(); iter!=notes.end(); ++iter) {
    string cow = iter->second.first;
    amounts[cow] += iter->second.second;

    set<string> next = setDisplay();

    if (display != next) {
      ++count;
      display = next;
    }
  }

  cout<<count<<"\n";

  return 0;
}