/*
 * 一年大约有 3.156×10^7 秒。编写一个程序，提示用户输入年龄，然后显示该年龄对应的秒数。
 */

#include <stdio.h>
int main(void)
{
  int age;

  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Your age is equal to %e seconds.\n", age * 3.156e7);

  return 0;
}
