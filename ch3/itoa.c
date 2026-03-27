#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 100
char buffer[MAXLEN + 1];

void reverse(char *s) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
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
		s[i++] = d + '0'; /* get next digit */
		d = n % 10;
	} while ((n /= 10) > 0 || d > 0); /* delete it */
	if (sign < 0) s[i++] = '-';
	s[i] = '\0';
	reverse(buffer);
}

void showitoa(int n) {
	itoa(n, buffer);
	printf("n:%d\nASCII:%s\n", n, buffer);
}

int main() {
	printf("Convert integer to ASCII.\n");
	showitoa(23647328);
	showitoa(-23647328);
	showitoa(67328);
	showitoa(-12);
	showitoa(-11);
	showitoa(-10);
	showitoa(-9);
	showitoa(-8);
	showitoa(1 << 31);
}
