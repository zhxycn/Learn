/*
 * 你刚被 MacroMuscle 有限公司聘用。该公司准备进入欧洲市场，需要一个把英寸单位转换为厘米单位
 * （1 英寸=2.54 厘米）的程序。该程序要提示用户输入英寸值。你的任务是定义程序目标和设计程序。
 */

#include <stdio.h>
int main(void)
{
  float in;	// 声明浮点型变量 in

  printf("Enter a length in inches: ");
  scanf("%f", &in);

  const float cm = in * 2.54f;	// 将两浮点数相乘，同时声明浮点型变量 cm 并将乘积赋值给变量 cm

  printf("The length in centimeters is %f\n", cm);

  getchar();	// 由于 scanf() 获取输入时需要按下 Enter 键，而此时 Enter 键仍在缓冲区，所以需要用一个 getchar() 来刷新缓冲区
  getchar();	// 此处的第二个 getchar() 才会使程序等待击键

  return 0;
}
