/******************************************************************************
 * movement.h:                                                                *
 *             Contains nessessary function prototypes to moving the snake.   *
 ******************************************************************************/

#ifndef MOVEMENT
#define MOVEMENT

/******************************************************************************
 * move: Moves snake by calling up(), down(), right(), left()                 *
 *       or terminates the program if wrong input is given.                   *
 ******************************************************************************/
void move(char ** a, int size, node_t ** list, char * food, char go,
        int * score, int *win);

/******************************************************************************
 * up: Moves the snake up.                                                    *
 ******************************************************************************/
void up(char ** a, const int size, node_t ** list, char * food, int * score,
        int *win);

/******************************************************************************
 * down: Moves the snake down.                                                *
 ******************************************************************************/
void down(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win);

/******************************************************************************
 * right: Moves the snake right.                                              *
 ******************************************************************************/
void right(char ** a, const int size, node_t ** list, char * food, int * score,
        int *win);

/******************************************************************************
 * left: Moves the snake up.                                                  *
 ******************************************************************************/
void left(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win);

#endif