/*
* Program Name: Project One
*
* Description: A Fahrenheit to Celsius calculator
*
* Author: Dylan Vance n01450847
*
* Date: 9/17/20
*/

#include <stdio.h>

int main(void) {
  int F;
  double C;

  printf("Enter a temperature in Fahrenheit\n");
  scanf("%d", &F);

  C = (100.0/180.0) * (F - 32.0);

  printf("%d degrees Fahrenheit in degrees Celsius is %.2f degrees.\n", F, C);

  return 0;
}