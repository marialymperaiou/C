#include <stdio.h>
#define clear_line {while (getchar() != '\n');}


int readint ();
double pi_calc (double, int);

int main ()
{
  int n, digits;

  printf("This program calculates the value of pi.\n\n");

  printf("Copyright confilling-shmmy.ntua.gr\n");
  printf("-----------------------------------------------------\n");
  printf("Give the number of loops you want the program to use for the calculation :  ");
  n = readint();

  while (n != 0)
  {
    printf("Give the number of the first decimal digits of the accuracy");
    printf(" that you want to be zero :  ");
    digits = readint();


    int counter = 1, i;
    double guard = 1, pi = 2, pi_next, e;
    for (i = 0; i < digits; i++)
    {
      guard *= 0.1;
    }
   
    pi_next = pi_calc(pi, counter);
    e = pi_next - pi;
 
    while (e >= guard && counter < n) 
    {
      counter += 1; 
      pi = pi_next;
      pi_next = pi_calc(pi, counter);
      e = pi_next - pi;

    }


    printf("\nThe value of pi is %.10f\n", pi); 
    printf("Calculated with %d loops\n", counter);
    printf("With %.10f accuracy\n\n", e);

 
    printf("-----------------------------------------------------\n");
    printf("Give the number of loops you want the program to use for the calculation :  ");
    n = readint();
  }
  return 0;
}

int readint ()
{
  int x, flag;
  do
  {
    flag = scanf("%d", &x);
    clear_line; //Υπενθυμίζω το define που έκανα.
    while (flag != 1)
    {
      printf("This is not an accepted value. Please give again :  ");
      flag = scanf("%d", &x);
      clear_line;
    }
  }
  while (x < 0);
  return (x);
}

double pi_calc (double pi, int n)
{
  double next_pi;
  next_pi = (pi * 4 * n * n)/((2 * n - 1) * (2 * n + 1));

  return (next_pi);
}