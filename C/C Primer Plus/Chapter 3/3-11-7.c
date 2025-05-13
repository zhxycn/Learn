/*
 * 1英寸相当于 2.54 厘米。编写一个程序，提示用户输入身高（/英寸），然后以厘米为单位显示身高。
 */

#include <stdio.h>
int main(void)
{
  float height;

  printf("Please enter your height in inches: ");
  scanf("%f", &height);

  printf("Your height is %f cm.\n", height * 2.54);

  return 0;
}
