#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
char buffer[MAXLEN + 1];

char *expandlr(char l, char r) {
	int n = r - l + 1;
	char *s = malloc((n + 1) * sizeof(char));
	char *p = s;
	for (char c = l; c <= r; c++) *p++ = c;
	*p = '\0';
	return s;
}

bool matchinglr(char l, char r) {
	if (l > r) return false;
	return 'a' <= l && r <= 'z' || 'A' <= l && r <= 'Z' || '0' <= l && r <= '9';
}

void expand(char *s1, char *s2, int n2) {
	int n1 = strlen(s1);
	int i1;
	int i2 = 0;
	for (i1 = 0; i1 < n1 - 2 && i2 < n2 ; i1++) {
		char l = s1[i1];
		char m = s1[i1 + 1];
		char r = s1[i1 + 2];
		if (m == '-' && matchinglr(l, r)) {
			char *ltor = expandlr(l, r);
			char *pltor = ltor;
			char c;
			while (i2 < n2 && (c = *pltor++) != '\0') s2[i2++] = c;
			i1 += 2;
			free(ltor);
		} else s2[i2++] = l;
	}
	while (i1 < n1 && i2 < n2) s2[i2++] = s1[i1++];
	s2[i2] = '\0';
}

void showexpand(char *s) {
	expand(s, buffer, MAXLEN);
	printf("s:%s\nexpanded:%s\n", s, buffer);
}

int main() {
	printf("Expand shorthand notations.\n");
	showexpand("a-z");
	showexpand("w-b");
	showexpand("-b-z--a--D-W1-7-8-0");
	showexpand("P-S-");
	showexpand("G-Jfoofoo4-55-999");
}
