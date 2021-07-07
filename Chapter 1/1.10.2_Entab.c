#include <stdio.h>

#define TABSIZE 4 // Amount of blanks in a tab
#define IN 1 // In a string of blanks
#define OUT 0 // Out of a string of blanks

// Copy input to output
// Replace strings of blanks in the input with tabs
int main(){
	int c, state, len;

	state = OUT;
	len = 0;
	while ((c = getchar()) != EOF){
		if (c ==' '){
			if (state == OUT)
				state = IN;
			++len;
		}
		else {
			if (state == IN){
				state = OUT;
				while (len >= TABSIZE){
					putchar('\t');
					len = len - TABSIZE;
				}
				while (len > 0){
					putchar(' ');
					--len;
				}
			}
			putchar(c);
		}
	}

	return 0;
}