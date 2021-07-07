#include <stdio.h>

#define TABSIZE 4 //Number of blanks in a tab

// Copy input to output
// Replace every tab with TABSIZE blanks
int main(){
	int c, i;

	while ((c = getchar()) != EOF){
		if (c =='\t')
			for (i = 0;i < TABSIZE; ++i)
				putchar(' ');
		else
			putchar(c);
	}

	return 0;
}