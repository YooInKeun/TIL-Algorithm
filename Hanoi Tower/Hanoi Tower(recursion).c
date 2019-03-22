#include <stdio.h>

void hanoi_cal(int n, char from, char mid, char to);

int main() {

	int floor;
	
	printf("�� ���� ���� �̵���Ű�ڽ��ϱ�? ");

	scanf_s("%d", &floor);
	printf("\n");

	hanoi_cal(floor, 'A', 'B', 'C');

	return 0;
}

void hanoi_cal(int n, char from, char mid, char to) {

	if (n == 1) {

		printf("���� 1 : %c -> %c\n", from, to);
	}

	else {

		hanoi_cal(n - 1, from, to, mid);
		printf("���� %d : %c -> %c\n", n, from, to);
		hanoi_cal(n - 1, mid, from, to);
	}

}