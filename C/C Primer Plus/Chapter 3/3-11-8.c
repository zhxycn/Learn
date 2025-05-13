/*
 * 在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，1盎司等于2大汤勺，1大汤勺等于3茶勺。
 * 编写一个程序，提示用户输入杯数，并以品脱、盎司、汤勺、茶勺为单位显示等价容量。思考对于该程序，
 * 为何使用浮点类型比整数类型更合适？
 */

#include <stdio.h>
int main(void)
{
  float cup;

  printf("Please enter the number of cups: ");
  scanf("%f", &cup);

  printf("The equivalent volume is %f pints, %f ounces, %f tablespoons, %f teaspoons.\n",
         cup / 2, cup * 8, cup * 8 * 2, cup * 8 * 2 * 3);

  return 0;
}

/*
 * 换算存在分数，使用整数类型会导致精度丢失。
 */
