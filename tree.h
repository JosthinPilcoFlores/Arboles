#ifndef TREE_H
#define TREE_H
struct node {
  int data;
  struct node*left;
  struct node* right;
};
struct node* newNode(int data);
struct node* insert(struct node* node, int data);
struct node* build123();
int size(struct node* node);
#endif
