#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100 // Buffer size
#define MAXOP 100 // Max size for an operand or operator
#define MAXVAL 100 // Maximum depth of val stack
#define NUMBER '0' // Signal that a number was found

enum FUNCTIONS { // Math header functions
	SIN = 1,
	EXP,
	POW
};

char buf[BUFSIZE]; // Buffer for ungetch
int bufp; // Next free position in buf
int sp = 0; // Next free stack position
double val[MAXVAL]; // Value Stack

void duplicate(double []);
int getch(void);
int getf(char);
int getop(char []);
double pop(void);
void ptop(void);
void push(double);
void swap(void);
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
			case SIN:
				push(sin(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
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

// duplicate: Copies the value stack into the given array
void duplicate(double new[]){
	for (int i = 0;i < sp;i++)
		new[i] = val[i];
}

// getch: Get a (possibly pushed back) character
int getch(){
	return (bufp > 0 ? buf[--bufp] : getchar());
}

// getf: Gets a math.h function from input and returns its value indexed by the enum
int getf(char first){
	char c;
	switch (first){
		case 'S':
		case 's':
			if ((c = getchar()) != 'I' && c != 'i')
				return -1;
			if ((c = getchar()) != 'N' && c != 'n')
				return -1;
			return SIN;
			break;
		case 'E':
		case 'e':
			if ((c = getchar()) != 'X' && c != 'x')
				return -1;
			if ((c = getchar()) != 'P' && c != 'p')
				return -1;
			return EXP;
			break;
		case 'P':
		case 'p':
			if ((c = getchar()) != 'O' && c != 'o')
				return -1;
			if ((c = getchar()) != 'W' && c != 'w')
				return -1;
			return POW;
			break;
		default:
			return first;
			break;
	}
}

// getop: Get next operator or numeric operand
int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t'); // Remove blanks

	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return getf(c); // Not a number

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

// ptop: Prints the top element of the stack without popping it
void ptop(){
	printf("The top element of the stack is %.8g\n", val[sp - 1]);
}

// push: push f onto value stack
void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: Stack full, cannot push %g\n", f);
}

// swap: Swaps the top two elements of the stack
void swap(){
	if (sp > 1){
		int temp;
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
}

// ungetch: Push character back on input
void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: Too many characters\n");
	else
		buf[bufp++] = c;
}