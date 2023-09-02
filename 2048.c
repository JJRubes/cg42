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

// val(i, j) -> board[index(i, j)]
#ifdef LEFT
// #define index(i, j) (i * 4 + (0 + j))
#define val(i, j) board[i * 4 + (0 + j)]
#endif
#ifdef RIGHT
// #define index(i, j) (i * 4 + (3 - j))
#define val(i, j) board[i * 4 + (3 - j)]
#endif
#ifdef DOWN
// #define index(i, j) (i + (3 - j) * 4)
#define val(i, j) board[i + (3 - j) * 4]
#endif
#ifdef UP
// #define index(i, j) (i + (0 + j) * 4)
#define val(i, j) board[i + (0 + j) * 4]
#endif

int gameOver() {
  for(int i = 0; i < 4; i++) {
    int prevRow = _;
    int prevCol = _;
    for(int j = 0; j < 4; j++) {
      if(val(i, j) != _ && val(i, j) == prevRow)
        return 0;
      prevRow = val(i, j);
      if(val(j, i) != _ && val(j, i) == prevCol)
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

int main() {
  printf("%4d %4d %4d %4d\n", board[0], board[1], board[2], board[3]);
  printf("%4d %4d %4d %4d\n", board[4], board[5], board[6], board[7]);
  printf("%4d %4d %4d %4d\n", board[8], board[9], board[10], board[11]);
  printf("%4d %4d %4d %4d\n", board[12], board[13], board[14], board[15]);
  printf("\n");

  // shifting over number
  // for(int i = 0; i < 4; i++) {
  //   int k = 0;
  //   for(int j = 0; j < 4; j++) {
  //     if(board[index(i, j)] != _) {
  //       if(k != j) {
  //         board[index(i, k)] = board[index(i, j)];
  //         board[index(i, j)] = _;
  //       }
  //       k++;
  //     }
  //   }
  // }

  // for(int i = 0; i < 4; i++) {
  //   for(int j = 0; j < 4 - 1; j++) {
  //     if(board[index(i, j)] != _ && board[index(i, j)] == board[index(i, j + 1)]) {
  //       board[index(i, j)] *= 2;
  //       for(int k = j + 1; k < 4 - 1; k++) {
  //         board[index(i, k)] = board[index(i, k + 1)];
  //       }
  //       board[index(i, 4 - 1)] = _;
  //     }
  //   }
  // }

  /* have 2 indices (per row/col)
     _ _ _ _  -->  _ _ _ _
     a b           a   b
     if a == _ and b == _

     _ _ 2 _  -->  2 _ _ _
     a   b         a     b
     if a == _ and b != b, a = b, b = _

     2 _ 2 _  -->  2 _ 2 _
     a b           a   b
     if a != _ and b == _, inc b

     2 _ 2 _  -->  4 _ _ _
     a   b           a   b
     2 _ 4 _  -->  2 4 _ _
     a   b           a   b
     if a != _ and b != _


     _ 2 2 2
     k j
     2 _ 2 2
     k   j
     4 _ _ 2
       k   j
     4 2 _ _
       k     j


     _ _ 4 2
     k j
     _ _ 4 2
     k   j
     4 _ _ 2
     k     j
     4 2 _ _
       k     j

     2 4 _ _
     k j
     2 4 _ _
       k j
     2 4 _ _
       k   j
     2 4 _ _
       k     j
     */
  // for each row/col
  for(int i = 0; i < 4; i++) {
    int k = 0;
    for(int j = 1; j < 4; j++) {
      if(val(i, j) == _) continue;
      if (val(i, k) == _) {
        val(i, k) = val(i, j);
        val(i, j) = _;
      } else if (val(i, k) == val(i, j)) {
        val(i, k) += val(i, j);
        val(i, j) = _;
        k++;
      } else {
        k++;
        val(i, k) = val(i, j);
        if(k != j) {
          val(i, j) = _;
        }
      }
    }
  }
  /*

     2 2 4 4
     a b
     4 _ 4 4
       a b
     4 4 _ 4
       a   b
     4 8 _ _
       a     b

     2 _ 4 _
     a b
     2 _ 4 _
     a   b
     (2 _ 4 _, 2 4 _ _)
        a b      a   b

     */
  printf("%4d %4d %4d %4d\n", board[0], board[1], board[2], board[3]);
  printf("%4d %4d %4d %4d\n", board[4], board[5], board[6], board[7]);
  printf("%4d %4d %4d %4d\n", board[8], board[9], board[10], board[11]);
  printf("%4d %4d %4d %4d\n", board[12], board[13], board[14], board[15]);
  // printf("%4d %4d %4d %4d\n", board[index(0, 0)], board[index(0, 1)], board[index(0, 2)], board[index(0, 3)]);
  // printf("%4d %4d %4d %4d\n", board[index(1, 0)], board[index(1, 1)], board[index(1, 2)], board[index(1, 3)]);
  // printf("%4d %4d %4d %4d\n", board[index(2, 0)], board[index(2, 1)], board[index(2, 2)], board[index(2, 3)]);
  // printf("%4d %4d %4d %4d\n", board[index(3, 0)], board[index(3, 1)], board[index(3, 2)], board[index(3, 3)]);

  /* for each direction if there is a double */
}
