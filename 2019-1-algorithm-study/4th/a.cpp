#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int wheelNum = 4;
const int toothNum = 8;
deque<int> wheels[wheelNum+1];

int K;

void rotate(int wheel, int dir) {
  if (dir == 1) { // 시계
    int back = wheels[wheel].back();
    wheels[wheel].pop_back();
    wheels[wheel].push_front(back);
  } else if (dir == -1) { // 반시계
    int front = wheels[wheel].front();
    wheels[wheel].pop_front();
    wheels[wheel].push_back(front);
  }
}

int getLeft(int wheel) {
  deque<int> cpy = wheels[wheel];
  cpy.pop_back();
  return cpy.back();
}

int getRight(int wheel) {
  deque<int> cpy = wheels[wheel];
  cpy.pop_front();
  cpy.pop_front();
  return cpy.front();
}

void leftSetting(int wheel, int dir) {
  int wheelLeft = wheel;
  int dirLeft =dir;
  for (int w=wheel; w>=1; --w) {
    rotate(w, dir);

  }
}

void rightSetting(int wheel, int dir) {
  int wheelRight = wheel;
  int dirRight = dir;
  for (int w = wheelRight+1; w<=wheelNum; ++w) { // wheel의 오른쪽
    if (getRight(wheelRight) != getLeft(w)) {
      rotate(w, dirRight*(-1));
      dirRight = dirRight * (-1);
      wheelRight = w;
    } else {
      break;
    }
  }
}

int main() {

  for (int i=1; i<=wheelNum; ++i) {
    for (int j=0; j<toothNum; ++j) {
      int input;
      scanf("%1d", &input);
      wheels[i].push_back(input);
    }
  }

  scanf("%d", &K);
  for (int i=0; i<K; ++i) {
    int wheel, dir;
    scanf("%d %d", &wheel, &dir);

    vector<pair<int, int>> shouldRot;
    shouldRot.push_back(pair<int, int> (wheel, dir));

    int wheelLeft = wheel;
    int dirLeft = dir;
    for (int w=wheelLeft-1; w>=1; --w) {
      if (getLeft(wheelLeft) != getRight(w)) {
        shouldRot.push_back(pair<int, int> (w, dirLeft*(-1)));
        dirLeft = dirLeft * (-1);
        wheelLeft = w;
      } else {
        break;
      }
    }

    int wheelRight = wheel;
    int dirRight = dir;
    for (int w=wheelRight+1; w<=wheelNum; ++w) {
      if (getRight(wheelRight) != getLeft(w)) {
        shouldRot.push_back(pair<int, int> (w, dirRight*(-1)));
        dirRight = dirRight * (-1);
        wheelRight = w;
      } else {
        break;
      }
    } 

    for (int i=0; i<shouldRot.size(); ++i) {
      rotate(shouldRot[i].first, shouldRot[i].second);
    }
  }

  int count = 0;
  if (wheels[1].front() == 1) {
    count += 1;
  }
  if (wheels[2].front() == 1) {
    count += 2;
  }
  if (wheels[3].front() == 1) {
    count += 4;
  }
  if (wheels[4].front() == 1) {
    count += 8;
  }

  printf("%d\n", count);

  return 0;
}