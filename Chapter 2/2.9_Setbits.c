#include <stdio.h>
#include <math.h>

int setbits(unsigned x, int p, int n, unsigned y);

// main: Prints x after applying setbits
int main(){
	int n = 2;
	int p = 3;
	unsigned x = 135;
	unsigned y = 73;

	printf("%d\n", setbits(x, p, n, y));

	return 0;
}

// setbits: Gets two unsigned numbers and an additional two numbers
// Returns the first unsigned number, with the first n bits from position p changed to the rightmost n bits of the second
int setbits(unsigned x, int p, int n, unsigned y){
	unsigned xbits;
	unsigned ybits;

	xbits = x & ~((int)(pow(2, n) - 1) << (p + 1 - n));
	ybits = (y & (int)(pow(2, n) - 1)) << (p + 1 - n);
	
	return xbits | ybits;
}