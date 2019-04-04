#include <stdio.h>

#define MAX_SIZE 100

int myStack[MAX_SIZE];
int top = -1;

void Push(int e);
int Pop();

int IsFull();
int IsEmpty();

void printStack();

void nr_hanoi(int n, int from, int by, int to); // Non Recursive Hanoi
void move(int from, int to, int n);

int main() {

	int num;

	printf("원반의 개수를 입력하세요 : ");

	scanf_s("%d", &num);

	printf("\n");
	nr_hanoi(num, 1, 2, 3);
	printf("\n");

	return 0;
}

void nr_hanoi(int n, int from, int by, int to) {

	while (1) {

		while (n > 1) {

			Push(to);
			Push(by);
			Push(from);
			Push(n);
			n--;
			Push(to);
			to = by;
			by = Pop();
		}

		move(from, to, n);

		if (!(top < 0)) {

			n = Pop();
			from = Pop();
			by = Pop();
			to = Pop();

			move(from, to, n);

			n--;
			Push(from);
			from = by;
			by = Pop();
		}

		else {

			break;
		}
	}
}

void move(int from, int to, int n) {

	printf("%d : %c -> %c\n", n, 'A'-1+from, 'A'-1+to);
}

void Push(int e) {

	if(!IsFull()){

		myStack[++top] = e;
	}
}

int Pop() {

	if (!IsEmpty()){

		return myStack[top--];
	}
}

int IsFull() {

	if (top >= MAX_SIZE-1) {

		printf("Stack Overflow\n");
		printf("\n");

		return 1;
	}

	else {

		return 0;
	}
}

int IsEmpty() {

	if (top <= -1) {

		printf("Stack Underflow\n");
		printf("\n");

		return 1;
	}

	else {

		return 0;
	}
}

void printStack() {

	for (int i = top; i >= 0; i--) {

		printf("%d\n", myStack[i]);
	}

	printf("\n");
}