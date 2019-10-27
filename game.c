/******************************************************************************
 * game.c:                                                                    *
 *         Starts the game, ends it, and inserts the food ('X').              *
 *                                                                            *
 *         Functions:                                                         *
 *         play_game(), lose(), win_sxs(), wrong_input()                      *
 ******************************************************************************/

#include "retro_snake_lib.h"

/******************************************************************************
 * play_game: Prints score, reads direction input                             *
 *            and calls move() to move snake.                                 *
 ******************************************************************************/
void play_game(char ** a, const int size, node_t ** list, char * food,
            int * score, int * win)
{
    char go;

    printf("\nSCORE: %d\n", *score);
    disp_board(a, size);
    printf("\nGo: ");
    scanf("%c", &go);
    move(a, size, list, food, go, score, win);
    scanf("%c", &go); /* remove \n from buffer */
}

/******************************************************************************
 * lose: Calls dealloc_cont() and dealloc_list()                              *
 *       to release the memory allocated and exits.                           *
 ******************************************************************************/
void lose(char ** a, node_t ** list)
{
    dealloc_cont(a);
    dealloc_list(list);
    exit(EXIT_SUCCESS);
}


/******************************************************************************
 * win_sxs: Prints winning message, score                                     *
 *           and calls dealloc_cont() and dealloc_list()                      *
 *           to release the memory allocated.                                 *
 *           Exits.                                                           *
 ******************************************************************************/
void win_sxs(char ** a, node_t ** list, const int * score)
{
    printf("\n>>>>>!YOU WON!<<<<<\n\n");
    printf("EPIC SCORE: %d\n", *score + SCORE_OFFSET);
    dealloc_cont(a);
    dealloc_list(list);
    exit(EXIT_SUCCESS);
}

/******************************************************************************
 * wrong_input: Terminates the program if wrong input is given.               *
 ******************************************************************************/
void wrong_input(char ** a, node_t ** list)
{
    fprintf(stderr, "Wrong input. Only w, s, d, a. Start over!\n");
    lose(a, list);
}