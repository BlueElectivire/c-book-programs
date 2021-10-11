#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100 // Buffer size

char buf[BUFSIZE]; // Buffer for ungetch
int bufp; // Next free position in buf

int getint(int *pn);

int main() {
	int num, *np;
	np = &num;
	int state;
	while (bufp < BUFSIZE &&  (state = getint(np)) != EOF)
		if (state > 0)
			printf("Value is %d\n", *np);
		else {
			printf("Not a number\n");
			break;
		}
	
	return 0;
}

int getch(void);
void ungetch(int);

// getint: get next integer from input into *pn
int getint(int *pn){
	int c, sign;

	while (isspace(c = getch())); //Skip whitespace
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); // NaN
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c)){ // NaN
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

// getch: Get a (possibly pushed back) character
int getch(){
	return (bufp > 0 ? buf[--bufp] : getchar());
}

// ungetch: Push character back on input
void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: Too many characters\n");
	else
		buf[bufp++] = c;
}