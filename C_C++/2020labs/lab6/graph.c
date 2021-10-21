#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right)
{
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}

/* Basic Problems */

int size(Node *node)
{
  /* Given a pointer to an unmarked node node, this function returns the total number of distinct,
     non-null nodes reachable fromnode, including itself.If passed a null pointer, it returns 0.
     It also marks all of the nodes reachable from node. */
  int res = 0;
  if (node != NULL && !node->marked)
  {
    node->marked = true;
    res += 1;
    res += size(node->left);
    res += size(node->right);
  }
  return res;
}

void unmark(Node *node)
{
  /* Given a marked node node, this function sets the marked field of node and every node reachable from it to false. */
  if (node != NULL && node->marked)
  {
    node->marked = false;
    unmark(node->left);
    unmark(node->right);
  }
}

bool path_from(Node *node1, Node *node2)
{
  /* Given two nodes node1 and node2, this function returns true if there is a path (via the left and right fields) of length 0
      or more from node1 to node2. If either node1 or node2 is NULL, then this function returns false */
  if (node1 == NULL || node2 == NULL)
  {
    return false;
  }
  if (node1 == node2)
  {
    return true;
  }
  else
  {
    return path_from(node1->left, node2) || path_from(node1->right, node2);
  }
}

bool cyclic(Node *node)
{
  /* This function returns true if there is a path of length 1 or more from node to itself, and false otherwise */
  if (node == NULL)
  {
    return false;
  }
  return path_from(node->left, node) || path_from(node->right, node);
}

/* Challenge problems */

static int get_nodes_util(Node *node, Node **dest, int i)
{

  if (node == NULL || node->marked)
  {
    return i;
  }

  dest[i++] = node;
  node->marked = true;
  i = get_nodes_util(node->left, dest, i);
  i = get_nodes_util(node->right, dest, i);

  return i;
}

void get_nodes(Node *node, Node **dest)
{
  /* This function receives a node pointer node, and a pointer into a buffer of node pointers dest, as arguments.
     The get_node function should then update the buffer with all of the unmarked nodes reachable from node via paths that only go through unmarked nodes. */
  get_nodes_util(node, dest, 0);
}

void graph_free(Node *node)
{
  /* This function should free a graph.  It should find the nodes to deallocate by declaring an automatic array of the right size
  and passing a pointer into this array to get_nodes. Your implementation of graph_free should not be recursive,
  and should not allocate any memory beyond the stack allocation of the buffer storing the reachable nodes. */
  if (node->marked)
  {
    unmark(node);
  }
  Node **dest = malloc(sizeof(Node) * size(node));
  for (int i = 0; i < size(node); i++)
  {
    dest[i] = NULL;
  }
  get_nodes(node, dest);
  int cnt = 0;
  while (dest[cnt] != NULL)
  {
    free(dest[cnt]);
  }
  free(dest);
}
