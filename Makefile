NO_MOVE:
	@echo "use make <direction> to move the board in that direction"
	@echo "or make NEW_GAME to start a new game"

left: LEFT
LEFT:
	@gcc 2048.c -o 2048 -D LEFT -w
	@./2048 > 2048.c
	@head -n 19 2048.c | tail -n 17

right: RIGHT
RIGHT:
	@gcc 2048.c -o 2048 -D RIGHT -w
	@./2048 > 2048.c
	@head -n 19 2048.c | tail -n 17

up: UP
UP:
	@gcc 2048.c -o 2048 -D UP -w
	@./2048 > 2048.c
	@head -n 19 2048.c | tail -n 17

down: DOWN
DOWN:
	@gcc 2048.c -o 2048 -D DOWN -w
	@./2048 > 2048.c
	@head -n 19 2048.c | tail -n 17

new_game: NEW_GAME
NEW_GAME:
	@gcc 2048.c -o 2048 -D NEW_GAME -w
	@./2048 > 2048.c
	@head -n 19 2048.c | tail -n 17
