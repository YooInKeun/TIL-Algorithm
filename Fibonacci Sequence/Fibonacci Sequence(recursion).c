#include <stdio.h>

int fibonacci(int n);

int main() {

	int num;

	printf("index : ");

	scanf_s("%d", &num);

	printf("°á°ú : %d\n", fibonacci(num));

	return 0;
}

int fibonacci(int n){

	if(n == 1) {
		return 1;
	}

	else if (n == 2) {
		return 1;
	}

	else {
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}