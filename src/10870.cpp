#include <iostream>

int n;

int fibonacci(int cur) {
	if (cur == 0) return 0;
	if (cur == 1) return 1;
	
	return fibonacci(cur-2) + fibonacci(cur-1);
}

int main()
{
	scanf("%d", &n);
	
	printf("%d\n", fibonacci(n));

    return 0;
}