#include <stdio.h>
#ifdef E
#error "custom error"
#endif

#ifdef LEFT
#define index(i, j) (i * 4 + j)
#endif

int main() {
  int _ = -1;
  int board[16] = {
 /* +------+------+------+------+
    |      |      |      |      | */
         _ ,    2 ,    2 ,    2 ,
 /* |      |      |      |      |
    +------+------+------+------+
    |      |      |      |      | */
         _ ,    _ ,    _ ,    _ ,
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
  /* check the feasibility of nested for loops accessing 1d array
     I want left to go
     -> -> -> -> v -> -> ...
     right
     <- <- <- <- v <- <- ...
     up v v v v -> v v ...
     down ^ ^ ^ ^ -> ^ ^ ^ ^

     so for left and right i * 4 +- j
     up and down i +- 4 * j

     this could just be a macro
     i * 4 + (3 - j)
     i * 4 + (0 + j)
     i + (3 - j) * 4
     i + (0 + j) * 4

     index(i, j)
     */
  for(int i = 0; i < 4; i++) {
    // next version
    // for 4
    // copy it into the next space
    // _ _ _ _
    // 2 _ _ _
    // _ _ 2 _
    // 2 2 2 _
    // 2 _ 2 _
    // _ 2 _ 2
    // _ _ 2 2
    int k = 0;
    for(int j = 0; j < 4; j++) {
      if(board[index(i, j)] != _) {
        if(k != j) {
          board[index(i, k)] = board[index(i, j)];
          board[index(i, j)] = _;
        }
        k++;
      }
    }
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4 - 1; j++) {
      if(board[index(i, j)] != _ && board[index(i, j)] == board[index(i, j + 1)]) {
        board[index(i, j)] *= 2;
        for(int k = j + 1; k < 4 - 1; k++) {
          board[index(i, k)] = board[index(i, k + 1)];
        }
        board[index(i, 4 - 1)] = _;
      }
    }
  }
  printf("%4d %4d %4d %4d\n", board[index(0, 0)], board[index(0, 1)], board[index(0, 2)], board[index(0, 3)]);
  printf("%4d %4d %4d %4d\n", board[index(1, 0)], board[index(1, 1)], board[index(1, 2)], board[index(1, 3)]);
  printf("%4d %4d %4d %4d\n", board[index(2, 0)], board[index(2, 1)], board[index(2, 2)], board[index(2, 3)]);
  printf("%4d %4d %4d %4d\n", board[index(3, 0)], board[index(3, 1)], board[index(3, 2)], board[index(3, 3)]);
}
