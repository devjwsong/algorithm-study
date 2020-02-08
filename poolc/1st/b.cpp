#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int NUM_COW = 7;
vector<int> amounts;

string cows[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main() {

  cin>>N;
  getchar();
  amounts.assign(NUM_COW, 0);

  for (int i=0; i<N; ++i) {
    string input;
    getline(cin, input);

    string cow;
    int amount;
    int length = 0;

    for (int j=1; j<input.length()+1; ++j) {
      if (input[j] == ' ') {
        length = j;
      }
    }

    cow = input.substr(0, length);
    amount = atoi(input.substr(length+1, input.length()-length-1).c_str());

    for (int j=0; j<NUM_COW; ++j) {
      if (cows[j].compare(cow) == 0) {
        amounts[j] += amount;
      }
    }
  }

  vector<int> copy = amounts;
  sort(copy.begin(), copy.end());

  copy.erase(unique(copy.begin(), copy.end()), copy.end());

  int s = copy[1];

  int count = 0;
  string answer = "";

  for (int j=0; j<NUM_COW; ++j) {
    if (amounts[j] == s) {
      ++count;
      answer = cows[j];

      if (count > 1) {
        answer = "Tie";
        break;
      }
    }
  }

  cout<<answer<<"\n";

  return 0;
}