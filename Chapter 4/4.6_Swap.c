#include <stdio.h>

#define swap(t, x, y) t = x; x = y; y = t;

int main(){
	int x = 3;
	int y = 4;
	int t = 0;

	printf("x = %d, y = %d\n", x, y);
	swap(t, x, y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}