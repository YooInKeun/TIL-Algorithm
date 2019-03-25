#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

char myStack[MAX_SIZE];
int top = -1;

void Push(char e);
char Pop();

void IsFull();
void IsEmpty();

void printStack();

void cal_postfix(char* myfix);
int priority(char x);

int main() {

	char myfix[100];

	printf("수식을 입력하세요 : ");

	gets(myfix);

	cal_postfix(myfix);

	return 0;
}

void Push(char e) {

	if (top > MAX_SIZE - 1) {

		IsFull();
	}

	else {

		myStack[++top] = e;
	}
}

char Pop() {

	char tmp;

	if (top <= -1) {

		IsEmpty();
	}

	else {

		printf("Top -> %d\n", myStack[top]);
		printf("\n");

		tmp = myStack[top];

		myStack[top--] = NULL;
	}

	return tmp;
}

void IsFull() {

	printf("Stack Overflow\n");
	printf("\n");

	return -1;

}

void IsEmpty() {

	printf("Stack Underflow\n");
	printf("\n");

	return -1;
}

void printStack() {

	for (int i = top; i >= 0; i--) {

		printf("%d\n", myStack[i]);
	}

	printf("\n");
}

void cal_postfix(char* myfix) {

	char result[100];
	int j = 0;

	/*
	for (int i = 0; myfix[i] != '\0'; i++) {

		if (myfix[i] == '+' || myfix[i] == '-' || myfix[i] == '*' || myfix[i] == '/' || myfix[i] == '(' || myfix[i] == ')') {

			if (priority(myfix[i]) >= priority(myStack[top])) {

				result[j] = Pop();
				j++;
			}

			else {

				Push(myfix[i]);
			}

		}

		else {

			result[j] = myfix[i];
			j++;
		}

		printf("결과 : %s\n", result);
	}

	*/

}

int priority(char x) {

	if (x == '(' || x == ')') {

		return 3;
	}

	else if (x == '*' || x == '/') {

		return 2;
	}

	else if (x == '+' || x == '-') {

		return 1;
	}
}