#include <stdio.h>
#include <math.h>

#define INTSIZE 16 // Amount of bits in an int

int invert(unsigned x, int p, int n);

int main(){
	unsigned x = 135;
	int p = 3;
	int n = 2;

	printf("%d\n", invert(x, p, n));

	return 0;
}

// invert: Inverts n bits in x from position p
// TODO: WRONG!!!!
int invert(unsigned x, int p, int n){
	unsigned xbits = ((~((x >> p + 1 - n) & (int)(pow(2, n) - 1))) << (INTSIZE - n)) >> (INTSIZE - p);
	unsigned xwhite = x & ~((int)(pow(2, n) - 1) << p + 1 - n);

	return xbits | xwhite;
}