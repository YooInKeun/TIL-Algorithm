#include <stdio.h>

int fibonacci(int n);

int main() {

	int num;

	printf("구하고자 값의 index : ");

	scanf_s("%d", &num);

	while (num < 3) { // 3 이상의 값 입력

		printf("3 이상의 값을 입력하세요 : ");

		scanf_s("%d", &num);
	}

	printf("결과 : %d\n", fibonacci(num));

	return 0;
}

int fibonacci(int n){

	int an, i;

	int an_1 = 1, an_2 = 1; // an_1은 a_(n-1)을 의미, an_2는 a_(n-2)를 의미

	for (i = 3; i <= n; i++) {

		an = an_1 + an_2; // an = a_(n-1) + a_(n-2) (단, n >= 3)
		an_2 = an_1;
		an_1 = an;

	}

	return an;
}