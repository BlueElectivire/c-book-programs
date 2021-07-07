#include <stdio.h>

int power(int m, int n);

//Test power function
int main(){
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i ,power(2,i), power(-3, i));
	return 0;
}

// Power: Raise base to the n-th power for n>=0
int power(int base, int n){
	int i, p;

	for (p = 1;n > 0; --n)
		p = p * base;
	return p;
}