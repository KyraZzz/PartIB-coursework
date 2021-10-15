#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void preorder(Tree *tree)
{
  if (tree == empty)
  {
    return;
  }
  printf("%d \n", tree->value);
  if (tree->left)
  {
    preorder(tree->left);
  }
  if (tree->right)
  {
    preorder(tree->right);
  }
}

int main(void)
{
  Tree *test = empty;

  printf("Empty tree:\n");
  for (int i = 1; i <= 5; i++)
  {
    printf("  member(%d, test) = %d\n", i, tree_member(i, test));
  }

  printf("Inserting 1..5:\n");
  test = tree_insert(1, test);
  test = tree_insert(2, test);
  test = tree_insert(3, test);
  test = tree_insert(4, test);
  test = tree_insert(5, test);

  for (int i = 1; i <= 5; i++)
  {
    printf("  member(%d, test) = %d\n", i, tree_member(i, test));
  }

  /* Challenge section -- remove the comments to enable */
  printf("Challenges: \n");

  printf("Removing 1 & 4:\n");
  test = tree_remove(1, test);
  test = tree_remove(4, test);

  for (int i = 1; i <= 5; i++)
  {
    printf("  member(%d, test) = %d\n", i, tree_member(i, test));
  }

  printf("Freeing the tree\n");
  tree_free(test);

  printf("Custom tests \n");
  printf("Inserting 3, 2, 8, 1, 6, 10:\n");
  test = empty;
  test = tree_insert(3, test);
  test = tree_insert(2, test);
  test = tree_insert(8, test);
  test = tree_insert(1, test);
  test = tree_insert(6, test);
  test = tree_insert(10, test);
  preorder(test);

  int members[] = {3, 2, 8, 1, 6, 10, 11, 0, 9};
  for (int i = 0; i < sizeof(members) / sizeof(int); i++)
  {
    printf("  member(%d, test) = %d\n", members[i], tree_member(members[i], test));
  }

  printf("Removing 8:\n");
  test = tree_remove(8, test);
  printf("Print preorder: \n");
  preorder(test);

  printf("Removing 3:\n");
  test = tree_remove(3, test);
  printf("Print preorder: \n");
  preorder(test);

  tree_free(test);
  return 0;
}

/* 
1. Expected correct output for base exercise:

$ ./lab4
Empty tree:
  member(1, test) = 0
  member(2, test) = 0
  member(3, test) = 0
  member(4, test) = 0
  member(5, test) = 0
Inserting 1..5:
  member(1, test) = 1
  member(2, test) = 1
  member(3, test) = 1
  member(4, test) = 1
  member(5, test) = 1
Freeing the tree

2. Expected correct output for challenge exercise:

$ ./lab4
Empty tree:
  member(1, test) = 0
  member(2, test) = 0
  member(3, test) = 0
  member(4, test) = 0
  member(5, test) = 0
Inserting 1..5:
  member(1, test) = 1
  member(2, test) = 1
  member(3, test) = 1
  member(4, test) = 1
  member(5, test) = 1
Removing 1 & 4:
  member(1, test) = 0
  member(2, test) = 1
  member(3, test) = 1
  member(4, test) = 0
  member(5, test) = 1
Freeing the tree


*/
