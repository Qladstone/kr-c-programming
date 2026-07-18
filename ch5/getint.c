#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int getch(void);
int ungetch(int);

int getint(int *pn) {
	int c, sign;
	while (isspace(c = getch())); // skip whitespace
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); // not a number
		*pn = INT_MIN;
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		char d = getch();
		if (!isdigit(d)) {
			ungetch(d); // not a number
			ungetch(c);
			*pn = INT_MIN;
			return 0;
		}
		c = d;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF) ungetch(c);
	return c;
}

int main(void) {
	printf("Running getint program.\n");
	int toget;
	getint(&toget);
	printf("Got %d\n", toget);
}
