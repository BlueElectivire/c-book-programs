#include <stdio.h>

#define MAX 1000 // Max length of a string

int getline(char []);
void reverse(char [], char []);

int length = 0;

// main: Gets an input line and prints it reversed
int main(){
	char line[MAX], output[MAX];\
	length;

	while (length = getline(line)){
		printf("%d\n", length);
		reverse(line, output);
		printf("%s\n", output);
	}

	return 0;
}

// getline: Receives an input line and returns its length
int getline(char line[]){
	int length = 0;
	char c;

	while ((c = getchar()) != EOF && c != '\n' && length < MAX)
		line[length++] = c;
	if (c == '\n' && length < MAX)
		line[length++] = '\n';
	if (length < MAX)
		line[length] = '\0';

	return length;
}

int i = -1; // input location
int o = 0; // output location

// reverse: reverses input and puts it into output
void reverse(char input[], char output[]){
	if (i < 0)
		i = length - 1;
	if (o == length){
		output[o] = '\0';
		i = -1;
		o = 0;
	}
	else {
		output[o++] = input[i--];
		reverse(input, output);
	}	
}