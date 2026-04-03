#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
int main() {
	double sum, myatof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	printf("Enter numbers to sum:\n");
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += myatof(line));
	return 0;
}

int getline(char s[], int lim) {
	int c, i;
	c = i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

double myatof(char s[]) {
	double val, factor;
	int i, sign, myatoi(char []);
	for (i = 0; isspace(s[i]); i++); /* skip white space */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.') i++;
	for (factor = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		factor /= 10.0;
	}
	if (s[i] == 'e') i++;
	int exp = myatoi(s + i);
	while (exp > 0) {
		factor *= 10.0;
		exp--;
	}
	while (exp < 0) {
		factor /= 10.0;
		exp++;
	}
	return sign * val * factor;
}

int myatoi(char s[]) {
	int val = 0;
	int sign;
	while (isspace(*s)) s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-') s++;
	char c;
	while ((c = *s++) != '\0') {
		val = 10 * val + (c - '0');
	}
	return sign * val;
}
