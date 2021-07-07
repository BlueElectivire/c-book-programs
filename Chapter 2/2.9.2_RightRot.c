#include <stdio.h>
#include <math.h>

#define INTSIZE 16 // The amount of bits in an int variable

int rightrot(unsigned x, int n);

int main(){
	unsigned x = 135;
	int n = 4;

	printf("%d\n", rightrot(x, n));

	return 0;
}

// rightrot: Rotate x to the right n times
int rightrot(unsigned x, int n){
	int bit; // The bit to be taken from the rightmost side to the leftmost side
	int i; // Iterator
	
	for (i = 0;i < n; i++){
		if (x % 2 == 1) {
			bit = pow(2, INTSIZE - 1); // 1 followed by a string of 0's for the size of an int
			x = (x >> 1) ^ bit; // The new bit to the left is always a 0, makes it a 1 without touching the others
		}
		else
			x = x >> 1; // The new bit is always a 0
	}

	return x;
}