#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// Print longest input line
int main(){
	int len; // Current line length
	int max; // Maximum length so far
	char line[MAXLINE]; // Current input line
	char longest[MAXLINE]; // Longest line so far

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0) // There was a line
		printf("%d: %s", max, longest);
		
	return 0;
}

// GetLine: Read a line into s, return its length
int getLine(char s[], int lim){
	int c, i;

	for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim)
			s[i] = c;
	if (c == '\n') {
		if (i < lim)
			s[i] = c;
		++i;
	}
	if (i < lim)
		s[i] = '\0';
	return i;
}

// Copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}