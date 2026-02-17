#include <stdio.h>
#include <string.h>

/*
 * Removes all characters from s1 that appear in s2
 */
void squeeze(char s1[], char s2[]) {
	int i, j;
	char c1, c2;
	for (i = j = 0; (c1 = s1[i]) != '\0'; i++) {
		bool matched = false;
		for (int k = 0; (c2 = s2[k]) != '\0'; k++) {
			if (c1 == c2) {
				matched = true;
				break;
			}
		}
		if (!matched) s1[j++] = s1[i];
	}
	s1[j++] = '\0';
}

void printSqueeze(char s1[], char s2[]) {
	printf("squeezing %s, %s", s1, s2);
	int n1 = strlen(s1);
	char ss1[n1];
	strcpy(ss1, s1);
	int n2 = strlen(s2);
	char ss2[n2];
	strcpy(ss2, s2);
	squeeze(ss1, ss2);
	printf(" gives %s\n", ss1);
}

int main() {
	printSqueeze("kitten", "cat");
	printSqueeze("kitten", "dog");
	printSqueeze("kitten", "cheetah");
	printSqueeze("kitten", "kindergarten");
}
