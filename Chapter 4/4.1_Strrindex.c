#include <stdio.h>

#define MAXLINE 1000 // The max length of a string
#define TAGLENGTH 4 // The length of the tag

int getline(char line[]);
int strrindex(char s[], char tag[]);

// main: Gets lines from input, and prints the rightmost index of occurrences of tag
int main(){
	char line[MAXLINE];
	char tag[TAGLENGTH] = "ould";

	while (getline(line))
		printf("%d\n", strrindex(line, tag));
			
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

// strrindex: Receives a string and a tag
// Returns the rightmost index which starts the tag string in the other string.
// Returns -1 if it does not occur.
int strrindex(char s[], char tag[]){
	int i; // Iterator
	int j; // Tag iterator
	int index = -1; // The wanted index
	int tempindex = -1; // Temp index, to be made perm on verification

	j = 0;
	for (i = 0;i < MAXLINE && s[i] != '\0';i++)
		if (s[i] == tag[j]){
			if (j == 0) // New occurrence
				tempindex = i;
			j++;
			if (j == TAGLENGTH){
				index = tempindex;
				tempindex = -1;
				j = 0;
			}
		}
		else if (tempindex != -1){
			tempindex = -1;
			j = 0;
		}
	
	return index;
}