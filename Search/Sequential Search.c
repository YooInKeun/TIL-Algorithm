#include <stdio.h>

char* sequential_search(int arr[], int arr_size);

int main(){

	int num[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

	printf("Result : %s\n", sequential_search(num, sizeof(num) / sizeof(num[0])));

	return 0;
}

char* sequential_search(int arr[], int arr_size) {

	int i, target;

	printf("Search Number : ");

	scanf_s("%d", &target);

	for (i = 0; i < arr_size; i++) {

		if (arr[i] == target) {

			return "success";
		}
	}

	return "fail";
}