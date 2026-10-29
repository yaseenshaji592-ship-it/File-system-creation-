
#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
char files[MAX][50];
int n, found;

void BFS(int start, char target[])
{
    int queue[MAX], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%s ", files[v]);

        if (strcmp(files[v], target) == 0)
            found = 1;

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int v, char target[])
{
    int i;

    visited[v] = 1;
    printf("%s ", files[v]);

    if (strcmp(files[v], target) == 0)
        found = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i, target);
    }
}

int main()
{
    int i, j, start;
    char target[50];

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    printf("Enter file/directory names:\n");
    for (i = 0; i < n; i++)
        scanf("%49s", files[i]);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter file name to search: ");
    scanf("%49s", target);

    found = 0;
    BFS(start, target);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;
    printf("\nDFS Traversal: ");
    DFS(start, target);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
