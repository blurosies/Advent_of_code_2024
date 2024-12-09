#include <stdlib.h>
#include <stdio.h>
#include "structure.h"

// clang -c structure.c
// functions to manage linked list

// add an int to the top of the linked list
void add_to_seq(sequence_t *s , int n){
    element_t *newcell =malloc(sizeof(element_t));
    newcell->value= n;
    newcell->suivant= s->tete;
    s->tete=newcell;
}

// remove specific element from list
void remove_from_seq(sequence_t *s, element_t *prec){
    if (prec == NULL){
        element_t *temp=s->tete;
        s->tete=temp->suivant;
        free(temp);
    }else {
    element_t *curr = prec->suivant;
    prec->suivant=curr->suivant;
    free(curr);
    }
}

// for debugging purposes
void print_sequence(sequence_t *s){
    if (s->tete==NULL){
        printf("sequence is empty");
    }
    element_t*curr = s->tete;
    while (curr != NULL){
        printf("%d\n",curr->value);
        curr=curr->suivant;
    }
}

// free sequence after use
void free_sequence(sequence_t *s) {
    element_t *curr = s->tete;
    while (curr != NULL) {
        element_t *temp = curr;
        curr = curr->suivant;
        free(temp);
    }
    free(s);
}

void empty_sequence(sequence_t *s) {
    element_t *curr = s->tete;
    while (curr != NULL) {
        element_t *temp = curr;
        curr = curr->suivant;
        free(temp);
    }
    s->tete=NULL;
}