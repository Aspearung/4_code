#include <stdio.h>

#define MAX_NODES 5

// �׷��� �迭 ����
int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

// ��� n�� ������ ��� �Լ�
void deg(int node) {
    int degree = 0;

    for (int i = 0; i < MAX_NODES; ++i) {
        degree += graph[node - 1][i];
    }

    printf("��� %d�� ������: %d\n", node, degree);
}

// ���� ������ ��� ��� ��� �Լ�
void printAdjacentNodes(int node) {
    printf("��� %d�� ������ ���: ", node);

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
        // ����ڷκ��� ��� �Է� �ޱ�
        printf("��带 �����ϼ��� (1���� %d����, -1�� ����): ", MAX_NODES);
        scanf("%d", &userNode);

        // -1 �Է� �� ����
        if (userNode == -1) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        // �Էµ� ����� ������ ���
        deg(userNode);

        // �Էµ� ���� ������ ��� ���
        printAdjacentNodes(userNode);
    }

    return 0;
}
