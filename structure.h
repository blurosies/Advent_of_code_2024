#include <stdlib.h>
#include <stdio.h>

// defining structures
typedef struct element {
    int   value;
    struct element *suivant;
}element_t;

typedef struct sequence {
    element_t*tete;
}sequence_t;

typedef struct Tuple {
    int val;
    element_t *elem;
}Tuple_t;

void add_to_seq(sequence_t *s , int n);

void remove_from_seq(sequence_t *s, element_t *prec);

void print_sequence(sequence_t *s);

void free_sequence(sequence_t *s);

void empty_sequence(sequence_t *s);


