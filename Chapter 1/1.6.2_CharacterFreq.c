#include <stdio.h>

#define LENGTH 27 // Length of array
#define OFFSET 97 // Offset of lowercase letters in ASCII

// Print a histogram of the frequencies
// of every lowercase letter and other chars
int main(){
	int c;
	int frequency[LENGTH];

	for (int i = 0;i < LENGTH; ++i)
		frequency[i] = 0;
	
	while ((c = getchar()) != EOF){
		if (c >= 'a' && c <= 'z')
		{
			++frequency[c - OFFSET];
		}
		else
			++frequency[LENGTH - 1];
	}

	// Print horizontal histogram
	for (int i = 0;i < LENGTH; ++i){
		printf("%c: ", i + OFFSET);
		for(int j = 0;j < frequency[i]; ++j)
			putchar('|');	
		putchar('\n');
	}
}