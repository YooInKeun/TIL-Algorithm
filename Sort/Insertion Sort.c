#include <stdio.h>

void insertion_sort(int arr[], int arr_size); // ascending

int main() {

	int num[5], i;

	for (i = 0; i < 5; i++) {

		scanf_s("%d", &num[i]);
	}

	insertion_sort(num, sizeof(num) / sizeof(num[0]));

	for (i = 0; i < 5; i++) {

		printf("%d ", num[i]);
	}

	return 0;
}

void insertion_sort(int arr[], int arr_size) {

	int i, j, tmp;

	for (i = 1; i < arr_size; i++) {

		tmp = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {

				arr[j + 1] = arr[j];
		}

		arr[j+1] = tmp;

	}
}
