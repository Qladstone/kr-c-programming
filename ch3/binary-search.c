#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = low + (high - low) /  2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch2(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = low + (high - low) / 2;
		if (x <= v[mid])
			high = mid;
		else low = mid + 1;
	}
	return v[low] == x ? low : -1;
}

int *testarray(int start, int d, int n) {
	int *arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		int x = start + i * d;
		arr[i] = x;
	}
	return arr;
}

int testsearch(int start, int d, int n) {
	int *arr = testarray(start, d, n);
	bool allmatch = true;
	for (int x = start; x < start + n * d; x++) {
		int i = binsearch(x, arr, n);
		int i2 = binsearch2(x, arr, n);
		if (i != i2) {
			allmatch = false;
			printf("mismatch! binsearch(%d) is %d, binsearch2(%d) is %d\n", x, i, x, i2);
		}
	}
	free(arr);
	if (allmatch) printf("All results for binsearch and binsearch2 are matching.\n");
}

void measuresearch(int start, int d, int n) {
	int *arr = testarray(start, d, n);
	
	clock_t startclock = clock();
	for (int x = start; x < start + n * d; x++) {
		int i = binsearch(x, arr, n);
	}
	clock_t endclock = clock();
	printf("binsearch took: %f seconds\n", (double) (endclock - startclock) / CLOCKS_PER_SEC);

	clock_t startclock2 = clock();
	for (int x = start; x < start + n * d; x++) {
		int i2 = binsearch2(x, arr, n);
	}
	clock_t endclock2 = clock();
	printf("binsearch2 took: %f seconds\n", (double) (endclock2 - startclock2) / CLOCKS_PER_SEC);

	free(arr);
}

int main() {
	printf("Running binary search comparison program.\n");
	testsearch(0, 16, 1000000);
	measuresearch(0, 16, 1000000);
}
