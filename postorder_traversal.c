#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left;
  struct node *right;
}node;

node *create_node(int key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  return new_node;
}


void postorder_traversal(node * cur_node)
{
  if(cur_node)
  {
    postorder_traversal(cur_node->left);
    postorder_traversal(cur_node->right);
    printf("%d, ", cur_node->key);
  }

}


int main()
{
  // binary tree
  //        1
  //     /     \
  //    2       3
  //  /  \     /  \
  // 4    5   6    7

  node *root = create_node(1);
  root->left = create_node(2);
  root->right = create_node(3);
  root->left->left = create_node(4);
  root->left->right = create_node(5);
  root->right->left = create_node(6);
  root->right->right = create_node(7);

  printf("\nPreoder : ");
  preorder_traversal(root);

  printf("\nPostorder : ");
  postorder_traversal(root);

  printf("\nInorder : ");
  inorder_traversal(root);

  printf("\n\n");
}
