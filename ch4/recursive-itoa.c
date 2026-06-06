#include <stdio.h>
#include <stdlib.h>

int alen(int n) {
	int len = 1;
	if (n < 0) len++;
	n /= 10;
	while (n != 0) {
		n /= 10;
		len++;
	}
	return len;
}

char *rritoa(int n, char *p) {
	if (n < 0) {
		*p++ = '-';
		n *= -1;
	}
	if (n / 10) p = rritoa(n / 10, p);
	*p++ = (n % 10) + '0';
	return p;
}

char *ritoa(int n) {
	int len = alen(n);
	char *result = malloc((len + 1) * sizeof(char));
	char *p = result;
	p = rritoa(n, p);
	*p = '\0';
	return result;
}

void showritoa(int n) {
	char *r = ritoa(n);
	printf("ritoa(%d): %s\n", n, r);
	free(r);
}

int main() {
	printf("Running recursive itoa program.\n");
	showritoa(100);
	showritoa(0);
	showritoa(-5);
	showritoa(7);
	showritoa(1232671);
	showritoa(-547836);
}
