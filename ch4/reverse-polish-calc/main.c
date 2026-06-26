#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main() {
	printf("Running reverse polish calculator...\n");
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				printf("received number: %.8g\n", atof(s));
				break;
			case '+':
				printf("received operator: +\n");
				break;
			case '*':
				printf("received operator: *\n");
				break;
			case '-':
				printf("received operator: -\n");
				break;
			case '/':
				printf("received operator: /\n");
				break;
			case '\n':
				printf("\tend of line.\n");
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;

		}
	}
}
