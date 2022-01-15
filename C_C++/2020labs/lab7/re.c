#include <stdlib.h>
#include <stdio.h>
#include "re.h"
#define MAX(X, Y) ((X < Y) ? Y : X)

arena_t create_arena(int size)
{
  /* Create a new arena */
  arena_t arena = malloc(sizeof(struct arena));
  arena->size = size;
  arena->current = 0;
  arena->exps = malloc(size * sizeof(Regexp));
  return arena;
}

void arena_free(arena_t a)
{
  /* Given an arena a, the arena_free function should deallocate the arena
     and its associated storage.This should be a simple, non-recursive function! */
  free(a->exps);
  free(a);
}

Regexp *re_alloc(arena_t a)
{
  /* Given an arena a, the re_alloc function should allocate a new Regexp and
     return a pointer to it. If the arena lacks room to allocate a new Regexp,
     it should return NULL. */
  if (a != NULL && a->current != a->size - 1)
  {
    int pos = a->current;
    a->current = a->current + 1;
    return a->exps + pos;
  }
  return NULL;
}

Regexp *re_chr(arena_t a, char c)
{
  /* Allocate a regexp matching the character c, allocating from the arena a.
     Return NULL if no memory is available. */
  Regexp *pos = re_alloc(a);
  if (pos != NULL)
  {
    // pos = malloc(sizeof(Regexp));
    pos->type = CHR;
    pos->data.chr = c;
    return pos;
  }
  return NULL;
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2)
{
  /* Allocate a regexp representing the alternative of r1 and r2 from the arena a.
     Return NULL if nomemory is available. */
  if (r1 == NULL || r2 == NULL)
  {
    return NULL;
  }
  Regexp *pos = re_alloc(a);
  if (pos != NULL)
  {
    // pos = malloc(sizeof(Regexp));
    pos->type = ALT;
    pos->data.pair.fst = r1;
    pos->data.pair.snd = r2;
    return pos;
  }
  return NULL;
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2)
{
  /* Allocate a regexp representing the sequencing ofr1 and r2 from the arena a.
     Return NULL if nomemory is available. */
  if (r1 == NULL || r2 == NULL)
  {
    return NULL;
  }
  Regexp *pos = re_alloc(a);
  if (pos != NULL)
  {
    // pos = malloc(sizeof(Regexp));
    pos->type = SEQ;
    pos->data.pair.fst = r1;
    pos->data.pair.snd = r2;
    return pos;
  }
  return NULL;
}

int re_match(Regexp *r, char *s, int i)
{
  /* Given a regular expression r,  a string s,  and a valid index into the string i,
     this function should return an integer.  If the function returns a non negative j,
     then the regular expression should match the substring running from i to j,
     including i but not j.  */
  int j = -1;
  if (r != NULL && i != -1 && s != NULL)
  {
    switch (r->type)
    {
    case CHR:
      j = s[i] == r->data.chr ? i + 1 : -1;
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT)
      {
        // if the first pair is ALT e.g., (ac+bc)()
        i = re_match(r->data.pair.fst, s, i);
      }
      else
      {
        // if the first pair is SEQ e.g., (ac)()
        i = re_match(r->data.pair.fst, s, i);
      }
      if (r->data.pair.snd->type == ALT)
      {
        j = re_match(r->data.pair.snd, s, i);
      }
      else
      {
        j = re_match(r->data.pair.snd, s, i);
      }
      break;
    case ALT:
      j = MAX(re_match(r->data.pair.fst, s, i), re_match(r->data.pair.snd, s, i));
      break;
    }
  }
  return j;
}

void re_print(Regexp *r)
{
  if (r != NULL)
  {
    switch (r->type)
    {
    case CHR:
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT)
      {
        printf("(");
        re_print(r->data.pair.fst);
        printf(")");
      }
      else
      {
        re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT)
      {
        printf("(");
        re_print(r->data.pair.snd);
        printf(")");
      }
      else
      {
        re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  }
  else
  {
    printf("NULL");
  }
}
