#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void display(int queue[], int qno, int f[], int r[], int bott[]) {
  if (f[qno] == bott[qno] && r[qno] == bott[qno])
    printf("\n Queue %d is empty. \n", qno);
  else {
    for (int i = f[qno]; i <= r[qno]; i++) {
      printf("%d\n", queue[i]);
    }
  }
}

int main() {
  int queue[MAX], ele;
  int bott[10], limit[10], f[10], r[10];
  int i, n, qno, size, ch, reply;
  printf("How many queues you want to enter? : ");
  scanf("%d", &n);
  size = MAX / n;
  bott[0] = -1;
  for (i = 1; i < n; i++)
    bott[i] = bott[i - 1] + size;
  for (i = 0; i < n; i++) {
    limit[i] = bott[i] + size;
  }
  for (i = 0; i < n; i++)
    f[i] = r[i] = bott[i];
  printf("\tChoose Operation");
  printf("\n 1. Insert in element Queue");
  printf("\n 2. Delete element from a Queue");
  printf("\n 3. display a queue");
  printf("\n 3. Exit \n");
  while (1) {
    printf("Choose operation : ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("\nChoose queue (0 to %d) : ", n - 1);
      scanf("%d", &qno);
      printf("Element to be entered in queue number %d : ", qno);
      scanf("%d", &ele);
      if (r[qno] == limit[qno]) {
        printf("Queue %d is full \n", qno);
      } else if (f[qno] == bott[qno] && r[qno] == bott[qno]) {
        f[qno]++;
        r[qno]++;
        queue[r[qno]] = ele;
        printf("%d is inserted in queue number %d.\n", ele, qno);
        display(queue, qno, f, r, bott);
      } else {
        r[qno]++;
        queue[r[qno]] = ele;
        printf("\n%d is inserted in queue number %d.\n", ele, qno);
        display(queue, qno, f, r, bott);
      }
      break;
    case 2:
      printf("\nChoose queue (0 to %d) : ", n - 1);
      scanf("%d", &qno);
      if (f[qno] == bott[qno] && r[qno] == bott[qno])
        printf("\n Queue %d is empty. \n", qno);
      else {
        f[qno]++;
        ele = queue[f[qno]];
        printf("%d is deleted from queue number %d \n\n", ele, qno);
        display(queue, qno, f, r, bott);
      }
    case 3:
      printf("\nChoose queue (0 to %d) : ", n - 1);
      scanf("%d", &qno);
      display(queue, qno, f, r, bott);
    case 4:
      break;
    default:
      printf("Invalid operation \n");
    }
  }
  return 0;
}
