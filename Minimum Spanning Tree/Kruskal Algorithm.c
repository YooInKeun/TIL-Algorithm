#include <stdio.h>

#define EDGE_MAX_SIZE 24 // edge의 개수
#define VERTEX_MAX_SIZE 16 // vertex의 개수

typedef struct edge{ // edge 구조체 정의

	int v1; // vertex1
	int v2; // vertex2
	int weight; // edge의 weight(cost)

}edge;

typedef int boolean; // c에서는 bool 타입이 없어서 typedef로 직접 구현
#define true 1
#define false 0

int parent[EDGE_MAX_SIZE +1]; // union-find 알고리즘에 사용할 parent 배열
int mstGraph[VERTEX_MAX_SIZE][VERTEX_MAX_SIZE] = {0, }; // mst graph는 adjacency matrix로 표현

edge createEdge(int v1, int v2, int weight); // vertex 및 edge(weight) 생성
void ascendingSort(edge* arr); // edgeList를 오름차순으로 정렬하기 위해 필요(bubble sort)

// union-find algorithm

void initParent(); // 부모 parent 초기화
int find(int v); // 부모 vertex가 무엇인지 찾기
int isSameParent(int a, int b); // 두 vertex(a, b)가 같은 부모인지 판별
void makeUnion(int a, int b); // 부모를 합침

int calculateMst(edge* arr); // minimum spanning tree 구하기
void printMstGraph(); // mst graph 출력

int main() {

	struct edge edgeList[EDGE_MAX_SIZE]; // edge 구조체 배열

	edgeList[0] = createEdge(1, 2, 3);
	edgeList[1] = createEdge(1, 5, 2);
	edgeList[2] = createEdge(2, 3, 1);
	edgeList[3] = createEdge(2, 6, 5);
	edgeList[4] = createEdge(3, 4, 4);
	edgeList[5] = createEdge(3, 7, 1);
	edgeList[6] = createEdge(4, 8, 6);
	edgeList[7] = createEdge(5, 6, 1);
	edgeList[8] = createEdge(5, 9, 3);
	edgeList[9] = createEdge(6, 7, 5);
	edgeList[10] = createEdge(6, 10, 4);
	edgeList[11] = createEdge(7, 8, 8);
	edgeList[12] = createEdge(7, 11, 2);
	edgeList[13] = createEdge(8, 12, 6);
	edgeList[14] = createEdge(9, 10, 2);
	edgeList[15] = createEdge(9, 13, 2);
	edgeList[16] = createEdge(10, 11, 4);
	edgeList[17] = createEdge(10, 14, 6);
	edgeList[18] = createEdge(11, 12, 6);
	edgeList[19] = createEdge(11, 15, 4);
	edgeList[20] = createEdge(12, 16, 4);
	edgeList[21] = createEdge(13, 14, 3);
	edgeList[22] = createEdge(14, 15, 5);
	edgeList[23] = createEdge(15, 16, 7);

	initParent(); // 부모 parent 초기화

	ascendingSort(edgeList); // edgeList를 오름차순으로 정렬

	printf("최소 비용 : %d\n\n", calculateMst(edgeList)); // mst 계산

	printMstGraph(); // mst graph 출력

	return 0;
}

edge createEdge(int v1, int v2, int weight) { // vertex 및 edge(weight) 생성

	struct edge newEdge;

	newEdge.v1 = v1;
	newEdge.v2 = v2;
	newEdge.weight = weight;

	return newEdge;
}

void ascendingSort(edge* arr) { // edgeList를 오름차순으로 정렬하기 위해 필요(bubble sort)

	struct edge tmpEdge;

	for (int i = 0; i < EDGE_MAX_SIZE -1; i++) { // bubble sort

		for (int j = 0; j < EDGE_MAX_SIZE -1; j++) {

			if (arr[j].weight > arr[j + 1].weight) {

				tmpEdge = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmpEdge;
			}
		}
	}
}

void initParent() { // 부모 parent 초기화

	for (int i = 1; i <= EDGE_MAX_SIZE; i++) {

		parent[i] = i;
	}
}

int find(int v) { // 부모 vertex가 무엇인지 찾기

	if (v == parent[v]) {

		return v;
	}

	else {

		return parent[v] = find(parent[v]);
	}
}

int isSameParent(int a, int b) { // 두 vertex(a, b)가 같은 부모인지 판별

	a = find(a);
	b = find(b);

	if (a == b) {

		return true;
	}

	else {

		return false;
	}
}

void makeUnion(int a, int b) { // 부모를 합침

	a = find(a);
	b = find(b);

	if (a != b) {

		parent[b] = a;
	}
}

int calculateMst(edge* arr) { // minimum spanning tree 구하기

	int mst = 0;

	for (int i = 0; i < EDGE_MAX_SIZE; i++) {

		if (isSameParent(arr[i].v1, arr[i].v2) == false) { // 같은 부모가 아니면

			mst += arr[i].weight; // mst 값 갱신
			makeUnion(arr[i].v1, arr[i].v2); // 부모 합치기

			mstGraph[arr[i].v1-1][arr[i].v2-1] = arr[i].weight; // mst graph에 표시
			mstGraph[arr[i].v2-1][arr[i].v1-1] = arr[i].weight; // mst graph에 표시
		}
	}

	return mst;
}

void printMstGraph() { // mst graph 출력

	for (int i = 0; i < VERTEX_MAX_SIZE; i++) {

		for (int j = 0; j < VERTEX_MAX_SIZE; j++) {

			printf("%2d ", mstGraph[i][j]); // 2자리 수에 맞게 출력
		}
		printf("\n");
	}

	printf("\n");
}
