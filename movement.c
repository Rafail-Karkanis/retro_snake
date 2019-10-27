/******************************************************************************
 * movement.c:                                                                *
 *             Moves the snake.                                               *
 *                                                                            *
 *             Functions:                                                     *
 *             move(), up(), down(), right(), left()                          *
 ******************************************************************************/

#include "retro_snake_lib.h"

/******************************************************************************
 * move: Moves snake by calling up(), down(), right(), left()                 *
 *      or terminates the program if wrong input is given.                    *
 ******************************************************************************/
void move(char ** a, const int size, node_t ** list, char * food, char go,
        int * score, int * win)
{
    switch(go)
    {
        case 'w':
            up(a, size, list, food, score, win);
            break;
        case 's':
            down(a, size, list, food, score, win);
            break;
        case 'a':
            left(a, size, list, food, score, win);
            break;
        case 'd':
            right(a, size, list, food, score, win);
            break;
        default:
            wrong_input(a, list);
    }
}

/******************************************************************************
 * up: Moves the snake up.                                                    *
 ******************************************************************************/
void up(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win)
{
    /* Checking if direction is opposite: no movement occurs. */
    if (*((*list)->val - COLS) == '*'
         && first_tail(list, (*list)->val - COLS)) 
    {
        ;
    }
    /* 
     * If the next point of the board is the last node of the tail, 
     * movement is possible.
     */
    else if (*((*list)->val - COLS) == ' ' 
            || end_of_tail(list, (*list)->val - COLS))
    {
        *((*list)->val - COLS) = '@';
        move_tail(list, end_of_tail(list, (*list)->val - COLS));
        (*list)->val = (*list)->val - COLS;
    }
    /* Expanding tail if food ('X') is eaten */
    else if (*((*list)->val - COLS) == 'X') {
        *((*list)->val - COLS) = '@';
        if(expand_tail(list))
            ;
        else {
            dealloc_list(list);
            dealloc_cont(a);
            exit(EXIT_FAILURE);
        }
        (*list)->val = (*list)->val - COLS;
        food = insert_food(a, size, score, win);
    }
    /* Landing on its tail '*', border '-', '|', ends the game */
    else {
        printf("\nYou went up to your grave.\n");
        lose(a, list);
    }
}

/******************************************************************************
 * down: Moves the snake down.                                                *
 ******************************************************************************/
void down(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win)
{
    /* Checking if direction is opposite: no movement occurs. */
    if (*((*list)->val + COLS) == '*'
         && first_tail(list, (*list)->val + COLS))
    {
        ;
    }
    /* 
     * If the next point of the board is the last node of the tail, 
     * movement is possible.
     */
    else if (*((*list)->val + COLS) == ' '
             || end_of_tail(list, (*list)->val + COLS))
    {
        *((*list)->val + COLS) = '@';
        move_tail(list, end_of_tail(list, (*list)->val + COLS));
        (*list)->val = (*list)->val + COLS;
    }
    /* Expanding tail if food ('X') is eaten */
    else if (*((*list)->val + COLS) == 'X') {
        *((*list)->val + COLS) = '@';
        if(expand_tail(list))
            ;
        else {
            dealloc_list(list);
            dealloc_cont(a);
            exit(EXIT_FAILURE);
        }
        (*list)->val = (*list)->val + COLS;
        food = insert_food(a, size, score, win);
    }
    /* Landing on its tail '*', border '-', '|', ends the game */
    else {
        printf("\nYou went down to your grave.\n");
        lose(a, list);
    }
}


/******************************************************************************
 * right: Moves the snake right.                                              *
 ******************************************************************************/
void right(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win)
{
    /* Checking if direction is opposite: no movement occurs. */
    if (*((*list)->val + 1) == '*' && first_tail(list, (*list)->val + 1)) {
        ;
    }
    /* 
     * If the next point of the board is the last node of the tail, 
     * movement is possible.
     */
    else if (*((*list)->val + 1) == ' '
             || end_of_tail(list,(*list)->val + 1))
    {
        *((*list)->val + 1) = '@';
        move_tail(list, end_of_tail(list,(*list)->val + 1));
        (*list)->val = (*list)->val + 1;
    }
    /* Expanding tail if food ('X') is eaten */
    else if (*((*list)->val + 1) == 'X') {
        *((*list)->val + 1) = '@';
        if(expand_tail(list))
            ;
        else {
            dealloc_list(list);
            dealloc_cont(a);
            exit(EXIT_FAILURE);
        }
        (*list)->val = (*list)->val + 1;
        food = insert_food(a, size, score, win);
    }
    /* Landing on its tail '*', border '-', '|', ends the game */
    else {
        printf("\nYou went right to your grave.\n");
        lose(a, list);
    }
}

/******************************************************************************
 * left: Moves the snake up.                                                  *
 ******************************************************************************/
void left(char ** a, const int size, node_t ** list, char * food, int * score,
        int * win)
{
    /* Checking if direction is opposite: no movement occurs. */
    if (*((*list)->val - 1) == '*'
         && first_tail(list, (*list)->val - 1))
    {
        ;
    }
    /* 
     * If the next point of the board is the last node of the tail, 
     * movement is possible.
     */
    else if (*((*list)->val - 1) == ' '
             || end_of_tail(list,(*list)->val - 1))
    {
        *((*list)->val - 1) = '@';
        move_tail(list, end_of_tail(list,(*list)->val - 1));
        (*list)->val = (*list)->val - 1;
    }
    /* Expanding tail if food ('X') is eaten */
    else if (*((*list)->val - 1) == 'X') {
        *((*list)->val - 1) = '@';
        if(expand_tail(list))
            ;
        else {
            dealloc_list(list);
            dealloc_cont(a);
            exit(EXIT_FAILURE);
        }
        (*list)->val = (*list)->val - 1;
        food = insert_food(a, size, score, win);
    }
    /* Landing on its tail '*', border '-', '|', ends the game */
    else {
        printf("\nYou went left to your grave.\n");
        lose(a, list);
    }
}