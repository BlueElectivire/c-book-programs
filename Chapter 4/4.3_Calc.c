#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100 // Buffer size
#define MAXOP 100 // Max size for an operand or operator
#define MAXVAL 100 // Maximum depth of val stack
#define NUMBER '0' // Signal that a number was found

char buf[BUFSIZE]; // Buffer for ungetch
int bufp; // Next free position in buf
int sp = 0; // Next free stack position
double val[MAXVAL]; // Value Stack

int getch(void);
int getop(char []);
double pop(void);
void push(double);
void ungetch(int);

// Reverse Polish Calculator
int main(){
	double op1; // First operand (for modulus)
	double op2; // Second operand (for non commutitive operations)
	char s[MAXOP]; // Input
	int type; // Type of input

	while ((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				if ((op2 = pop()) != 0.0)
					push(pop() / op2);
				else
					printf("Error: Division by zero\n");
				break;
			case '%':
				if ((op2 = pop()) != 0.0)
					if ((op1 = pop()) == (int)op1 && op2 == (int)op2)
						push ((int)op1 % (int)op2);
					else
						printf("Error: Non-integer operands for modulus\n");
				else
					printf("Error: Division by zero\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: Unknown input %s\n", s);
				break;
		}
	}

	return 0;
}

// getch: Get a (possibly pushed back) character
int getch(){
	return (bufp > 0 ? buf[--bufp] : getchar());
}

// getop: Get next operator or numeric operand
int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t'); // Remove blanks

	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; // Not a number

	i = 1;
	if (c == '-')
		if (isdigit(c = getch())) // Negative number
			s[i++] = c;
		else // Subtraction operand
			return '-';
	if (isdigit(c)) // Collect integer part
		while (isdigit(s[i++] = c = getch()));
	if (c == '.') // Collect fraction part
		while (isdigit(s[i++] = c = getch()));

	s[i] = '\0';
	if (c != EOF);
		ungetch(c);
	return NUMBER;
}

// pop: Pop and return the top value from stack
double pop(){
	if (sp > 0)
		return val[--sp];
	printf("Error: Stack empty\n");
	return 0;
}

// push: push f onto value stack
void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full, cannot push %g\n", f);
}

// ungetch: Push character back on input
void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: Too many characters\n");
	else
		buf[bufp++] = c;
}