#include <stdlib.h>
#include <string.h>

int graph[55][55];
int graphSize[55];
int visited[55];
int vertices, degreeSum;

void dfs(int node)
{
    visited[node] = 1;
    vertices++;
    degreeSum += graphSize[node];

    for (int i = 0; i < graphSize[node]; i++)
    {
        int next = graph[node][i];
        if (!visited[next])
            dfs(next);
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize)
{
    memset(graphSize, 0, sizeof(graphSize));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vertices = 0;
            degreeSum = 0;

            dfs(i);

            int edgeCount = degreeSum / 2;
            int required = vertices * (vertices - 1) / 2;

            if (edgeCount == required)
                ans++;
        }
    }

    return ans;
}