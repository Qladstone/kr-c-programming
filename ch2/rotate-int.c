#include <stdio.h>

void printBinary(unsigned x) {
	unsigned sz = 8 * sizeof(unsigned);
	char digits[sz];
	char p = 0;
	if (x == 0) printf("0");
	while (x > 0) {
		digits[p++] = x & 1;
		x /= 2;
	}
	while (p > 0) printf("%d", digits[--p]);
}

// rotates the binary representation of x to the right by n bits
unsigned rightrot(unsigned x,  unsigned n) {
	unsigned sz = 8 * sizeof(unsigned);
	if (n > sz) return rightrot(x, n % sz);
	unsigned spillover = ~(~0u << n) & x;
	return (x >> n) | (spillover << (sz - n));
}

void printRightrot(unsigned x, unsigned n) {
	unsigned y = rightrot(x, n);
	printf("x: %u, n: %u, rightrot(x, n): %u | ", x, n, y);
	printf("x in binary: ");
	printBinary(x);
	printf(", rightrot(x) in binary: ");
	printBinary(y);
	printf("\n");
}

int main() {
	printRightrot(24, 1);
	printRightrot(24, 3);
	printRightrot(24, 4);
	printRightrot(24, 6);
	printRightrot(27, 1);
	printRightrot(27, 3);
	printRightrot(27, 4);
	printRightrot(27, 6);
	printRightrot(301, 1);
	printRightrot(301, 3);
	printRightrot(301, 4);
	printRightrot(301, 6);
}
