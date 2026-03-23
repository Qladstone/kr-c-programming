#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower(int c) {
	return ('A' <= c && c <= 'Z') ? c - ('A' - 'a') : c;
}

char *lowerstr(char *s) {
	int n = strlen(s);
	char *result = malloc((n + 1) * sizeof(char));
	for (int i = 0; i < n; i++) result[i] = lower(s[i]);
	result[n] = '\0';
	return result;
}

void printlower(char *s) {
	char *lowered = lowerstr(s);
	printf("s: %s, lowerstr(s): %s\n", s, lowered);
	free(lowered);
}

int main() {
	printlower("Hello");
	printlower("Hello World");
	printlower("Hello WORLD");
	printlower("INnoVation");
	printlower("6-pool Zerg rush");
	printlower("foo bar");
	printlower("BAR FOO");
}
