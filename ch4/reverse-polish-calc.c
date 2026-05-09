#include <math.h> /* for fmod and other mathematical functions */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* for strcmp() */

#define MAXOP 100 /* max size of operand or operator */
#define INVALID '0' /* signal invalid operator */
#define NUMBER '1' /* signal that a number was found */
#define SIN '2'
#define COS '3'
#define TAN '4'
#define EXP '5'
#define POW '6'
#define VAR '7'

#define VARCOUNT 26
#define NOTVAR '\0'

int getnext(char []);
int getop(char []);
int getnum(char []);
void push(double);
double pop(void);
double peek(void); /* unused */
void clear(void); /* unused */
void pushvar(char);
char popvar(void);
char peekvar(void); /* unused */
void clearvar(void); /* unused */

double vars[VARCOUNT] = {0};

/* reverse Polish calculator */
int main() {
	int type;
	double op1, op2;
	char s[MAXOP];

	printf("Enter expression:\t");
	while ((type = getnext(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				pushvar(NOTVAR);
				break;
			case VAR:
				push(vars[s[0] - 'a']);
				pushvar(s[0]);
				break;
			case '+':
				push(pop() + pop());
				popvar();
				popvar();
				pushvar(NOTVAR);
				break;
			case '*':
				push(pop() * pop());
				popvar();
				popvar();
				pushvar(NOTVAR);
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				popvar();
				popvar();
				pushvar(NOTVAR);
				break;
			case '/':
				op2 = pop();
				popvar();
				if (op2 != 0.0) {
					push(pop() / op2);
					popvar();
					pushvar(NOTVAR);
				} else
					printf("error: zero divisor for division operation\n");
				break;
			case '%':
				op2 = pop();
				popvar();
				if (op2 != 0.0) {
					push(fmod(pop(), op2));
					popvar();
					pushvar(NOTVAR);
				} else
					printf("error: zero divisor for modulo operation\n");
				break;
			case '=':
				op2 = pop();
				op1 = pop();
				popvar();
				char c = popvar();
				if (c == NOTVAR) {
					push(op1);
					pushvar(NOTVAR);
				}
				else {
					vars[c - 'a'] = op2; /* assign value of op2 to the variable */
					push(vars[c - 'a']);
					pushvar(NOTVAR);
				}
				break;
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				push(tan(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;

			case '\n':
				printf("Result:\t%.8g\n", pop());
				clear();
				printf("Enter expression:\t");
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* peek: returns the top values from the stack without removing it */
double peek(void) {
	if (sp > 0)
		return val[sp - 1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* clear: clears all values on the stack */
void clear(void) {
	sp = 0;
}

int varsp = 0; /* next free stack position */
char var[MAXVAL]; /* var stack */

void pushvar(char c) {
	if (varsp < MAXVAL)
		var[varsp++] = c;
	else 
		printf("error: var stack full, can't push %c\n", c);
}

char popvar(void) {
	if (varsp > 0)
		return var[--varsp];
	else {
		printf("error: var stack empty\n");
		return NOTVAR;
	}
}

char peekvar(void) {
	if (varsp > 0)
		return var[varsp - 1];
	else {
		printf("error: var stack empty:\n");
		return NOTVAR;
	}
}

void clearvar(void) {
	varsp = 0;
}

#include <ctype.h>

char getch(void);
void ungetch(char);

/* getnext: get next operator or numeric operand */
int getnext(char s[]) {
	char c;
	while ((c = getch()) == ' ' || c == '\t');
	if (c == '\n') return c;
	ungetch(c);
	if (isdigit(c) || c == '.') return getnum(s);
	else return getop(s);
}

/* getop: get next operator */
int getop(char s[]) {
	char c;
	int i = 0;
	while ((s[i++] = c = getch()) != ' ' && c != '\t' && c != '\n');
	s[i - 1] = '\0';
	ungetch(c);
	if (strcmp(s, "sin") == 0) return SIN;
	if (strcmp(s, "cos") == 0) return COS;
	if (strcmp(s, "tan") == 0) return TAN;
	if (strcmp(s, "exp") == 0) return EXP;
	if (strcmp(s, "pow") == 0) return POW;
	if (s[1] == '\0' && 'a' <= s[0] && s[0] <= 'z') return VAR;
	return s[0];
}

/* getnum: get next numeric operand */
int getnum(char s[]) {
	int i, c;
	s[i = 0] = c = getch();
	s[1] = '\0';
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	ungetch(c);
	return NUMBER;
}

#define BUFSIZE 1

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

char getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}
