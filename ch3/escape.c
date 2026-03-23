#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char *s, char *t) {
	char c;
	while ((c = *t++) != '\0') {
		switch (c) {
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			default:
				*s++ = c;
				break;
		}
	}
	*s = '\0';
}

void capture(char *s, char *t) {
	char c;
	while ((c = *s++) != '\0') {
		switch (c) {
			case '\\':
				char d = *s++;
				switch (d) {
					case 't':
						*t++ = '\t';
						break;
					case 'n':
						*t++ = '\n';
						break;
					default:
						*t++ = c;
						*t++ = d;
						break;
				}
				break;
			default:
				*t++ = c;
				break;
		}
	}
	*t = '\0';
}

void showescape(char *t) {
	printf("Escaping...\n");
	int n = strlen(t);
	char *s = malloc((2 * n + 1) * sizeof(char));
	escape(s, t);
	printf("s:%s\n", s);
	printf("t:%s\n", t);
	free(s);
}

void showcapture(char *s) {
	printf("Capturing...\n");
	int n = strlen(s);
	char *t = malloc((n + 1) * sizeof(char));
	capture(s, t);
	printf("s:%s\n", s);
	printf("t:%s\n", t);
	free(t);
}

int main() {
	printf("Escape sequences.\n\n");
	showescape("\thello world\nhello there\n");
	showcapture("\\thello world\\nhello there\\n");
}
