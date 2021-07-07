#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size
#define THRESHOLD 80 // Minimum length for print

int getLine(char line[], int maxline);

// Print input lines longer than 80 characters
int main(){
	int len; // Current line length
	char line[MAXLINE]; // Current input line

	while ((len = getLine(line, MAXLINE)) > 0)
		if (len > THRESHOLD)
			printf("%s\n", line);
	
	return 0;
}

// GetLine: Read a line into s, return its length
int getLine(char s[], int lim){
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}