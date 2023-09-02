NO_MOVE:
	@echo "use make <direction> to move the board in that direction"
	@echo "or make NEW_GAME to start a new game"

left: LEFT
LEFT:
	gcc 2048.c -o 2048 -Wall -D LEFT

right: RIGHT
RIGHT:
	gcc 2048.c -o 2048 -Wall -D RIGHT

up: UP
UP:
	gcc 2048.c -o 2048 -Wall -D UP

down: DOWN
DOWN:
	gcc 2048.c -o 2048 -Wall -D DOWN
