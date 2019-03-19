#include <stdio.h>

void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);

int main() {

	int arr[8] = {81, 53, -40, 10, 1, 8, 15, 13}, i;

	printf("정렬 전\n");

	for (i = 0; i < 8; i++) {

		printf("%d ", arr[i]);
	}

	mergeSort(arr, 0, 7);

	printf("\n정렬 후\n");

	for (i = 0; i < 8; i++) {

		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}
void mergeSort(int data[], int p, int r) {
	
	int q;

	if (p<r) {

		q = (p + r) / 2;

		mergeSort(data, p, q); // conquer
		mergeSort(data, q + 1, r); // conquer
		merge(data, p, q, r); // combine
	}
}

void merge(int data[], int p, int q, int r) {

	int i = p, j = q + 1, k = p;
	int tmp[8]; // new array

	while (i <= q && j <= r) {

		if (data[i] <= data[j]) {

			tmp[k++] = data[i++];
		}

		else {

			tmp[k++] = data[j++];
		}
	}

	while (i <= q) {

		tmp[k++] = data[i++];
	}

	while (j <= r) {

		tmp[k++] = data[j++];
	}

	for (int a = p; a <= r; a++) {

		data[a] = tmp[a];
	}
}
