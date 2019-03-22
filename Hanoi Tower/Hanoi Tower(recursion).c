#include <stdio.h>

void hanoi_cal(int n, char from, char mid, char to);

int main() {

	int floor;
	
	printf("몇 개의 층을 이동시키겠습니까? ");

	scanf_s("%d", &floor);
	printf("\n");

	hanoi_cal(floor, 'A', 'B', 'C');

	return 0;
}

void hanoi_cal(int n, char from, char mid, char to) {

	if (n == 1) {

		printf("원판 1 : %c -> %c\n", from, to);
	}

	else {

		hanoi_cal(n - 1, from, to, mid);
		printf("원판 %d : %c -> %c\n", n, from, to);
		hanoi_cal(n - 1, mid, from, to);
	}

}