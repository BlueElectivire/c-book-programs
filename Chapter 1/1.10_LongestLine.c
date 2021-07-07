#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int max; // Maximum line length so far
char line[MAXLINE]; // Current input line
char longest[MAXLINE]; // Longest line so far

int getLine(void);
void copy(void);

// Print Longest input line
// Using external variables
int main(){
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getLine()) > 0)
		if (len > max){
			max = len;
			copy();
		}

	if (max > 0) // There was a line
		printf("%s", longest);

	return 0;
}

// GetLine: Get input line into external 'line'
int getLine(void){
	int c, i;
	extern char line[];

	for (i = 0;i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}

// Copy: Copy the array 'line' into 'longest'
void copy(void){
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}