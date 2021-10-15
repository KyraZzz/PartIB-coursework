#include <ctype.h>
#include <string.h>
#include "revwords.h"
#include <stdio.h>

void reverse_substring(char str[], int start, int end)
{
  /* takes a string str, indices start & end, reverse the substring between two indices */
  int i = start;
  int j = end;
  while (i < j)
  {
    char temp = str[i];
    str[i++] = str[j];
    str[j--] = temp;
  }
}

int find_next_start(char str[], int len, int i)
{
  /* takes a string str with length and index i, 
     returns the index k which is the starting position of the next word
    begining at index i or later */
  int k = (((i == 0) && isalpha(str[i])) || (i >= 1 && isalpha(str[i - 1]))) ? i : -1;
  if (k == -1)
  {
    while (isalpha(str[i]) && i < strlen(str))
    {
      i++;
    }
    k = i + 1;
  }
  return k > strlen(str) ? -1 : k;
}

int find_next_end(char str[], int len, int i)
{
  /* string str and length and index i, return the first index k past the end of the word starting at i */
  int k = i;
  while (isalpha(str[i]))
  {
    k = i++;
  }
  return k;
}

void reverse_words(char s[])
{
  /* takes a string and reverse all the words in it */
  int i = 0;
  while (i != strlen(s))
  {
    int start = find_next_start(s, strlen(s) - i, i);
    int end = find_next_end(s, strlen(s) - i, start);
    if (start == -1 || start >= end)
    {
      break;
    }
    reverse_substring(s, start, end);
    i = end;
  }
}
