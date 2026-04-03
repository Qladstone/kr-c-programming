#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
	char line[MAXLINE];
	int found = 0;
	printf("Find all lines matching: %s\n", pattern);
	while (getline(line, MAXLINE) > 0) {
		int leftindex = strindex(line, pattern);
		int rightindex = strrindex(line, pattern);
		printf("matched indices: left=%d,right=%d\n", leftindex, rightindex);
		if (leftindex >= 0 && rightindex >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
	int c, i;
	c = i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
				return i;
	}
	return -1;
}

/* strrindex: return index of first occurence of t in s from the right, -1 if none */
int strrindex(char s[], char t[]) {
	int i, j, k;
	int slen = strlen(s);
	int tlen = strlen(t);
	for (int i = slen - tlen; i >= 0; i--) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
