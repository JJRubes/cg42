#include <stdio.h>
#ifdef E
#error "custom error"
#endif

void p(int board[4][4]) {
  printf("%4d %4d %4d %4d\n", board[0][0], board[0][1], board[0][2], board[0][3]);
  printf("%4d %4d %4d %4d\n", board[1][0], board[1][1], board[1][2], board[1][3]);
  printf("%4d %4d %4d %4d\n", board[2][0], board[2][1], board[2][2], board[2][3]);
  printf("%4d %4d %4d %4d\n\n", board[3][0], board[3][1], board[3][2], board[3][3]);
}

int main() {
  int _ = -1;
  int board[4][4] = {
 /* +------+------+------+------+
    |      |      |      |      | */
    {    2 ,    2 ,    2 ,    2 },
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
    {    _ ,    _ ,    _ ,    _ },
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
    {    _ ,    _ ,    _ ,    _ },
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
    {    _ ,    _ ,    _ ,    _ },
 /* |      |      |      |      |
    +------+------+------+------+ */
  };
  for(int i = 0; i < 4; i++) {
    int j;
    for(j = 0; j < 4; j++) {
      if(board[i][j] != _) {
        break;
      }
    }
    if(j < 4 && j > 0) {
      for(int k = 0; k < 4 - j; k++) {
        board[i][k] = board[i][k + j];
        board[i][k + j] = _;
      }
    }
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4 - 1; j++) {
      if(board[i][j] != _ && board[i][j] == board[i][j + 1]) {
        board[i][j] *= 2;
        for(int k = j + 1; k < 4 - 1; k++) {
          board[i][k] = board[i][k + 1];
        }
        board[i][4 - 1] = _;
      }
    }
  }
  printf("%4d %4d %4d %4d\n", board[0][0], board[0][1], board[0][2], board[0][3]);
  printf("%4d %4d %4d %4d\n", board[1][0], board[1][1], board[1][2], board[1][3]);
  printf("%4d %4d %4d %4d\n", board[2][0], board[2][1], board[2][2], board[2][3]);
  printf("%4d %4d %4d %4d\n", board[3][0], board[3][1], board[3][2], board[3][3]);
}
