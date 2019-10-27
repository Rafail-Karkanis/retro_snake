/******************************************************************************
 * list.h:                                                                    *
 *         Contains nessessary type definition of the node                    *
 *         and all the function prototypes regarding the list (snake).        *
 ******************************************************************************/

#ifndef LIST
#define LIST

/******************************************************************************
 * node_t: The list. It is comprised of a pointer to an element of the board, *
 *         a pointer to the next node, and a pointer to the previous node.    *
 ******************************************************************************/
typedef struct node
{
    char * val;
    struct node * next;
    struct node * prev;
} node_t;


/******************************************************************************
 * add_to_list: Creates and inserts nodes to the list.                        *
 *              Contains pointer to the next and previous node.               *
 *              Returns whether memory allocation is successful or not.       *
 ******************************************************************************/
int add_to_list(node_t ** list, char * c);

/******************************************************************************
 * move_tail: Prepares the movement of the snake.                             *
 *            It turns the head from '@' to '*'.                              *
 *            Then it either changes the last part of the tail to ' '         *
 *            or to '@' if the move concludes at the very end of the tail,    *
 *            like a dog chasing its tail .                                   *
 ******************************************************************************/
void move_tail(node_t ** list, const int head_to_tail);

/******************************************************************************
 * end_of_tail: Returns whether or not a given point                          *
 *              concurs with the end of the tail                              *
 ******************************************************************************/
int end_of_tail(node_t ** list, const char * pos);

/******************************************************************************
 * first_tail: Returns whether or not a given point                           *
 *             is the first node of the snake's tail.                         *
 ******************************************************************************/
int first_tail(node_t ** list, const char * pos);

/******************************************************************************
 * expand_tail: Inserts new node to the tail.                                 *
 *              Returns whether memory allocation is successful or not.       *
 ******************************************************************************/
int expand_tail(node_t ** list);

/******************************************************************************
 * dealloc_list: Releases the memory allocated to the list (snake).           *
 ******************************************************************************/
void dealloc_list(node_t ** list);

#endif