#include <stdio.h>

#define EDGE_MAX_SIZE 7 // edge의 개수
#define VERTEX_MAX_SIZE 5 // vertex의 개수

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
void descendingSort(edge* arr); // edgeList를 오름차순으로 정렬하기 위해 필요(bubble sort)

// union-find algorithm

void initParent(); // 부모 parent 초기화
int find(int v); // 부모 vertex가 무엇인지 찾기
int isSameParent(int a, int b); // 두 vertex(a, b)가 같은 부모인지 판별
void makeUnion(int a, int b); // 부모를 합침

int calculateMst(edge* arr); // minimum spanning tree 구하기
void printMstGraph(); // mst graph 출력

int main() {

	struct edge edgeList[EDGE_MAX_SIZE]; // edge 구조체 배열

	edgeList[0] = createEdge(1, 2, 4);
	edgeList[1] = createEdge(1, 3, 2);
	edgeList[2] = createEdge(1, 4, 5);
	edgeList[3] = createEdge(2, 4, 7);
	edgeList[4] = createEdge(2, 3, 10);
	edgeList[5] = createEdge(2, 5, 8);
	edgeList[6] = createEdge(3, 5, 1);

	initParent(); // 부모 parent 초기화

	descendingSort(edgeList); // edgeList를 오름차순으로 정렬

	printf("최소 비용 : %d\n\n", calculateMst(edgeList));

	printMstGraph();

	return 0;
}

edge createEdge(int v1, int v2, int weight) { // vertex 및 edge(weight) 생성

	struct edge newEdge;

	newEdge.v1 = v1;
	newEdge.v2 = v2;
	newEdge.weight = weight;

	return newEdge;
}

void descendingSort(edge* arr) { // mstGraph는 adjacency matrix로 표현

	struct edge tmpEdge;

	for (int i = 0; i < EDGE_MAX_SIZE -1; i++) { // bubble sort

		for (int j = 0; j < EDGE_MAX_SIZE -1; j++) {

			if (arr[j].weight < arr[j + 1].weight) {

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

			mstGraph[arr[i].v1][arr[i].v2] = arr[i].weight; // mst graph에 표시
			mstGraph[arr[i].v2][arr[i].v1] = arr[i].weight; // mst graph에 표시
		}
	}

	return mst;
}

void printMstGraph() {

	for (int i = 0; i < VERTEX_MAX_SIZE; i++) {

		for (int j = 0; j < VERTEX_MAX_SIZE; j++) {

			printf("%2d ", mstGraph[i][j]); // 2자리 수에 맞게 출력
		}
		printf("\n");
	}

	printf("\n");
}