#include <stdio.h>

#define MAXLINE 1000 // The max length for a string

int getline(char line[]);
void escape(char from[], char to[]);
void rescape(char from[], char to[]);

int main(){
	char s1[MAXLINE];
	char s2[MAXLINE];

	while (getline(s1)){
		escape(s1, s2);
		printf("Escape Sequences: %s\n", s2);
		rescape(s2, s1);
		printf("Regular characters: %s\n", s1);
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

// escape: Copies the array from into the array to, converting each special character into its escape sequence.
void escape(char from[], char to[]){
	int fcount; // From count
	int tcount; // To count

	tcount = 0;
	for (fcount = 0;from[fcount] != '\0';fcount++){
		switch (from[fcount]){
			case '\t':
				to[tcount++] = '\\';
				to[tcount++] = 't';
				break;
			case '\n':
				to[tcount++] = '\\';
				to[tcount++] = 'n';
				break;
			case '\\':
				to[tcount++] = '\\';
				to[tcount++] = '\\';
				break;
			default:
				to[tcount++] = from[fcount];
				break;
		}
	}
	
	to[tcount] = '\0';
}

// rescape: Copies the array from into the array to. converting each two char sequence that forms an escape sequence into that sequence
void rescape(char from[], char to[]){
	int fcount; // From count
	int tcount; // To count

	tcount = 0;
	for (fcount = 0;from[fcount] != '\0';fcount++){
		if (fcount){
			if (from[fcount - 1] == '\\'){
				switch (from[fcount]){
					case 't':
						to[tcount++] = '\t';
						break;
					case 'n':
						to[tcount++] = '\n';
						break;
					case '\\':
						to[tcount++] == '\\';
						break;
					default:
						to[tcount++] == '\\';
						to[tcount++] = from[fcount];
						break;
				}
			}
			else if (from[fcount] != '\\')
				to[tcount++] = from[fcount];
		}
		else if (from[fcount] != '\\')
			to[tcount++] = from[fcount];
	}
	
	to[tcount] = '\0';
}