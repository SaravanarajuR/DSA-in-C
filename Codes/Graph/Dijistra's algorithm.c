#include <stdio.h>
#include <stdlib.h>
#define c 9999
#define MAX 10

void dij(int graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (graph[i][j] == 0)
        cost[i][j] = c;
      else
        cost[i][j] = graph[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = c;

    for (i = 0; i < n; i++) {
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }
    }
    printf("\nVisiting %d", nextnode);

    visited[nextnode] = 1;
    for (i = 0; i < n; i++) {
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    }
    count++;
    for (i = 0; i < n; i++) {
      if (i != start && distance[i] != c) {
        printf("\n%d-->%d=%d", start, i, distance[i]);
      }
    }
  }
  printf("\nFinal distances");
  for (i = 0; i < n; i++) {
    printf("\nDistance between %d and %d is %d", start, i, i);
    for (j = pred[i]; j != start; j = pred[j]) {
      printf("<---%d", j);
    }
    printf("<---%d=%d", start, distance[i]);
  }
}

void main() {
  int graph[MAX][MAX], d, i, j, n, u;
  printf("Enter the number of nodes");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the distance between %d and %d(Enter 0 if no path)", i, j);
      scanf("%d", &d);
      graph[i][j] = d;
    }
  }
  printf("Enter the source node");
  scanf("%d", &u);
  dij(graph, n, u);
}
