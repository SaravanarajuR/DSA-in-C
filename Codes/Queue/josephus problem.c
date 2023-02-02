#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *head = 0, *newnode, *tail = 0, *temp, *del;

void find(struct node *start, int k, int i) {
  temp = start;
  for (int i; i < k; i++) {
    temp = temp->next;
  }
  del = temp->next;
  temp->next = temp->next->next;
  free(del);
  while (temp->next == temp) {
    printf("%d", temp->data);
    return;
  }
  find(temp, k, 1);
}

void main() {
  int n, d, k, l;
  printf("\nEnter the number of nodes");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("\nEnter the data");
    scanf("%d", &d);
    newnode = malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = 0;
    if (head == NULL) {
      head = tail = newnode;
    } else {
      newnode->next = head;
      tail->next = newnode;
      tail = newnode;
    }
  }
  printf("Enter the k value");
  scanf("%d", &k);
  find(head, k, 2);
}
