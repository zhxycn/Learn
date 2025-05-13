/*
 * Dottie Cawm 编写了一个程序，请找出程序中的错误。
 *
 * #include <stdio.h>
 * main
 * (
 *   float g; h;
 *   float tax, rate;
 *
 *   g = e21;
 *   tax = rate*g;
 * )
 *
 */

#include <stdio.h>
int main(void) // main 函数的返回值类型为 int
{
  float g, h; // h 变量已声明但未初始化
  float tax, rate; // rate 变量已声明但未初始化

  g = 1e21; // 浮点数 e 计数法 e 前的数字为小数部分，不能缺省
  tax = rate * g;
} // 函数体使用花括号标记开始与结束

//除此之外，该程序未输出任何内容，且缺少 return 语句。
