#include <stdio.h>

void printBinary(int x) {
	int n = sizeof(int);
	char digits[n];
	int p = 0;
	if (x == 0) printf("0");
	while (x > 0) {
		digits[p++] = x & 1;
		x /= 2;
	}
	while (p > 0) printf("%d", digits[--p]);
}

int mask(int p, int n) {
	return ~(~0 << n) << p;
}

// flips the n bits of x starting at p
int invert(int x, int p, int n) {
	int m = mask(p, n);
	return (~m & x) | (m & ~x);
}

void printInvert(int x, int p, int n) {
	printf("x: ");
	printBinary(x);
	printf(", p: %d, n: %d, inverted: ", p, n);
	printBinary(invert(x, p, n));
	printf("\n");
}

int main() {
	printInvert(24, 1, 3);
	printInvert(24, 2, 3);
	printInvert(24, 2, 4);
	printInvert(365, 2, 4);
	printInvert(365, 2, 1);
	printInvert(365, 4, 5);
}
