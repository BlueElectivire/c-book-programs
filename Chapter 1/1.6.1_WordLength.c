#include <stdio.h>

#define LENGTH 10 // Array length
#define OUT 0 // Out of a word
#define IN 1 // In a word

// Prints the length of inputs as a histogram
int main(){
	int c, state, len, max;
	int wordLengths[LENGTH];

	for (int i = 0;i < LENGTH; ++i)
		wordLengths[i] = 0;

	state = OUT;
	len = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (state == IN){
				state = OUT;
				if (len < LENGTH - 1)
					++wordLengths[len];
				else
					++wordLengths[LENGTH - 1];
				len = 0;
			}
		}
		else{
			state = IN;
			++len;
		}
	}

	// Print horizontal histogram
	for (int i = 0;i < LENGTH; ++i){
		printf("%d: ", i);
		for(int j = 0;j < wordLengths[i]; ++j)
			putchar('|');	
		putchar('\n');
	}
		
	// Print vertical histogram
	max = 0;
	for (int i = 0;i < LENGTH; ++i){
		if (max < wordLengths[i])
			max = wordLengths[i];
		printf("%d\t", i);
	}	
	printf("\n");

	for (int i = 0;i < max; ++i){
		for (int i = 0;i < LENGTH; ++i)
			if (wordLengths[i] > 0){
				printf("-\t");
				--wordLengths[i];
			}
			else{
				printf(" \t");
			}
		printf("\n");
	}
}