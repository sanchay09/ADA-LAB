#include <stdio.h>

#define INFINITY 999

int nV;
void printMatrix(int matrix[][nV]);

void floyd(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
}

void printMatrix(int matrix[][nV])
{
    printf("\nAll Pairs Shortest Path is :\n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INFINITY)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &nV);

    int graph[nV][nV];
    printf("Enter the weight of edges in the graph:\n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    floyd(graph);
}
