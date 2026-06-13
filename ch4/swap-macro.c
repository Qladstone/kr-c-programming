#include <stdio.h>

#define swap(t, x, y) \
	{ \
		t tmp = x; \
		x = y; \
		y = tmp; \
	}

void showswapint(int x, int y) {
	printf("Before swap: x=%d, y=%d\n", x, y);
	swap(int, x, y);
	printf("After swap: x=%d, y=%d\n", x, y);
}

void showswapchar(char x, char y) {
	printf("Before swap: x=%c, y=%c\n", x, y);
	swap(char, x, y);
	printf("After swap: x=%c, y=%c\n", x, y);
}

void showswapstr(char *x, char *y) {
	printf("Before swap: x=%s, y=%s\n", x, y);
	swap(char *, x, y);
	printf("After swap: x=%s, y=%s\n", x, y);
}

int main() {
	showswapint(0, 2);
	showswapint(-1233, 999);
	showswapint(1 << 10, 500);
	showswapchar('a', 'b');
	showswapchar('5', 'z');
	showswapchar('?', '#');
	showswapstr("abc", "xyz");
	showswapstr("Hello world.", "- - -");
	showswapstr("=-??x", "[][]");
}
