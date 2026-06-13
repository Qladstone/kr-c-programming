#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rrreverse(char *l, int d) {
	if (d <= 0) return;
	char t = *l;
	*l = *(l + d);
	*(l + d) = t;
	rrreverse(l + 1, d - 2);
}

void rreverse(char *s) {
	rrreverse(s, strlen(s) - 1);
}

void showrreverse(char *s) {
	int n = strlen(s);
	char *p = malloc((n + 1) * sizeof(char));
	strcpy(p, s);
	rreverse(p);
	printf("rreverse(%s): %s\n", s, p);
	free(p);
}

int main() {
	printf("Running recursive reverse program.\n");
	showrreverse("");
	showrreverse("a");
	showrreverse("ab");
	showrreverse("yeZ");
	showrreverse("2c343^=");
	showrreverse("23c 2!!?-");
}
