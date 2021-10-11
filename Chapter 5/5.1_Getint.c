#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 100 // Buffer size

char buf[BUFSIZE]; // Buffer for ungetch
int bufp; // Next free position in buf

int getint(int *);
int getfloat(float *);

int main() {
	float num, *np;
	np = &num;
	int state;
	while (bufp < BUFSIZE &&  (state = getfloat(np)) != EOF)
		if (state > 0)
			printf("Value is %f\n", *np);
		else {
			printf("Not a number\n");
			break;
		}
	
	return 0;
}

int getch(void);
void ungetch(int);

// getint: get next integer from input into *ip
int getint(int *ip){
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
	for (*ip = 0; isdigit(c); c = getch())
		*ip = 10 * *ip + (c - '0');
	*ip *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

// getfloat: get next float from input to *fp
int getfloat(float *fp){
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
	for (*fp = 0; isdigit(c); c = getch())
		*fp = 10 * *fp + (c - '0');
	if (c == '.')
		c = getch();
		for (int i = 1; isdigit(c); i++){
			*fp += pow(10, -i) * (c - '0');
			c = getch();
		}
	*fp *= sign;
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