/******************************************************************************
 * board.c:                                                                   *
 *          Creates and displays the board of the game.                       *
 *                                                                            *
 *          Inserts snake's head and food.                                    *
 *                                                                            *
 *          Functions:                                                        *
 *          board_size(), alloc_cont(), init_board(), disp_board(),           *
 *          init_snake(), insert_food(), dealloc_cont()                       *
 ******************************************************************************/

#include "retro_snake_lib.h"

/******************************************************************************
 * board_size: Returns the size of the table as a run time parameter.         *
 *             If the size is less than 3 or not set, program terminates.     *
 ******************************************************************************/
int board_size(const int argc, const int s)
{
    if (argc != 2 || s <= 3) {
        fprintf(stderr, "Size too small; program terminated.\n");
        exit(EXIT_FAILURE);
    }
    return s;
}

/******************************************************************************
 * alloc_cont: Allocates a continuous block of memory for the board.          *
 ******************************************************************************/
void alloc_cont(char *** a, const int size)
{
    int i;
    *a = (char **) malloc(ROWS * sizeof(char *) + ROWS * COLS * sizeof(char));
    if (*a == NULL) {
        fprintf(stderr, "Error: malloc failed in alloc_cont\n");
        exit(EXIT_FAILURE);
    }
    /* a[i][0] pointing to the first element of each row */
    for (i = 0; i < ROWS; i++)
        (*a)[i] = (char *) &(*a)[ROWS] + i * COLS;
}

/******************************************************************************
 * init_board: Fills the board with borders and spaces.                       *
 ******************************************************************************/
void init_board(char ** a, const int size)
{
    int i, j;
    for (i = 0; i < ROWS; i++){
        for (j = 0; j < COLS; j++){
            if (i == 0 || i == ROWS - 1) 
                *(*(a + i) + j) = '-';
            else if (j == 0 || j == COLS - 1)
                *(*(a + i) + j) = '|';
            else
                *(*(a + i) + j) = ' ';
        }
    }
    a[0][0] = ' ';
    a[0][COLS - 1] = ' ';
    a[ROWS - 1][0] = ' ';
    a[ROWS - 1][COLS - 1] = ' ';
}


/******************************************************************************
 * disp_board: Prints the board.                                              *
 ******************************************************************************/
void disp_board(char ** a, const int size)
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%c", *(*(a + i) + j));
        printf("\n");
    }
    printf("\n");
}

/******************************************************************************
 * init_snake: Randomly places the head of the snake                          *
 *             and returns its position.                                      *
 ******************************************************************************/
char * init_snake(char **a, const int size)
{
    int x = 1 + rand() % (ROWS - 2);
    int y = 1 + rand() % (COLS - 2);

    *(*(a + x) + y) = '@';

    return &a[x][y];
}

/******************************************************************************
 * insert_food: Inserts 'X' (food) to a random location.                      *
 *              Returns the position of 'X'.                                  *
 *              If max score is reached, win variable is set to 1 (true)      *
 *              initiating the end of game.                                   *
 ******************************************************************************/
char * insert_food(char ** a, const int size, int * score, int * win)
{
    int x = 1;
    int y = 0;
    
    if ((*score + SCORE_OFFSET) != MAX_SCORE) {
        while(a[x][y] != ' ') {
            x = 1 + rand() % (ROWS - 2);
            y = 1 + rand() % (COLS - 2);
        }
        *score = *score + SCORE_OFFSET;
        a[x][y] = 'X';

        return &a[x][y];
    }
    else {
        *win = 1;    /* If game is over, flag win turns true (1) */
    }
    return NULL;
}

/******************************************************************************
 * dealloc_cont: Releases the memory allocated for the board                  *
 ******************************************************************************/
void dealloc_cont(char ** a)
{
    free(a);
}