#include <iostream>
#include <cmath>

using namespace std;

struct Object {
  Object(int _x1, int _y1, int _x2, int _y2) {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    vert = x2 - x1;
    hori = y2 - y1;
  }

  int x1;
  int y1;
  int x2;
  int y2;
  int vert;
  int hori;
};

int getOverlap(struct Object bill, struct Object truck) {
  int area = 0;

  int vert = 0;
  if (bill.x1 >= truck.x1 && bill.x2 <= truck.x2) {
    vert = bill.vert;
  } else if (truck.x1 >= bill.x1 && truck.x2 <= bill.x2) {
    vert = truck.vert;
  } else if (bill.x1 < truck.x1 && bill.x2 >= truck.x1) {
    vert = bill.x2 - truck.x1;
  } else if (bill.x2 > truck.x2 && bill.x1 <= truck.x2) {
    vert = truck.x2 - bill.x1;
  }

  int hori = 0;
  if (bill.y1 >= truck.y1 && bill.y2 <= truck.y2) {
    hori = bill.hori;
  } else if (truck.y1 >= bill.y1 && truck.y2 <= bill.y2) {
    hori = truck.hori;
  } else if (bill.y1 < truck.y1 && bill.y2 >= truck.y1) {
    hori = bill.y2 - truck.y1;
  } else if (bill.y2 > truck.y2 && bill.y1 <= truck.y2) {
    hori = truck.y2 - bill.y1;
  }
  
  area = vert * hori;
  return area;
}

int main() {

  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  struct Object bill1(x1, y1, x2, y2);

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  struct Object bill2(x1, y1, x2, y2);

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  struct Object truck(x1, y1, x2, y2);

  int sum = bill1.hori * bill1.vert + bill2.hori * bill2.vert;
  sum -= getOverlap(bill1, truck);
  sum -= getOverlap(bill2, truck);

  printf("%d\n", sum);

  return 0;
}