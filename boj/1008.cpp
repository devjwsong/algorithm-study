#include <iostream>

using namespace std;

int main() {
    double a, b = 0.0;
    
    scanf("%lf %lf", &a, &b);
    printf("%.9lf\n", a / b);
    
    return 0;
}