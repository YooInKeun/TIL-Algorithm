#include <stdio.h>

int cal_Gcd(int a, int b);

int main() {

	int a, b, c;

	printf("���� �� ���� �Է��ϼ��� : ");

	scanf_s("%d %d", &a, &b);

	c = cal_Gcd(a, b);

	printf("�ִ����� : %d\n", c);

	return 0;
}

cal_Gcd(int a, int b) {

	int bigger;

	if (a >= b) {

		bigger = a;
	}

	else {

		bigger = b;
	}

	for (int i = bigger; i >= 1; i--) {

		if (a%i == 0 && b%i == 0) {

			return i;
		}
	}
}