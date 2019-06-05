#include <stdio.h>

#define MAX_SIZE 16 // 최대 vertex 개수 16개

typedef int boolean; // c에서는 bool 타입이 없어서 typedef로 직접 구현
#define true 1
#define false 0

int INF = 1000000; // 무한대 값

boolean visited[MAX_SIZE] = { false, }; // 방문한 vertex를 판별하는 bool 타입 array
int costFromStart[MAX_SIZE]; // start vertex로부터 다른 vertex 까지의 cost를 저장할 array

int getMinCostVertex(int* arr); // 연결된 vertex 중에 가장 cost가 작은 vertex 리턴
void dijkstra(int v, int arr[MAX_SIZE][MAX_SIZE]); // 최소 cost 계산(다익스트라 알고리즘)
void printResult(); // 결과 출력

int main() {

	int start; // 시작 vertex

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

	printf("출발지를 선택하세요 : ");

	scanf_s("%d", &start);

	dijkstra(start, graph); // 다익스트라 알고리즘 실행

	printResult(); // 결과 출력

	return 0;
}

int getMinCostVertex(int* arr) { // 연결된 vertex 중에 가장 cost가 작은 vertex 리턴

	int min = 9999;

	int idx = 0;
	int vertex_idx;

	for (int i = 0; i < MAX_SIZE; i++) {

		if (costFromStart[i] < min && visited[i] == false) { // start vertex에서 방문하지 않은 vertex 중에 cost가 가장 작은 vertex idx 저장

			min = costFromStart[i];
			idx = i;
		}
	}

	vertex_idx = idx + 1;

	return vertex_idx;
}

void dijkstra(int v, int arr[MAX_SIZE][MAX_SIZE]) { // 최단 경로 및 cost 찾기(다익스트라 알고리즘)

	int minVertex; //  getMinCostVertex 리턴 값 저장
	int passThrough; // 거쳐가는 경우의 cost 값

	for (int i = 0; i < MAX_SIZE; i++) { // start vertex에서 다른 vertex까지의 cost 초기화

		costFromStart[i] = arr[v - 1][i];
	}

	visited[v - 1] = true; // 자기 자신의 vertex는 방문한 것으로 처리

	for (int i = 0; i < MAX_SIZE - 1; i++) { // 다른 vertex를 하나씩 방문

		minVertex = getMinCostVertex(arr[v - 1]); // start로 부터 cost가 가장 작은 vertex 구하기
		visited[minVertex - 1] = true; // start로 부터 cost가 가장 작은 vertex 방문

		for (int j = 0; j < MAX_SIZE; j++) { // start로 부터 다른 vertex를 거쳐가는 경우의 cost 값 계산

			passThrough = costFromStart[minVertex - 1] + arr[minVertex - 1][j]; // start로 부터 다른 vertex를 거쳐가는 경우의 cost 값 저장

			if (visited[j] == false) { // 방문하지 않은 vertex인데

				if (passThrough < costFromStart[j]) { // // 다른 vertex를 거쳐가는 경우의 cost 값이 더 작다면

					costFromStart[j] = passThrough; // 더 작은 cost 값으로 갱신
				}
			}
		}
	}
}

void printResult() { // 결과 출력

	for (int i = 0; i < MAX_SIZE - 1; i++) {

		printf("정점 %2d까지 : %2d\n", i, costFromStart[i]);
	}
}