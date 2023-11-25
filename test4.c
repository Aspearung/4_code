#include <stdio.h>

#define MAX_NODES 5

// 그래프 배열 선언
int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

// 노드 n의 분지수 출력 함수
void deg(int node) {
    int degree = 0;

    for (int i = 0; i < MAX_NODES; ++i) {
        degree += graph[node - 1][i];
    }

    printf("노드 %d의 분지수: %d\n", node, degree);
}

// 노드와 인접한 모든 노드 출력 함수
void printAdjacentNodes(int node) {
    printf("노드 %d와 인접한 노드: ", node);

    for (int i = 0; i < MAX_NODES; ++i) {
        if (graph[node - 1][i]) {
            printf("%d ", i + 1);
        }
    }

    printf("\n");
}

int main() {
    int userNode;

    while (1) {
        // 사용자로부터 노드 입력 받기
        printf("노드를 선택하세요 (1부터 %d까지, -1로 종료): ", MAX_NODES);
        scanf("%d", &userNode);

        // -1 입력 시 종료
        if (userNode == -1) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        // 입력된 노드의 분지수 출력
        deg(userNode);

        // 입력된 노드와 인접한 노드 출력
        printAdjacentNodes(userNode);
    }

    return 0;
}
