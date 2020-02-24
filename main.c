#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
    return;
}

void selection_sort(double *array, int size)
{
  int min_index;
  for (int i = 0; i < size - 1; i++)
  {
    min_index = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < array[min_index])
        min_index = j;
    }
    swap(&array[i], &array[min_index]);
  }
}

void shell_sort(double *array, int size)
{
  int shift = size >> 1;
  while (shift > 0)
  {
    for (int i = 0; i < size; i++)
    {
      int j = i;
      double c = array[i];
      while ((j >= shift) && (array[j - shift] > c))
      {
        array[j] = array[j - shift];
        j -= shift;
      }
      array[j] = c;
    }
    shift >>= 1;
  }
}

int main()
{
    int N;
    double *array;
    scanf("%d", &N);
    array = (double*) malloc(N * sizeof (double));
    for (int i = 0; i < N >> 1 - 1; i++)
    {
        array[i] = (double)(rand())/RAND_MAX * N;
        printf("%lf ", array[i]);
    }
    printf("\n");
    selection_sort(array, N);
    for (int i = 0; i < N; i++)
    {
        printf("%lf ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        array[i] = (double)(rand())/RAND_MAX * N;
        printf("%lf ", array[i]);
    }
    printf("\n");
    shell_sort(array, N);
    for (int i = 0; i < N; i++)
    {
        printf("%lf ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
