/*
 * 1个水分子的质量约为 3.0×10^−23 克。1夸脱水大约是 950 克。编写一个程序，
 * 提示用户输入水的夸脱数，并显示水分子的数量。
 */

#include <stdio.h>
int main(void)
{
  float quarts;

  printf("Enter the amount of water in quarts: ");
  scanf("%f", &quarts);

  printf("There are %e molecules in %f quarts of water.\n",
         quarts * 950 / 3.0e-23, quarts);

  return 0;
}
