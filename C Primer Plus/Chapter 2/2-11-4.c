/*
 * Indiana Sloth 编写了下面的程序，并征求你的意见。请帮助他评定。
 *
 * #include <stdio.h>
 * int main{void}
 * (
 *   int s
 *
 *   s := 56;
 *   printf(There are s weeks in a year.);
 *   return 0;
 *
 */

#include <stdio.h>
int main(void) // 函数的参数声明使用圆括号
{
  int s; // 语句以分号结束

  s = 56; // 使用等号赋值
  printf("There are %d weeks in a year.\n", s); // 使用占位符在字符串中引用变量
  return 0;
} // 函数体使用花括号标记开始与结束
