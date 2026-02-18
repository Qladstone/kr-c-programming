#include <stdio.h>

void printBinary(int x) {
	int sz = 8 * sizeof(x);
	char digits[sz];
	char p = 0;
	if (x == 0) printf("0");
	while (x != 0) {
		digits[p++] = x & 1;
		x = ((unsigned) x) >> 1;
	}
	while (p > 0) printf("%d", digits[--p]);
}

// counts the number of 1 bits in x
int bitcount(int x) {
	int result = 0;
	while (x != 0) {
		x &= (x - 1);
		result++;
	}
	return result;
}

void printBitcount(int x) {
	printf("x: %d, x in binary: ", x);
	printBinary(x);
	printf(", bitcount: %d\n", bitcount(x));
}

int main() {
	printBitcount(12);
	printBitcount(-1);
	printBitcount(-3);
	printBitcount(1025);
}
