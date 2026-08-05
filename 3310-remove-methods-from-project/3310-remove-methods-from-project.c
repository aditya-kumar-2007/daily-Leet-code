#include <stdlib.h>
#include <stdbool.h>

int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int* head_nodes = (int*)malloc(n * sizeof(int));
    int* next_edges = (int*)malloc(invocationsSize * sizeof(int));
    int* to_nodes = (int*)malloc(invocationsSize * sizeof(int));
    
    for (int i = 0; i < n; i++) head_nodes[i] = -1;
    
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        to_nodes[i] = v;
        next_edges[i] = head_nodes[u];
        head_nodes[u] = i;
    }

    bool* suspicious = (bool*)calloc(n, sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0, tail = 0;

    suspicious[k] = true;
    queue[tail++] = k;

    while (head < tail) {
        int curr = queue[head++];
        int edge = head_nodes[curr];
        while (edge != -1) {
            int neighbor = to_nodes[edge];
            if (!suspicious[neighbor]) {
                suspicious[neighbor] = true;
                queue[tail++] = neighbor;
            }
            edge = next_edges[edge];
        }
    }

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        if (!suspicious[u] && suspicious[v]) {
            int* result = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) result[j] = j;
            *returnSize = n;
            free(head_nodes); free(next_edges); free(to_nodes);
            free(suspicious); free(queue);
            return result;
        }
    }

    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!suspicious[i]) result[count++] = i;
    }

    *returnSize = count;
    free(head_nodes); free(next_edges); free(to_nodes);
    free(suspicious); free(queue);
    return result;
}
