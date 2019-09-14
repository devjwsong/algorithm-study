#include <iostream>

using namespace std;

int x, y, w, h;

int main() {

    scanf("%d %d %d %d", &x, &y, &w, &h);

    int dist_x = min(w-x, x);
    int dist_y = min(h-y, y);

    printf("%d\n", min(dist_x, dist_y));

    return 0;
}