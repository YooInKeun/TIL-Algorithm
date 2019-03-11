#include <stdio.h>

char* binary_search(int arr[], int arr_size);

int main(){

	int num[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

	printf("Result : %s\n", binary_search(num, sizeof(num) / sizeof(num[0])));

	return 0;
}

char* binary_search(int arr[], int arr_size){

	int mid, target;
	int start = 0;
	int end = arr_size - 1;

	printf("Search Number : ");
	
	scanf_s("%d", &target);

	while (start <= end) {

		mid = (start + end) / 2;

		if (arr[mid] == target) {

			return "success";
		}

		else if (arr[mid] < target) {

			start = mid + 1;
		}

		else if (arr[mid] > target) {

			end = mid - 1;
		}
	}

	return "fail";
}