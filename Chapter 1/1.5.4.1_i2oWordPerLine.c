#include <stdio.h>

#define OUT 0 // Out of word
#define IN 1 // In a word

// Copy input to output
// Every word printed is in new line
int main(){
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF){
		if (c == '\t' || c == ' '  || c == '\n'){
			if (state == IN){
				state = OUT;
				putchar('\n');
			}
		}	
		else{
			state = IN;
			putchar(c);
		}
	}
}