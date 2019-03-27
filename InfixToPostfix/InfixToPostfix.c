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

void cal_postfix(char* myfix); // infix 수식을 postfix로 변환
int priority(char x); // operator 우선 순위 값 return

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

		printf("Top -> %c\n", myStack[top]);
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

		printf("%c\n", myStack[i]);
	}

	printf("\n");
}

void cal_postfix(char* myfix) {

	char result[100];
	int i, j = 0;
	
	for (i = 0; myfix[i] != '\0'; i++) { // 입력 배열을 Search하면서 operator의 우선순위에 따라 Stack에 Push or Pop

		if (myfix[i] == '+' || myfix[i] == '-' || myfix[i] == '*' || myfix[i] == '/') { // operator를 만나면
			
			if (top > -1) { 
				
				while (priority(myfix[i]) <= priority(myStack[top])) { // 우선순위가 맞을 때까지 Pop

					result[j] = Pop();
					j++;
				}
			}

				Push(myfix[i]);
		}

		else { // operator를 제외한 문자

			result[j] = myfix[i];
			j++;
		}
	}

	while (top != -1) { // Search가 다 끝나고 Stack에 남아 있는 operator Pop

		result[j] = Pop();
		j++;
	}

	for (int k = 0; k <= j ; k++) {

		printf("%c", result[k]);
	}

	printf("\n");
}

int priority(char x) {

	if (x == '*' || x == '/') {

		return 2;
	}

	else if (x == '+' || x == '-') {

		return 1;
	}
}