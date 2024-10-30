#include "tree.h"
#include <stdlib.h>

struct node* newNode(int data){
  struct node* node = malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*struct node* insert(struct node* node, int data){
  if(node == NULL)
    return newNode(data);
  if(data <= node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);
  return node;
}*/

struct node* insert(struct node* node, int data){
  if(node)
    if(data <= node->data)
      node->left = insert(node->left, data);
    else
      node->right = insert(node->right, data);
  else
    node = newNode(data);
  return node;
}

/*struct node* build123(){
  struct node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  return root;
}*/

struct node* build123(){
  struct node* root = insert(NULL, 2);
  root = insert(root, 1);
  root = insert(root, 2);
  return root;
}

int size(struct node* node){
  if (node == NULL)
    return 0;
  return 1+size(root->left)+size(root->right);
}
