// Program to create a BST from 1, 2, 3, 4, 5, 6 and convert to AVL

#include <stdio.h>
#include <stdlib.h>
#define MAX(A, B) A > B ? A : B

typedef struct node
{
  int key;
  struct node *left;
  struct node *right;
  int height;
}node;

node *create_node(int key)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->height = 1;
  return new_node;
}

int height(node *root)
{
  if(!root)
  {
    return 0;
  }
  return root->height;
}

int update_height(node *root)
{
  return MAX(height(root->left), height(root->right)) + 1;
}

int height_difference(node *root)
{
  // printf("key %d\tleft %d\tright %d\n", root->key, height(root->left), height(root->right));
  return height(root->left) - height(root->right);
}

node *right_rotate(node *root)
{
  printf("Performing right rotation at node with key %d\n", root->key);
  node *new_root = root->left;
  node *temp = new_root->right;

  new_root->right = root;
  root->left = temp;

  root->height = update_height(root);
  new_root->height = update_height(new_root);

  return new_root;
}

node *left_rotate(node *root)
{
  printf("Performing left rotation at node with key %d\n", root->key);
  node *new_root = root->right;
  node *temp = new_root->left;

  new_root->left = root;
  root->right = temp;

  root->height = update_height(root);
  new_root->height = update_height(new_root);

  return new_root;
}

void rotate(node *root)
{
  int unbalanced = height_difference(root);
  if(unbalanced > 1)
  {
    if(height_difference(root->left) > 0)
    {
      right_rotate(root);
    }
    else
    {
      left_rotate(root->right);
      right_rotate(root);
    }
  }
  else if(unbalanced < -1)
  {
    if(height_difference(root->right) < 0)
    {
      left_rotate(root);
    }
    else
    {
      right_rotate(root->left);
      left_rotate(root);
    }
  }
}

node *insert(node *root, int key)
{
  if(!root)
  {
    return create_node(key);
  }
  else
  {
    if(key < root->key)
    {
      root->left = insert(root->left, key);
    }
    else
    {
      root->right = insert(root->right, key);
    }
  }
  root->height = update_height(root);
  rotate(root);
  return root;
}

int main()
{
  node *root = NULL;

  int bst_arr[] = {1, 2, 3, 4, 5, 6};
  for(int i=0; i<6; i++)
  {
    root = insert(root, bst_arr[i]);
  }
  printf("Height after reconstruction: %d\n", root->height);
}
