#include <stdio.h>
#include <stdlib.h>

void printarray(int arr[], int n) {
	printf("[");
	if (n > 0) printf("%d", arr[0]);
	for (int i = 1; i < n; i++) {
		printf(",%d", arr[i]);
	}
	printf("]\n");
}

int *randarray(int n) {
	int *arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) arr[i] = rand();
	return arr;
}

void demoshellsort(int v[], int n) {
	printf("Starting arr: ");
	printarray(v, n);
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
		printf("arr for gap=%d: ", gap);
		printarray(v, n);
	}
}

int main() {
	printf("Shellsort demonstration.\n");
	demoshellsort(randarray(12), 12);
}
