/******************************************************************************
 * board.h:                                                                   *
 *          Contains nessessary define directives and function prototypes     *
 *          regarding the grid of the game                                    *
 *          and the initialization of the snake.                              *
 ******************************************************************************/

#ifndef BOARD
#define BOARD

#define ROWS (size)        /* Board's width */
#define COLS (2 * size)    /* Board's length is double its width */

/******************************************************************************
 * board_size: Returns the size of the table as a run time parameter.         *
 *             If the size is less than 3 or not set, program terminates.     *
 ******************************************************************************/
int board_size(const int argc, const int s);

/******************************************************************************
 * alloc_cont: Allocates a continuous block of memory for the board.          *
 ******************************************************************************/
void alloc_cont(char *** a, const int size);

/******************************************************************************
 * init_board: Fills the board with borders and spaces.                       *
 ******************************************************************************/
void init_board(char ** a, const int size);

/******************************************************************************
 * disp_board: Prints the board.                                              *
 ******************************************************************************/
void disp_board(char ** a, const int size);

/******************************************************************************
 * init_snake: Randomly places the head of the snake                          *
 *             and returns its position.                                      *
 ******************************************************************************/
char * init_snake(char ** a, const int size);

/******************************************************************************
 * insert_food: Inserts 'X' (food) to a random location.                      *
 *              Returns the position of 'X'.                                  *
 *              If max score is reached, win variable is set to 1 (true)      *
 *              initiating the end of game.                                   *
 ******************************************************************************/
char * insert_food(char ** a, const int size, int * score, int * win);

/******************************************************************************
 * dealloc_cont: Releases the memory allocated for the board                  *
 ******************************************************************************/
void dealloc_cont(char ** a);

#endif