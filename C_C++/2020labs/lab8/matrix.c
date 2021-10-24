#include "matrix.h"
#include <stdbool.h>

matrix_t matrix_create(int rows, int cols)
{
  /* Given integer arguments rows and cols, return a new matrix of size rows × cols.
     Initializing the elements of the array is optional, but may help you debug. */
  double *arr = calloc(rows * cols, sizeof(double));
  matrix_t m = {rows, cols, arr};
  return m;
}

double matrix_get(matrix_t m, int r, int c)
{
  /* Return the value in the r-th row and c-th column of m. */
  assert(r < m.rows && c < m.cols);
  return m.elts[m.cols * r + c];
}

void matrix_set(matrix_t m, int r, int c, double d)
{
  assert(r < m.rows && c < m.cols);
  /* Modify the value in the r-th row and c-th column of m to d. */
  m.elts[m.cols * r + c] = d;
}

void matrix_free(matrix_t m)
{
  /* Deallocate the storage associated with the matrix m. */
  free(m.elts);
}

matrix_t matrix_multiply(matrix_t m1, matrix_t m2)
{
  /* Given an n × m matrix m1 and an m × k matrix m2, return the n × k matrix that is
     the matrix product of m1 and m2. You should be able to implement this with
     a simple triply-nested for-loop. */
  matrix_t m = matrix_create(m1.rows, m2.cols);
  for (int i = 0; i < m1.rows; i++)
  {
    for (int j = 0; j < m2.cols; j++)
    {
      int temp_sum = 0;
      for (int k = 0; k < m1.cols; k++)
      {
        temp_sum += m1.elts[m1.cols * i + k] * m2.elts[m2.cols * k + j];
      }
      m.elts[m.cols * i + j] = temp_sum;
    }
  }
  return m;
}

matrix_t matrix_transpose(matrix_t m)
{
  /* Given an n × m matrix m as an argument, return the m × n transposed matrix.
     (That is, if A is the argument and B is the return value, then A(i, j) = B(j, i).) */
  matrix_t t = matrix_create(m.cols, m.rows);
  for (int i = 0; i < m.rows; i++)
  {
    for (int j = 0; j < m.cols; j++)
    {
      t.elts[t.cols * j + i] = m.elts[m.cols * i + j];
    }
  }
  return t;
}

matrix_t matrix_multiply_transposed(matrix_t m1, matrix_t m2)
{
  assert(m1.cols == m2.cols);
  /* Given an n × m matrix m1 and an k × m matrix m2, return the n × k matrix
     that corresponds to m1 times the transpose of m2. */
  matrix_t m = matrix_create(m1.rows, m2.rows);
  for (int i = 0; i < m1.rows; i++)
  {
    for (int j = 0; j < m2.rows; j++)
    {
      int temp_sum = 0;
      for (int k = 0; k < m1.cols; k++)
      {
        temp_sum += m1.elts[m1.cols * i + k] * m2.elts[m2.cols * j + k];
      }
      m.elts[m.cols * i + j] = temp_sum;
    }
  }

  return m;
}

matrix_t matrix_multiply_fast(matrix_t m1, matrix_t m2)
{
  /* This function should also implement matrix multiplication,
     but do it by constructing the transpose of m2, and then
     passing that to matrix_multiply_transposed.  Don’t forget to
     free the transposed matrix when you are done! */
  matrix_t transposed_m2 = matrix_transpose(m2);
  matrix_t result = matrix_multiply_transposed(m1, transposed_m2);
  matrix_free(m2);
  return result;
}

void matrix_print(matrix_t m)
{
  for (int i = 0; i < m.rows; i++)
  {
    for (int j = 0; j < m.cols; j++)
    {
      printf("%g\t", matrix_get(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}
