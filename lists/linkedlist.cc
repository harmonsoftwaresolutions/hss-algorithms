#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* InsertHead(Node *head, int data)
{
  Node* node = (struct Node*) malloc(sizeof(struct Node*));
  node->data = data;
  node->next = NULL;
  if (!head)
    return node;

  node->next = head;
  head = node;

  return head;
};

Node* InsertTail(Node *head, int data)
{
  Node* node = (struct Node*) malloc(sizeof(struct Node*));
  node->data = data;
  node->next = NULL;

  if (!head)
    cout << "Head was NULL\n";
    return node;

  Node* cursor = head;
  while (cursor->next)
    cursor = cursor->next;

  cursor->next = node;

  return head;
};

Node* InsertNth(Node *head, int data, int position)
{
  Node* node = (struct Node*) malloc(sizeof(struct Node*));
  node->data = data;
  node->next = NULL;
  if (!head)
    return node;

  Node* cursor = head;
  int cnt = 0;
  while (cnt < position)
    cursor = cursor->next;

  if (position == 0) {
    node->next = cursor;
    return node;
  }
  node->next = cursor->next;
  cursor->next = node;

  return head;
};

int main()
{
  Node* root = InsertHead(NULL, 10);
  cout << "NULL InsertHead, should be [10]\n";
  printf("Node 1%p, %d\n", root, root->data);

  root = InsertHead(root, 5);
  cout << "Head InsertHead, should be [5,10]\n";
  printf("Node 1\t%p, %d\n", root, root->data);
  printf("Node 2\t%p, %d\n", root->next, root->next->data);

  root = InsertNth(root, 4, 0);
  cout << "Insert pos 0, should be [4,5,10]\n";
  printf("Node 1\t%p, %d\n", root, root->data);
  printf("Node 2\t%p, %d\n", root->next, root->next->data);
  printf("Node 3\t%p, %d\n", root->next->next, root->next->next->data);
  // printf("InsertNth, root pntr %p data %d\n", root, root->data);
  // printf("InsertNth, root->next pntr %p\n", root->next);

  // root = InsertNth(root, 15, 1);
  // printf("root pntr %p\n", root);
  // printf("InsertNth 15 pos 1, root pntr %p data %d\n", root->next, root->next->data);

  return 0;
};
