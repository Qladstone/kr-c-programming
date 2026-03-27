#include <stdio.h>
#include <stdlib.h>

char digit(int d) {
	if (d < 10) return '0' + d;
	else return 'a' + (d - 10);
}

char *itob(int n, int b) {
	if (b <= 1) b = 2;
	else if (b > 16) b = 16;
	int x = n;
	int len = 1;
	x /= b;
	while (x > 0) {
		x /= b;
		len++;
	}
	char *result = malloc((len + 1) * sizeof(char));
	result += len;
	x = n;
	*result = '\0';
	*--result = digit(x % b);
	x /= b;
	while (x > 0) {
		*--result = digit(x % b);
		x /= b;
	}
	return result;
}

void showitob(int n, int b) {
	char *s = itob(n, b);
	printf("itob(%d, %d): %s\n", n, b, s);
	free(s);
}

int main() {
	printf("Convert int to base b representation.\n");
	int nums[] = {0, 5, 8, 10, 12, 128, 131, 256, 260, 1024};
	int numslen = 10;
	int bases[] = {10, 2, 8, 16};
	int baseslen = 4;
	for (int i = 0; i < baseslen; i++) {
		int b = bases[i];
		for (int j = 0; j < numslen; j++) {
			int n = nums[j];
			showitob(n, b);
		}
	}
}
