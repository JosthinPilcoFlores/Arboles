#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include <assert.h>

int max(int a, int b){
  return (a>b) ? a : b;
}

int min(int a, int b){
  return (a<b) ? a : b;
}

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
  root = insert(root, 3);
  return root;
}

int size(struct node* node){
  if (node == NULL)
    return 0;
  return 1+size(node->left)+size(node->right);
}

int maxDepth(struct node* node){
  if(node==NULL)
    return 0;
  return 1 + max(maxDepth(node->left), maxDepth(node->right));
}

int minValue(struct node* node){
  assert(node != NULL);
  if(node->left == NULL)
    return node->data;
  return minValue(node->left);
}

void printTree(struct node* node){
  if(node == NULL){
    printf(" ");
  }else{
    printTree(node->left);
    printf("%d,", node->data);
    printTree(node->right);
  }
}

void printPostorder(struct node* node){
  if(node == NULL){
    printf(" ");
  }else{
    printTree(node->left);
    printTree(node->right);
    printf("%d,", node->data);
  }
}

int hasPathSum(struct node* node, int sum){
  if(node == NULL)
    return sum == 0;
  //return hasPathSum(node->left,sum == node->data);
  return hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data);
}
