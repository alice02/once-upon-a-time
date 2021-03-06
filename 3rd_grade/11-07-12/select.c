/*●●● 必要なヘッダファイルを含める ●●●*/
#include <stdlib.h>

struct data
{
  char  *cp_dat;
  int   i_num;
};

void my_select(struct data ref,
	       struct data *set)
{
  int  i;
  int  i_length;
  int  i_rand;

  i_length = ref.i_num;  /*●●● 右辺 ●●●*/

  for (i = 0;  i < ref.i_num;  i++)
  {
    i_rand = rand() % i_length;  /*●●● 右辺 ●●●*/
    set->cp_dat[i] = ref.cp_dat[i_rand];  /*●●● 右辺 ●●●*/

    /*●●● 選択した文字を最後の文字でつぶす ●●●*/
        ref.cp_dat[i_rand] = ref.cp_dat[i_length-1];
    /*●●● 選択可能な範囲を縮める ●●●*/
    i_length--;
  }
}
