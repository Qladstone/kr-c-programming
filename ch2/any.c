#include <stdio.h>

int any(char s1[], char s2[]) {
	char c1, c2;
	int i = 0;
	while ((c1 = *s1++) != '\0') {
		char* ss2 = s2;
		while ((c2 = *ss2++) != '\0') {
			if (c1 == c2) return i;
		}
		i++;
	}
	return -1;
}

void printAny(char s1[], char s2[]) {
	printf("%s has a character from %s at index %d\n", s1, s2, any(s1, s2));
}

int main() {
	printAny("cat", "kitten");
	printAny("kitten", "cat");
	printAny("cat", "dog");
	printAny("dog", "cat");
	printAny("push", "beep");
	printAny("beep", "push");
}
