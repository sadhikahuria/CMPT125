#include <stdio.h>

//linked list structure
typedef struct element
{
    int val;
    element_t *next;
} element_t;

typedef struct list {
    element_t *head;
    element_t *tail;
    unsigned int elementcount;
} list_t;// DHSL list

//prepend
//inserting at the front

/*
int prepend(int newval){
    element_t *newnode = malloc(sizeof(element_t));
    if (newnode != NULL){
        newnode -> val = newval;
        newnode -> next = head;
        head = newnode;
        elementcount++;


    }
}
*/

// how much time does this take 
// 6 operations

//traverse

/*
anchor head of linked list
if (head != NULL){
    element_t *current = head;
    while (current -> next != NULL){
        current = current -> next;

    }
}
*/

/*
int append (int newval){
    element_t *newnode = malloc(sizeof(element_t));
    if( newnode != NULL){
        newnode -> val = newval;
        newnode -> next = NULL;
        if (head == NULL){
            head = newnode;

        } 
        else {
            element_t *current = head;
            while( current -> next != NULL){
                current = current -> next;

            }
            curent -> next = newnode;
            elementcount ++;

        }
    }
}
*/


/*
void removeatfront(){
    if (head != NULL){
        element_t *nodetoremove = head;
        head = head -> next;

        nodetoremove -> next = NULL;
        free(nodetoremove);
        nodetoremove = NULL;
        elementcount--;

    }
}
*/



