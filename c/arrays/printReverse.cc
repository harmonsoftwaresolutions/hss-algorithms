#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

void reversePrint(Node *head)
{
  if (!head)
    return;

  if (head->next)
    reversePrint(head->next);

  cout << head->data << endl;

  return;
};

int main()
{
  Node* root = (struct Node*) malloc(sizeof(struct Node*));
  Node* new_node = (struct Node*) malloc(sizeof(struct Node*));

  root->data = 1;
  root->next = new_node;

  new_node->data = 2;
  new_node->next = NULL;

  reversePrint(root);

  return 0;
};
