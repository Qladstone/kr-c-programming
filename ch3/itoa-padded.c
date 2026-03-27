#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void reverse(char *s) {
	int len = strlen(s);
	char *l = s, *r = s + len - 1;
	while (l < r) {
		char tmp = *l;
		*l++ = *r;
		*r-- = tmp;
	}
}

/* itoa: convert n to characters in s */
void myitoa(int n, char s[], int minwidth) {
	int i, sign;

	i = 0;
	int d;
	if ((sign = n) < 0) { /* record sign */
		n = -(n + 1);
		d = (n % 10) + 1;
		n /= 10;
		if (d == 10) {
			d = 0;
			n++;
		}
	} else {
		d = n % 10;
		n /= 10;
	}

	do { /* generate digits in reverse order */
		s[i++] = d + '0';
		d = n % 10;
	} while ((n /= 10) > 0 || d > 0);
	if (sign < 0) s[i++] = '-';
	while (i < minwidth) s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

void showitoa(int n) {
	char *buffer = malloc((MAXLEN + 1) * sizeof(char));
	myitoa(n, buffer, 8);
	printf("n:%d\nASCII:%s\n", n, buffer);
	free(buffer);
}

int main() {
	printf("Convert integer to ASCII.\n");
	showitoa(93647328);
	showitoa(-93647328);
	showitoa(12345678);
	showitoa(-2345678);
	showitoa(2345678);
	showitoa(-345678);
	showitoa(67328);
	showitoa(-12);
	showitoa(-11);
	showitoa(-10);
	showitoa(-9);
	showitoa(-8);
	showitoa(1 << 31);
}
