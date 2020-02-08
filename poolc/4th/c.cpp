#include <iostream>

using namespace std;

int memo[4][14]; // P:0, K:1, H:2, T:3

int main() {
  
  string input;
  getline(cin, input);

  bool GRESKA = false; 

  for (int i=0; i<input.length(); i+=3) {
    string card = input.substr(i, 3);
    int shape = -1;
    if (card[0] == 'P') {
      shape = 0;
    } else if (card[0] == 'K') {
      shape = 1;
    } else if (card[0] == 'H') {
      shape = 2;
    } else if (card[0] == 'T') {
      shape = 3;
    }
    
    int num = -1;
    if (card[1] != '0') {
      num = atoi(card.substr(1, 2).c_str());
    } else {
      num = atoi(card.substr(2, 2).c_str());
    }

    if (memo[shape][num] == 1) {
      GRESKA = true;
      break;
    } else {
      memo[shape][num] = 1;
    }
  }

  if (GRESKA) {
    cout<<"GRESKA"<<"\n";
  } else {
    for (int i=0; i<4; ++i) {
      int count = 0;
      for (int j=1; j<=13; ++j) {
        if (memo[i][j] == 0) {
          ++count;
        }
      }

      cout<<count<<" ";
    }
    cout<<"\n";
  }

  return 0;
}