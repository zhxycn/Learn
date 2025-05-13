/*
 * 编写一个程序，生成以下输出：
 *
 * For he's a jolly good fellow!
 * For he's a jolly good fellow!
 * For he's a jolly good fellow!
 * Which nobody can deny!
 *
 * 除了 main() 函数以外，该程序还要调用两个自定义函数：一个名为 jolly() ，用于打印前三条消息，
 * 调用一次打印一条；另一个函数名为 deny() ，打印最后一条消息。
 */

#include <stdio.h>
void jolly(void);
void deny(void);
int main(void)
{
  jolly();
  jolly();
  jolly();
  deny();

  return 0;
}

void jolly(void)
{
  printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
  printf("Which nobody can deny!\n");
}
