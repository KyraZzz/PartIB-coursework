#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail)
{
  /* malloc() will be explained in the next lecture! */
  List *cell = (List *)malloc(sizeof(List));
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
    sum += list->head;
    list = list->tail;
  }
  return sum;
}

void iterate(int (*f)(int), List *list)
{
  /* apply f to each element of the list */
  while (list != NULL)
  {
    list->head = f(list->head);
    list = list->tail;
  }
}

void print_list(List *list)
{
  /* print a comma-separated list of elements */
  printf("[");
  while (list->tail != NULL)
  {
    printf("%d, ", list->head);
    list = list->tail;
  }
  printf("%d]\n", list->head);
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2)
{
  /* Given two increasing lists, return one linked list containing all of the elements of the two arguments in increasing order. */
  if (list1 == NULL)
  {
    return list2;
  }
  else if (list2 == NULL)
  {
    return list1;
  }
  List *result = NULL;
  if (list1->head <= list2->head)
  {
    result = list1;
    result->tail = merge(list1->tail, list2);
  }
  else
  {
    result = list2;
    result->tail = merge(list1, list2->tail);
  }
  return result;
}

void split(List *list, List **list1, List **list2)
{
  /* Each linked list containing half of the list */
  // when 0 or 1 element
  if (list == NULL || list->tail == NULL)
  {
    *list1 = list;
    *list2 = NULL;
    return;
  }
  // more than two elements
  *list1 = list;
  *list2 = list->tail;
  split(list->tail->tail, &((*list1)->tail), &((*list2)->tail));
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort2(List *list)
{
  if (list == NULL || list->tail == NULL)
  {
    return list;
  }
  else
  {
    List *list1;
    List *list2;

    split(list, &list1, &list2);
    list1 = mergesort2(list1);
    list2 = mergesort2(list2);
    return merge(list1, list2);
  }
}
