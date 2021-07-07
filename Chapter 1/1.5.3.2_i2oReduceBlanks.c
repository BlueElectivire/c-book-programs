#include <stdio.h>

// Copy input to output
// Replace every string of blanks to a single blank
int main(){
	int c, lastc;

	lastc = 0;
	while ((c = getchar()) != EOF){
		if (lastc == ' '){
			if (c != ' ')
				putchar(c);
		}
		else	
			putchar(c);
		lastc = c;
	}
}