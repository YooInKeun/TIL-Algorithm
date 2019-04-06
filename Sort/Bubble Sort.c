#include <stdio.h>

void bubble_sort(int arr[], int arr_size); // ascending

int main() {

	int num[5], i;

	for (i = 0; i < 5; i++) {

		scanf_s("%d", &num[i]);
	}
	
	bubble_sort(num, sizeof(num)/sizeof(num[0]));
	
	for (i = 0; i < 5; i++) {

		printf("%d ", num[i]);
	}

	return 0;
}

void bubble_sort(int arr[], int arr_size) { // 좀 더 효율적인 버블 정렬(Loop count 감소)

	int i, j, tmp, cnt = 0;
	
	for(i = arr_size - 1; i >= 0; i--) {

		for (j = 0; j < i; j++) {

			if (arr[j] > arr[j + 1]) {

				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}

			cnt++;
		}
	}

	printf("Loop Count : %d\n", cnt);
}
