/******************************************************************************
 * retro_snake.c:                                                             *
 *                Executable code.                                            *
 *                                                                            *
 *                Calls all the necessary functions that run the game.        *
 ******************************************************************************/

#include "retro_snake_lib.h"

int main(int argc, char ** argv)
{
    int size, win = 0, score = -SCORE_OFFSET;
    char ** b = NULL;
    char * food = NULL;
    node_t *snake = NULL;

    size = board_size(argc, atoi(argv[1]));
    srand((unsigned int) time(NULL));     /* Generate pool of random numbers */
    alloc_cont(&b, size);
    init_board(b, size);
    add_to_list(&snake, init_snake(b, size));
    food = insert_food(b, size, &score, &win);

    while(!win) {
        play_game(b, size, &snake, food, &score, &win);
    }
    disp_board(b, size);
    win_sxs(b, &snake, &score);

    return 0;
}