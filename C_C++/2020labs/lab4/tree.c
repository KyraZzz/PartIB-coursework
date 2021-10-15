#include <stdlib.h>
#include "tree.h"
#include <stdio.h>

/* BASE EXERCISE */

int tree_member(int x, Tree *tree)
{
  /* This function takes an integer x and a tree tree, 
      and returns 0 if x does not occur intree, and 1 if it does occur. 
      This function should not allocate or deallocate any memory at all. */
  if (tree == NULL)
  {
    return 0;
  }
  if (tree->value == x)
  {
    return 1;
  }
  return tree_member(x, tree->left) || tree_member(x, tree->right);
}

Tree *tree_insert(int x, Tree *tree)
{
  /* This function should insert x into the tree tree if it is not present, 
  and do nothing otherwise. */
  if (tree == empty)
  {
    tree = (Tree *)malloc(sizeof(Tree));
    tree->value = x;
    tree->left = empty;
    tree->right = empty;
  }
  else if (tree->value < x)
  {
    tree->right = tree_insert(x, tree->right);
  }
  else if (tree->value > x)
  {
    tree->left = tree_insert(x, tree->left);
  }
  return tree;
}

void tree_free(Tree *tree)
{
  /* Given a tree tree as an argument, 
      this function should free all of the memory associated with the tree. 
      This function should recursively call free on each reachable node. */
  if (tree != empty)
  {
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
  }
}

/* CHALLENGE EXERCISE */

void pop_minimum(Tree *tree, int *min, Tree **new_tree)
{
  /* This function should take a nonempty tree tree as its first argument, 
      and then it should 
      (a) return the minimum value held in the tree in the contents of min, and 
      (b) modify tree so that it no longer contains min, returning an updated pointer in new_tree */
  if (tree == empty)
  {
    return;
  }
  else if (tree->left == empty)
  {
    *min = tree->value;
    *new_tree = tree_remove(*min, *new_tree);
    return;
  }
  else
  {
    pop_minimum(tree->left, min, new_tree);
  }
}

Tree *tree_remove(int x, Tree *tree)
{
  /* This function should remove x from the tree tree if it is present, and do nothing otherwise. */
  if (tree == empty)
  {
    return tree;
  }
  else if (tree->value == x)
  {
    if (!tree->left && !tree->right)
    {
      tree = empty;
    }
    // if only has left subtree or only has right subtree, then substitute
    else if (tree->left && !tree->right)
    {
      tree = tree->left;
    }
    else if (!tree->left && tree->right)
    {
      tree = tree->right;
    }
    else
    {
      // if has both left and right subtrees, then pop_minimum on right subtree and substitute it
      int *min_p = (int *)malloc(sizeof(int)); // remember to assign some memory, null pointer points to nothing, cause segmentation error
      Tree **new_tree = &tree->right;
      pop_minimum(tree->right, min_p, new_tree);
      if (min_p)
      {
        tree->value = *min_p;
        tree->right = *new_tree;
      }
    }
  }
  else if (tree->value < x)
  {
    tree->right = tree_remove(x, tree->right);
  }
  else
  {
    tree->left = tree_remove(x, tree->left);
  }
  return tree;
}