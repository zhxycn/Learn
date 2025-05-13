/*
 * 通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。
 */

#include <stdio.h>
int main(void)
{
  const int int_overflow = 2147483647;
  const float float_overflow = 3.4e38;
  const float float_underflow = 0.123456e-38;

  printf("int overflow: %d %d %d\n", int_overflow, int_overflow + 1, int_overflow + 2);
  printf("float overflow: %e %e\n", float_overflow, float_overflow * 10.f);
  printf("float underflow: %e %e\n", float_underflow, float_underflow / 10.f);

  return 0;
}
