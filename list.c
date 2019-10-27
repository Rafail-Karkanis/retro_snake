/******************************************************************************
 * list.c:                                                                    *
 *         Creates and manipulates the snake.                                 *
 *                                                                            *
 *         Functions:                                                         *
 *         add_to_list(), move_tail(), end_of_tail(), first_tail(),           *
 *         expand_tail(), dealloc_list()                                      *
 ******************************************************************************/

#include "retro_snake_lib.h"

/******************************************************************************
 * add_to_list: Creates and inserts nodes to the list.                        *
 *              Contains pointer to the next and previous node.               *
 *              Returns whether memory allocation is successful or not.       *
 ******************************************************************************/
int add_to_list(node_t ** list, char * c) 
{ 
    node_t * new_node;
    node_t * last;

    new_node = (node_t *) malloc(sizeof(node_t)); 

    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed in add_to_list\n");
        return 0;
    }

    last = *list;

    new_node->val = c;

    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
        new_node->prev = new_node;
    }   
    else {
        while (last->next != NULL) {
            new_node->prev = last;
            last = last->next;
        }
        new_node->prev = last;
        last->next = new_node;
    }
    return 1;
}

/******************************************************************************
 * move_tail: Prepares the movement of the snake.                             *
 *            It turns the head from '@' to '*'.                              *
 *            Then it either changes the last part of the tail to ' '         *
 *            or to '@' if the move concludes at the very end of the tail,    *
 *            like a dog chasing its tail .                                   *
 ******************************************************************************/
void move_tail(node_t ** list, const int head_to_tail)
{
    node_t *last;
    last = *list;


    *((*list)->val) = '*';

    while (last->next != NULL)
        last = last->next;

    if (head_to_tail)
        *(last->val) = '@';
    else
        *(last->val) = ' ';

    while (last != *list) {
        last->val = last->prev->val;
        last = last->prev;
    }
    last->val = last->prev->val;
}

/******************************************************************************
 * end_of_tail: Returns whether or not a given point                          *
 *              concurs with the end of the tail                              *
 ******************************************************************************/
int end_of_tail(node_t ** list, const char * pos)
{
    node_t *last;
    last = *list;

    while(last->next != NULL)
        last = last->next;

    if (last->val == pos)
        return 1;
    return 0;
}

/******************************************************************************
 * first_tail: Returns whether or not a given point                           *
 *             is the first node of the snake's tail.                         *
 ******************************************************************************/
int first_tail(node_t ** list, const char * pos)
{

    if (pos == (*list)->next->val)
        return 1;
    return 0;
}

/******************************************************************************
 * expand_tail: Inserts new node to the tail.                                 *
 *              Returns whether memory allocation is successful or not.       *
 ******************************************************************************/
int expand_tail(node_t ** list)
{
    node_t *last;
    last = *list;

    *((*list)->val) = '*';

    while (last->next != NULL)
        last = last->next;

    /* Checking whether add_to_list was successful in allocating memory. */
    if(add_to_list(list, last->val))
        ;
    else
        return 0;
    last = last->next;

    *(last->val) = '*';

    while (last != *list) {
        last->val = last->prev->val;
        last = last->prev;
    }
    last->val = last->prev->val;

    return 1;
}

/******************************************************************************
 * dealloc_list: Releases the memory allocated to the list (snake).           *
 ******************************************************************************/
void dealloc_list(node_t ** list)
{
    node_t * temp;

    while (*list != NULL) {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}