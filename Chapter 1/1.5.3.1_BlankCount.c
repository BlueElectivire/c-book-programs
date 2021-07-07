#include <stdio.h>

// Count blanks, tabs, and newlines
int main(){
	int c, nChars;

	nChars = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n' || c == ' ' || c == '\t')
			++nChars;

	printf("%d\n", nChars);
}