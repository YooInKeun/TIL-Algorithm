#include <stdio.h>

#define MAX_SIZE 16 // �ִ� vertex ���� 16��

typedef int boolean; // c������ bool Ÿ���� ��� typedef�� ���� ����
#define true 1
#define false 0

int INF = 1000000; // ���Ѵ� ��

boolean visited[MAX_SIZE] = { false, }; // �湮�� vertex�� �Ǻ��ϴ� bool Ÿ�� array
int costFromStart[MAX_SIZE]; // start vertex�κ��� �ٸ� vertex ������ cost�� ������ array

int getMinCostVertex(int* arr); // ����� vertex �߿� ���� cost�� ���� vertex ����
void dijkstra(int v, int arr[MAX_SIZE][MAX_SIZE]); // �ּ� cost ���(���ͽ�Ʈ�� �˰���)
void printResult(); // ��� ���

int main() {

	int start; // ���� vertex

	int graph[MAX_SIZE][MAX_SIZE] = {
		{ 0, 3, INF, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
		{ 3, 0, 1, INF, INF, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
		{ INF, 1, 0, 4, INF,INF, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF },
		{ INF, INF, 4, 0, INF, INF, INF, 6, INF, INF, INF, INF, INF, INF, INF, INF },
		{ 2, INF, INF, INF, 0, 1, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF },
		{ INF, 5, INF, INF, 1, 0, 5, INF, INF, 4, INF, INF, INF, INF, INF, INF },
		{ INF, INF, 1, INF, INF, 5, 0, 8, INF, INF, 2, INF, INF, INF, INF, INF },
		{ INF, INF, INF, 6, INF, INF, 8, 0, INF, INF, INF, 6, INF, INF, INF, INF },
		{ INF, INF, INF, INF, 3, INF, INF, INF, 0, 2, INF, INF, 2, INF, INF, INF },
		{ INF, INF, INF, INF, INF, 4, INF, INF, 2, 0, 4, INF, INF, 6, INF, INF },
		{ INF, INF, INF, INF, INF, INF, 2, INF, INF, 4, 0, 6, INF, INF, 4, INF },
		{ INF, INF, INF, INF, INF, INF, INF, 6, INF, INF, 6, 0, INF, INF, INF, 4 },
		{ INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, INF, INF, 0, 3, INF, INF },
		{ INF, INF, INF, INF, INF, INF, INF, INF, INF, 6, INF, INF, 3, 0, 5, INF },
		{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, 5, 0, 7 },
		{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, INF, 7, 0 }
	};

	printf("������� �����ϼ��� : ");

	scanf_s("%d", &start);

	dijkstra(start, graph); // ���ͽ�Ʈ�� �˰��� ����

	printResult(); // ��� ���

	return 0;
}

int getMinCostVertex(int* arr) { // ����� vertex �߿� ���� cost�� ���� vertex ����

	int min = 9999;

	int idx = 0;
	int vertex_idx;

	for (int i = 0; i < MAX_SIZE; i++) {

		if (costFromStart[i] < min && visited[i] == false) { // start vertex���� �湮���� ���� vertex �߿� cost�� ���� ���� vertex idx ����

			min = costFromStart[i];
			idx = i;
		}
	}

	vertex_idx = idx + 1;

	return vertex_idx;
}

void dijkstra(int v, int arr[MAX_SIZE][MAX_SIZE]) { // �ִ� ��� �� cost ã��(���ͽ�Ʈ�� �˰���)

	int minVertex; //  getMinCostVertex ���� �� ����
	int passThrough; // ���İ��� ����� cost ��

	for (int i = 0; i < MAX_SIZE; i++) { // start vertex���� �ٸ� vertex������ cost �ʱ�ȭ

		costFromStart[i] = arr[v - 1][i];
	}

	visited[v - 1] = true; // �ڱ� �ڽ��� vertex�� �湮�� ������ ó��

	for (int i = 0; i < MAX_SIZE - 1; i++) { // �ٸ� vertex�� �ϳ��� �湮

		minVertex = getMinCostVertex(arr[v - 1]); // start�� ���� cost�� ���� ���� vertex ���ϱ�
		visited[minVertex - 1] = true; // start�� ���� cost�� ���� ���� vertex �湮

		for (int j = 0; j < MAX_SIZE; j++) { // start�� ���� �ٸ� vertex�� ���İ��� ����� cost �� ���

			passThrough = costFromStart[minVertex - 1] + arr[minVertex - 1][j]; // start�� ���� �ٸ� vertex�� ���İ��� ����� cost �� ����

			if (visited[j] == false) { // �湮���� ���� vertex�ε�

				if (passThrough < costFromStart[j]) { // // �ٸ� vertex�� ���İ��� ����� cost ���� �� �۴ٸ�

					costFromStart[j] = passThrough; // �� ���� cost ������ ����
				}
			}
		}
	}
}

void printResult() { // ��� ���

	for (int i = 0; i < MAX_SIZE - 1; i++) {

		printf("���� %2d���� : %2d\n", i, costFromStart[i]);
	}
}