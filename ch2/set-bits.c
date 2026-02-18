#include <stdio.h>

void printSetBits(int x, int p, int n, int y);
int setBits(int x, int p, int n, int y);
int mask(int p, int n);
void printBinary(int x);
int numBits(int x);

int main() {
	printSetBits(14, 1, 1, 4);
	printSetBits(14, 1, 2, 4);
	printSetBits(21, 2, 1, 12);
	printSetBits(21, 3, 2, 13);
	printSetBits(21, 2, 3, 13);
	printSetBits(25, 4, 1, 36);
	printSetBits(25, 1, 3, 36);
}

void printSetBits(int x, int p, int n, int y) {
	printf("x: ");
	printBinary(x);
	printf(", y: ");
	printBinary(y);
	printf(", p: %d, n: %d, result: ", p, n);
	printBinary(setBits(x, p, n, y));
	printf("\n");
}

// sets the n bits of x beginning at p to those of y
int setBits(int x, int p, int n, int y) {
	int m = mask(p, n);
	return x & ~m | y & m;
}

int mask(int p, int n) {
	if (n <= 0) return 0;
	else {
		int result = 1;
		while (n-- > 1) {
			result <<= 1;
			result += 1;
		}
		while (p-- > 0) {
			result <<= 1;
		}
		return result;
	}
}

int numBits(int x) {
	int result = 1;
	while (x > 1) {
		x /= 2;
		result++;
	}
	return result;
}

void printBinary(int x) {
	int n = numBits(x);
	int stack[n];
	int p = 0;
	for (int i = 0; i < n; i++) {
		stack[p++] = x & 1;
		x /= 2;
	}
	while (p > 0) {
		printf("%d", stack[--p]);
	}
}
