#include <stdio.h>

// Copy input to output
// Replace every tab, backspace and backslash with escape sequences
int main(){
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b'){
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		else	
			putchar(c);
	}
}