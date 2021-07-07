#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size

int getLine(char line[], int maxline);
void reverse(char line[], int length);

// Print longest input line
int main(){
	int len; // Current line length
	char line[MAXLINE]; // Current input line

	while ((len = getLine(line, MAXLINE)) > 0){
		reverse(line, len);
		printf("%s\n", line);
	}
	
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

// Reverse: Reverses the input string
void reverse(char s[], int length){
	char temp;

	for (int i = 0;i < length / 2; ++i){
		temp = s[length - i - 1];
		s[length - i - 1] = s[i];
		s[i] = temp;
	}
}