/*
 * 如何以下面的格式输出变量 words 和 lines 的值（这里，3020 和 350 代表两个变量的值）？
 * There were 3020 words and 350 lines.
 */

#include <stdio.h>
int main(void)
{
  int words, lines;
  words = 3020;
  lines = 350;

  printf("There were %d words and %d lines.\n", words, lines);

  return 0;
}
