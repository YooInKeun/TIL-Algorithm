#include <stdio.h>

int cal_Lcm(int a, int b);

int main() {

	int a, b, c;

	printf("���� �� ���� �Է��ϼ��� : ");

	scanf_s("%d %d", &a, &b);

	c = cal_Lcm(a, b);

	printf("�ּҰ���� : %d\n", c);

	return 0;
}

cal_Lcm(int a, int b) {

	int bigger;

	if (a >= b) {

		bigger = a;
	}

	else {

		bigger = b;
	}

	for (int i = bigger; i <=a*b; i++) {

		if (i%a == 0 && i%b == 0) {

			return i;
		}
	}
}