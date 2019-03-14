#include <stdio.h>

int fibonacci(int n);

int main() {

	int num;

	printf("���ϰ��� ���� index : ");

	scanf_s("%d", &num);

	while (num < 3) { // 3 �̻��� �� �Է�

		printf("3 �̻��� ���� �Է��ϼ��� : ");

		scanf_s("%d", &num);
	}

	printf("��� : %d\n", fibonacci(num));

	return 0;
}

int fibonacci(int n){

	int an, i;

	int an_1 = 1, an_2 = 1; // an_1�� a_(n-1)�� �ǹ�, an_2�� a_(n-2)�� �ǹ�

	for (i = 3; i <= n; i++) {

		an = an_1 + an_2; // an = a_(n-1) + a_(n-2) (��, n >= 3)
		an_2 = an_1;
		an_1 = an;

	}

	return an;
}