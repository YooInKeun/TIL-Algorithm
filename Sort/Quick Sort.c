#include <stdio.h>

void quick_sort(int arr[], int left, int right);

int main() {

	int num[10], i;

	for (i = 0; i < 10; i++) {

		scanf_s("%d", &num[i]);
	}

	quick_sort(num, 0, (sizeof(num) / sizeof(num[0]))-1);

	for (i = 0; i < 10; i++) {

		printf("%d ", num[i]);
	}

	return 0;
}

void quick_sort(int arr[], int left, int right) {

	int L = left, R = right;
	int temp;
	int pivot = arr[(left + right) / 2];

	while (L <= R) {

		while (arr[L] < pivot) {
			L++;
		}

		while (arr[R] > pivot) {
			R--;
		}

		if (L <= R) {
			if (L != R) {
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
			L++;
			R--;

		}
	}

	if (left < R) {
		quick_sort(arr, left, R);
	}

	if (L < right) {
		quick_sort(arr, L, right);
	}
}