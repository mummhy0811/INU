#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
/*
기본 틀로 다익스트라를 사용하였습니다. A부터 K까지 순서대로 shortest_path함수로 보내 소요 시간을 계산하였습니다. 
내가 어떤 사람에게 이메일을 보낼 때 필요한 시간은 0이므로, 가장 마지막 사람들끼리의 전달 시간은 빼주었습니다.(sending)
distance와 sending은 둘 다 시간의 합이지만, distance는 마지막 사람의 시간도 포함된 합입니다. (아래 설명에서는 거리라고 표현하였습니다.)
무한루프를 도는 것을 막기 위해 이미 메일을 보낸 사람에게는 다시 보내지 않도록 found배열을 만들어 주었습니다.
*/
#define TRUE 1
#define FALSE 0
#define INF 100000
#define MAX_VERTICES 50

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; //인접행렬형태
}GraphType;

double distance[MAX_VERTICES]; // 그 사람과 본인과의 거리(본인이 보내는 시간도 포함한 시간)
int found[MAX_VERTICES]; //방문 여부
double sending[MAX_VERTICES][MAX_VERTICES]; //메일 전송시 소요 시간(본인이 보내는 시간을 제외한 시간)

int choose(double distance[], int n, int found[]) {
	int i, minpos;
	double min;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && ! found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path(GraphType* g, int start) {
	int u, w;
	for (int i = 0; i < g->n; i++) {
		if (g->weight[start][i] != INF && g->weight[start][i] != 0) { //무한대이거나 0이 아닐 경우, 소요 시간 저장
			distance[i] = 1.0 / g->weight[start][i]; 
			sending[start][i] = INF; //무한대로 초기화.
		}
		else { //무한대이거나 0일 경우, weight값 그대로 저장
			distance[i] = g->weight[start][i];
			sending[start][i] = INF;
		}
		found[i] = FALSE;
	}
	found[start] = TRUE; //첫 시작점은 방문 상태로 시작
	distance[start] = 0; //본인과의 거리는 0임.

	for (int i = 0; i<g->n-1 ; i++) { //모든 정점에 대해
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++) {
			if (!found[w]) //방문하지 않았으면
				if (g->weight[u][w] != INF && distance[u] + 1.0 / g->weight[u][w] <distance[w]) { // 거리가 짧으면 메일 전송 시간도 짧다.
					distance[w] = distance[u] + 1.0 / g->weight[u][w];
					sending[start][w] = distance[u];
				}
				else if(g->weight[u][w] != INF && distance[u] < sending[start][w]) //거리가 더 길더라도, 실제 보내는 시간은 더 빠를 수 있기 때문에 확인.
					sending[start][w] = distance[u];
		}
	}
}

void email(GraphType* g) {
	double ans = 0.0;

	for (int i = 0; i < g->n; i++) //A~K의 모든 사람이 본인과 직접 연결되지 않는 다른 모든 사람에게 이메일을 보냄
		shortest_path(g, i);

	for (int i = 0; i < g->n; i++) { //걸리는 시간 출력
		for (int j = 0; j < g->n; j++) 
			if (g->weight[i][j] == INF) 
				ans = ans + sending[i][j];
	}
	printf("총 소요 시간: %f\n", ans);
}
int main(void) {
	clock_t start, finish;
	double duration;
	start = clock();
	GraphType g = { 11,
	{{0, 19, 3, 11, 13, INF, INF, INF, INF, INF, INF},
	{19, 0, 4, 5, INF, INF, INF, INF, INF, INF, INF},
	{3, 4, 0, 8, 21, INF, INF, INF, INF, INF ,INF},
	{11, 5, 8, 0, INF, 7, 5, INF, 14, INF, 15},
	{13, INF, 21, INF, 0, 24, INF, INF, INF, 6, INF},
	{INF, INF, INF, 7, 24, 0, 17, 8, 3, INF, INF},
	{INF, INF, INF, 5, INF, 17, 0, INF, 15, INF, 12},
	{INF, INF, INF, INF, INF, 8, INF, 0, 11, 7, INF},
	{INF, INF, INF, 14, INF, 3, 15, 11, 0, INF, INF},
	{INF, INF, INF, INF, 6, INF, INF, 7, INF, 0, INF},
	{INF, INF, INF, 15, INF, INF, 12, INF, INF, INF, 0}}
	};
	email(&g);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n===================\n코드 전체 수행시간: %f \n===================\n", duration);
	return 0;
}

