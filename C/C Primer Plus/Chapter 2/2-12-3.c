/*
 * 编写一个程序把你的年龄转换成天数，并显示这两个值。这里不用考虑闰年的问题。
 */

#include <stdio.h>
int main(void)
{
  int age, days;

  age = 18;
  days = age * 365;
  printf("Age: %d, Days: %d\n", age, days);

  return 0;
}
