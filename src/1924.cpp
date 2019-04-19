#include <iostream>

using namespace std;

int main() {

    string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int mon, date;
    scanf("%d %d", &mon, &date);

    int value = 0;
    
    for (int i=mon-1; i>=0; --i) {
        if (i == 0) {
            value += (date-1);
        } else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            value += 31;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            value += 30;
        } else if (i == 2) {
            value += 28;
        }
    }

    printf("%s\n", days[value % 7].c_str());

    return 0;
}