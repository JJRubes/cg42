#define _ -1
int board[16] = {
 /* +------+------+------+------+
    |      |      |      |      | */
         _ ,    2 ,    2 ,    2 ,
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
         _ ,    2 ,    _ ,    _ ,
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
         _ ,    2 ,    _ ,    2 ,
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
         _ ,    _ ,    4 ,    2 ,
 /* |      |      |      |      |
    +------+------+------+------+ */
};

#include <stdio.h>
#include <stdlib.h>
#ifdef E
#error "custom error"
#endif

#ifdef LEFT
#define val(i, j) board[i * 4 + (0 + j)]
#endif
#ifdef RIGHT
#define val(i, j) board[i * 4 + (3 - j)]
#endif
#ifdef DOWN
#define val(i, j) board[i + (3 - j) * 4]
#endif
#ifdef UP
#define val(i, j) board[i + (0 + j) * 4]
#endif

int gameOver() {
  for(int i = 0; i < 4; i++) {
    int prevRow = _;
    int prevCol = _;
    for(int j = 0; j < 4; j++) {
      if(val(i, j) == _ || val(i, j) == prevRow)
        return 0;
      prevRow = val(i, j);
      if(val(j, i) == _ || val(j, i) == prevCol)
        return 0;
      prevCol = val(j, j);
    }
  }
  return 1;
}

void addRandom() {
  while(1) {
    int index = rand() % 16;
    if(board[index] == _) {
      board[index] = rand() % 100 < 90 ? 2 : 4;
      return;
    }
  }
}

int move() {
  int changed = 0;
  for(int i = 0; i < 4; i++) {
    int k = 0;
    for(int j = 1; j < 4; j++) {
      if(val(i, j) == _) continue;
      if (val(i, k) == _) {
        val(i, k) = val(i, j);
        val(i, j) = _;
        changed = 1;
      } else if (val(i, k) == val(i, j)) {
        val(i, k) += val(i, j);
        val(i, j) = _;
        k++;
        changed = 1;
      } else {
        k++;
        val(i, k) = val(i, j);
        if(k != j) {
          val(i, j) = _;
        }
      }
    }
  }
  return changed;
}

int main() {
  printf("%4d %4d %4d %4d\n", board[0], board[1], board[2], board[3]);
  printf("%4d %4d %4d %4d\n", board[4], board[5], board[6], board[7]);
  printf("%4d %4d %4d %4d\n", board[8], board[9], board[10], board[11]);
  printf("%4d %4d %4d %4d\n", board[12], board[13], board[14], board[15]);
  printf("\n");

#include <time.h>
  srand(time(NULL));
  if(move())
    addRandom();

  printf("%4d %4d %4d %4d\n", board[0], board[1], board[2], board[3]);
  printf("%4d %4d %4d %4d\n", board[4], board[5], board[6], board[7]);
  printf("%4d %4d %4d %4d\n", board[8], board[9], board[10], board[11]);
  printf("%4d %4d %4d %4d\n", board[12], board[13], board[14], board[15]);

  if(gameOver()) {
    puts("game over");
  }
}
