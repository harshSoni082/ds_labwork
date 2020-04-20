// Program to create a BST from 1, 2, 3, 4, 5, 6 and find which nodes are unbalanced

#include <stdio.h>
#include <stdlib.h>
#define MAX(A, B) A > B ? A : B

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
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *insert(node *root, int key)
{
  if(!root)
  {
    root = create_node(key);
  }
  else
  {
    if(key < root->key)
    {
      if(!root->left)
      {
        root->left = create_node(key);
        return NULL;
      }
      insert(root->left, key);
    }
    else
    {
      if(!root->right)
      {
        root->right = create_node(key);
        return NULL;
      }
      insert(root->right, key);
    }
  }
  return root;
}

int height(node *root)
{
  if(!root)
  {
    return -1;
  }
  return MAX(height(root->left), height(root->right)) + 1;
}


void find_balanced(node *root)
{
  if(root)
  {
    find_balanced(root->left);
    int l = height(root->left);
    int r = height(root->right);
    if(l - r > 1)
    {
      printf("The node with key %d is left heavy with %d nodes\n", root->key, l+1);
    }
    else if(l - r < -1)
    {
      printf("The node with key %d is right heavy with %d nodes\n", root->key, r+1);
    }
    find_balanced(root->right);
  }
}


int main()
{
  node *root = NULL;

  int bst_arr[] = {1, 2, 3, 4, 5, 6};
  for(int i=0; i<6; i++)
  {
    if(i == 0)
    {
      root = insert(root, bst_arr[i]);
    }
    else
    {
      insert(root, bst_arr[i]);
    }
  }
  find_balanced(root);
}
