#include <stdio.h>

#define MAXLINE 1000 // Maximum length of a string

int getline(char line[]);
int any(char s1[], char s2[]);

// main: Gets two input lines, prints out the first index where a character from the second array appears in the first.
int main(){
	char s1[MAXLINE]; // The first string
	char s2[MAXLINE]; // The second string

	while (getline(s1) != 0 && getline(s2) != 0){
		printf("%d\n", any(s1, s2));
	}

	return 0;
}

// getline: Gets an input line from the user and puts it in the array line.
// Returns its length
int getline(char line[]){
	int c; // Input character
	int i; // Length of the input string

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	if (i < MAXLINE)
		line[i] = '\0';

	return i;
}

// any: Gets two char arrays.
// Returns the first location in the first array where any character of the second array occurs.
int any(char s1[], char s2[]){
	int i; // Iteration variable.
	int j; // Iteration variable.

	for (i = 0;i < MAXLINE && s2[i] != '\n';i++)
		for (j = 0;j < MAXLINE && s1[j] != '\n';j++)
			if (s1[j] == s2[i])
				return j;

	return -1;
}