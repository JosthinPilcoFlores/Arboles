#include "tree.h"
#include <stdlib.h>

struct node* newNode(int data){
  struct node* node = malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
}
