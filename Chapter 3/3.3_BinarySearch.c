#include <stdio.h>
#include <math.h>

int binsearch(int a[], int n, int x);

int main(){
	int a[10];
	int i;
	int x = 8;
	int y = 3;

	for (i = 0;i < 10;i++)
		a[i] = pow(2, i);

	printf("x's place: %d\n", binsearch(a, 10, x));
	printf("y's place: %d\n", binsearch(a, 10, y));

	return 0;
}

// binsearch: Returns x's location in sorted array a of length n
// Returns -1 if does not exist
int binsearch(int a[], int n, int x){
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != a[mid]){
		if (x < a[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == a[mid])
		return mid;

	return -1; // Not Found
}