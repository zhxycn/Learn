/*
 * 修正下面的程序（在 C 中，/表示除以）。
 *
 * void main(int) / this program is perfect /
 * {
 *   cows, legs integer;
 *   printf("How many cow legs did you count?\n");
 *   scanf("%c", legs);
 *   cows = legs / 4;
 *   printf("That implies there are %f cows.\n", cows);
 * }
 *
 */

#include <stdio.h>
int main(void) /* this program is perfect */
{
  int cows, legs;

  printf("How many cow legs did you count?\n");
  scanf("%d", &legs);

  cows = legs / 4;

  printf("That implies there are %d cows.\n", cows);

  return 0;
}
