/******************************************************************************
 * game.h:                                                                    *
 *         Contains nessessary define directives                              *
 *         and the function prototypes regarding the game.                    *
 *         i.e. Playing, losing, winning, wrong input                         *
 ******************************************************************************/

#ifndef GAME
#define GAME

/* The maximum possible score */
#define MAX_SCORE (((ROWS - 2) * (COLS - 2)) * 10 - 10)
#define SCORE_OFFSET (10)    /* An offset that assists with calculations */

/******************************************************************************
 * play_game: Prints score, reads direction input                             *
 *            and calls move() to move snake.                                 *
 ******************************************************************************/
void play_game(char ** a, const int size, node_t ** list, char * food,
                int * score, int * win);

/******************************************************************************
 * lose: Calls dealloc_cont() and dealloc_list()                              *
 *       to release the memory allocated and exits.                           *
 ******************************************************************************/
void lose(char ** a, node_t ** list);

/******************************************************************************
 * win_sxs: Prints winning message, score                                     *
 *           and calls dealloc_cont() and dealloc_list()                      *
 *           to release the memory allocated.                                 *
 *           Exits.                                                           *
 ******************************************************************************/
void win_sxs(char ** a, node_t ** list, const int * score);

/******************************************************************************
 * wrong_input: Terminates the program if wrong input is given.               *
 ******************************************************************************/
void wrong_input(char ** a, node_t ** list);

#endif