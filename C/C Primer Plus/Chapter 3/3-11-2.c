/*
 * 编写一个程序，要求提示输入一个 ASCII 码值（如，66），然后打印输入的字符。
 */

#include <stdio.h>
int main(void)
{
  int ascii;

  printf("Please enter an ASCII code: ");
  scanf("%d", &ascii);
  printf("The character of ASCII code %d is %c.\n", ascii, ascii);

  return 0;
}
