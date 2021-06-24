#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail)
{
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list)
{
  /* take a list and sum up all elements. */
  int sum = 0;
  while (list != NULL)
  {
    sum += (*list).head;
    list = list->tail;
  }
  return sum;
}

void iterate(int (*f)(int), List *list)
{
  /* apply f to each element of the list */
  while (list != NULL)
  {
    (*list).head = f((*list).head);
    list = list->tail;
  }
}

void print_list(List *list)
{
  /* print a comma-separated list of elements */
  printf("[");
  while (list->tail != NULL)
  {
    printf("%d, ", (*list).head);
    list = list->tail;
  }
  printf("%d]\n", (*list).head);
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2)
{
  /* Given two increasing lists, return one linked list containing all of the elements of the two arguments in increasing order. */
  List *res = malloc(sizeof(List));
  while (list1 != NULL && list2 != NULL)
  {
    if (list1->head < list2->head)
    {
      res = list1;
      list1 = list1->tail;
    }
    else
    {
      res = list2;
      list2 = list2->tail;
    }
    res = res->tail;
  }

  if (list1 != NULL)
  {
    res = list1;
  }
  if (list2 != NULL)
  {
    res = list2;
  }
  return res;
}

void split(List *list, List **list1, List **list2)
{
  /* Each linked list containing half of the list */
  // when 0 or 1 element
  if (list == NULL || list->tail == NULL)
  {
    return;
  }
  else
  {
    // more than two elements
    while (list != NULL && list->tail != NULL)
    {
      (*list1)->head = list->head;
      (*list2)->head = list->tail->head;
      list = list->tail->tail;
      (*list1) = (*list1)->tail;
      (*list2) = (*list2)->tail;
    }
    (*list1) = list;
  }
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort2(List *list)
{
  printf("hihiii");
  if (list == NULL || list->tail == NULL)
  {
    return list;
  }
  else
  {
    printf("hihiii");
    List *list1;
    List *list2;

    split(list, &list1, &list2);
    list1 = mergesort2(list1);
    list2 = mergesort2(list2);
    printf("list1: %d, list2: %d\n", list1->head, list2->head);
    return merge(list1, list2);
  }
}
