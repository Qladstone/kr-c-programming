#include <stdio.h>
#include <string.h>

unsigned int htoi(char *s);
void printAtoi(char *s);

int main() {
	printAtoi("10");
	printAtoi("100");
	printAtoi("0x111");
	printAtoi("0X11F");
	printAtoi("0x1de1fe3d");
	printAtoi("123ddeFa27");
	printAtoi("12CCd23aa");
}

// Converts a hexadecimal string into a decimal int
unsigned int htoi(char *s) {
	int n = strlen(s);
	int start = 0;
	if (n > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) start = 2;

	unsigned int x = 0;
	for (int i = start; i < n; i++) {
		x <<= 4;
		char c = s[i];
		short h = 0;
		if ('0' <= c && c <= '9') h = c - '0';
		else if ('a' <= c && c <= 'f') h = c - 'a' + 10;
		else if ('A' <= c && c <= 'F') h = c - 'A' + 10;
		x += h;
	}
	return x;
}

void printAtoi(char *s) {
	printf("hexadecimal %s -> decimal %u\n", s, htoi(s));
}
