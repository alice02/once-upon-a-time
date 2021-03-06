#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long  ELEM;

#define QUEUE_SIZE 5   /*●●● 定義 ●●●*/
#define next(a) (((a) + 1) % QUEUE_SIZE)   /*●●● 定義 ●●●*/


void error(char *s)
{
  /*●●● 処理 ●●●*/
  fprintf(stderr, s);
}

void init(int *front,
	  int *rear)
{
  /*●●● 処理 ●●●*/
  *front = *rear = 0;
}

void enqueue(ELEM  queue[],
	     int  front,
	     int  *rear,
	     ELEM  x)
{
  if (next(*rear) == front)  /*●●● 分岐条件 ●●●*/
  {
    error("待ち行列がフルなので要素を入れられません\n");
  }
  else
  {
    /*●●● 処理 ●●●*/
    queue[*rear] = x;
    *rear = next(*rear);
  }
}

int dequeue(ELEM  queue[],
	    int  *front,
	    int  rear,
	    ELEM *x)
{
  int  i_ret = 0;

  if (*front == rear)  /*●●● 分岐条件 ●●●*/
  {
    error("待ち行列が空なので要素を取り出せません\n");
    i_ret = 1;   /*●●● 右辺 ●●●*/
  }
  else
  {
    /*●●● 処理 ●●●*/
    *x = queue[*front];
    *front = next(*front);
    i_ret = 0;
  }

  return i_ret;  /*●●● 戻り値 ●●●*/
}

int  empty(int  front,
	   int  rear)
{
  return front == rear;
}
