# Code Guessing 42
This is my entry for [Code Guessing round 42](https://cg.esolangs.gay/42/),
which was to implement 2048. 

I'm a big fan of quines so this entry plays 2048 by accepting a move as
by defining the respective macro when compiling the entry, and the move
is executed when the resulting binary is run. But the output is not
simply the board state but an entire copy of the original program, which
can then be recompiled again to keep playing.

There are a number of problems with the implementation, but it generally
works well enough. The main problems are that it is extremely hard to
read the board, the game over doesn't work correctly, and there is no
win condition. 
