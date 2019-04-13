#include <stdio.h>

int cal_Gcd(int a, int b);

int main() {

	int a, b, c;

	printf("정수 두 개를 입력하세요 : ");

	scanf_s("%d %d", &a, &b);

	c = cal_Gcd(a, b);

	printf("최대공약수 : %d\n", c);

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