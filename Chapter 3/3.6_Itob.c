#include <stdio.h>
#include <math.h>

#define MAXLINE 1000 // Max length for a string
#define DIGITOFFSET 48 // The offset of digits in ASCII
#define LETTEROFFSET 97 // The offset of lowercase letters in ASCII

void itob(int number, int base, char s[]);
void reverse(char s[], int slen);

int main(){
	int bases[4];
	int n = 531, m = -164;
	char nstr[MAXLINE], mstr[MAXLINE];

	bases[0] = 10;
	bases[1] = 2;
	bases[2] = 8;
	bases[3] = 16;

	for (int i = 0;i < 4;i++){
		itob(n, bases[i], nstr);
		itob(m, bases[i], mstr);
		printf("In base %d: n=%s, m=%s\n", bases[i], nstr, mstr);
	}

	return 0;
}

// itob: Convert n into base b and puts it in s
void itob(int n, int b, char s[]){
	int digit; // The current digit in base b
	int exp; // Smallest exponent of b for which b^exp > n
	int len = 0; // The length of the string

	if (n < 0){
		s[len++] = '-';
		n *= -1;
	}

	for (exp = 0;pow(b, exp) < n;exp++); // Find the exponent

	for (int i = exp - 1;i >= 0;i--){ 
		for (digit = 0;pow(b, i) * digit <= n;digit++);
		n -= pow(b, i) * (digit - 1);
		s[len++] = digit - 1 + ((digit > 10) ? LETTEROFFSET - 10 : DIGITOFFSET);
	}

	s[len] = '\0';
}