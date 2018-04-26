#include <stdio.h>
#include <stdlib.h>
#define N 3

void array_creation (int [][]);
void print_array1 (int [][]);
void print_array2 (int [][]);
void reverse_array (int [][], int[][]);
int tridiagonal (int [][]);
int triangular (int [][]);

int main ()
{
  printf("---------------------------------------------------\n");
  printf("Give an array %dx%d :\n", N, N);
  int A[N][N]; 
  array_creation(A); 
  printf("\n");
  print_array1(A); 
  printf("\n");
  print_array2(A); 
  printf("\n");
  int B[N][N]; 
  reverse_array(A, B); 
  printf("The reverse array is :\n");
  print_array1(B); 
  int result;
  result = tridiagonal(A); 
  if (result == 0)
  {
    printf("The array is not tridiagonal\n");
  }
  else
  {
    printf("The array is tridiagonal\n");
  }
  result = triangular(A); 
  if (result == 0)
  {
    printf("The array is upper and down triangular\n");
  }
  else if (result == 1)
  {
    printf("The array is down triangular\n");
  }
  else if (result == 2)
  {
    printf("The array is upper triangular\n");
  }
  else
  {
    printf("The array is not triangular\n");
  }
  system("pause");
  return 0;
}

void array_creation (int pin[N][N])
{
  int i, j;
  for (i = 0; i < N; i++) 
  {
    for (j = 0; j < N; j++)
    {
      scanf("%d", &pin[i][j]); 
    }
  }
}

void print_array1 (int pin[N][N])
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%d\t", pin[i][j]); 
    }
    printf("\n"); 
  }
}

void print_array2 (int pin[N][N])
{
  int i, j, step;
  step = 1;
  j = 0;
  for (i = 0; i < N; i++) 
  {
    while (j < N && j >= 0)
      
    {
      printf("%d ", pin[i][j]);
      j += step; 
    }

    j -= step;

    step *= - 1; 
  }
  printf("\n");
}

void reverse_array (int pin1[N][N], int pin2[N][N])
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      pin2[j][i] = pin1[i][j]; 
                              
    }
  }
}

int tridiagonal (int pin[N][N])
{
  int flag, i, j;
  flag = 1;
  i = 2;
  while (i < N && flag == 1) 
  {
    j = i; 
    while (j < N && flag == 1) 
    {
      if (pin[j - i][j] != 0 || pin[j][j - i] != 0)
      {
        flag = 0;
      }
      j++;
    }
    i++;
  }
  return (flag); 
}

int triangular (int pin[N][N])
{
  int flag, i, j;
  flag = 0;
  i = 1; 
  while (i < N && flag < 1)
  {
    j = i;
    while (j < N && flag < 1) 
    {
      if (pin[j][j - i] != 0) 
      {
        flag += 1;
      }
      j++;
    }
    i++;
  }
  i = 1;
  while (i < N && flag < 2) 
  {
    j = i;
    while (j < N && flag < 2)
    {
      if (pin[j - i][j] != 0)
      {
        flag += 2;
      }
      j++;
    }
    i++;
  }
  return (flag);
}