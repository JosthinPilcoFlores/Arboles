#ifndef TREE_H
#define TREE_H
struct node {
  int data;
  struct node*left;
  struct node* right;
};
struct node* newNode(int data);
void struct node* build123();
#endif
