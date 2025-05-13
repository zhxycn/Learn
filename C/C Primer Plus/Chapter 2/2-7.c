/*
 * nogood.c -- 有错误的程序
 *
 * #include <stdio.h>
 * int main()
 * (
 *   int n, int n2, int n3;
 *
 *   /* 该程序有多处错误
 *   n = 5;
 *   n2 = n * n;
 *   n3 = n2 * n2;
 *   printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
 *
 *   return 0;
 * )
 *
 */

#include <stdio.h>
int main()
{
  int n; int n2; int n3; // 语句以分号结束

  // 注释缺少结束标记
  n = 5;
  n2 = n * n;
  n3 = n2 * n2;
  printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);

  return 0;
} // 函数体使用花括号标记开始与结束
