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

//day 1 a
// find smallest number of the list
Tuple_t find_s_number(sequence_t *s){
    Tuple_t tup;
    element_t * prec=NULL; //precedes the smallest number
    element_t * track=NULL; //precedes curr
    element_t *curr = s->tete;
    int smallest = curr->value;
     while (curr != NULL){
        if (curr->value < smallest){
            smallest=curr->value;
            prec=track;
        }
        track=curr;
        curr=curr->suivant;
        
    }
    tup.val=smallest;
    tup.elem=prec;
    return tup;
}

int calculate_diff (sequence_t *s1 , sequence_t *s2){
    int somme = 0;
    while(s1->tete != NULL && s2->tete !=NULL ){
        Tuple_t i=find_s_number(s1);
        Tuple_t j=find_s_number(s2);
        somme+= abs(i.val-j.val);
        remove_from_seq(s1,i.elem);
        remove_from_seq(s2,j.elem);
    }
    return somme;


}

//day 1 b
//searches freq of one particular int in the sequence
int recherche_freq_element(sequence_t *s , int n){
    int cpt=0;
    element_t *curr = s->tete;
    while (curr!= NULL){
        if (curr->value==n){
            cpt++;
        }

        curr=curr->suivant;
    }
    return cpt;
}

int similarity_score(sequence_t *s1 , sequence_t *s2){
    int score = 0;
    element_t *curr=s1->tete;
    while (curr != NULL){
        int i =recherche_freq_element(s2, curr->value);
        score+= curr->value * i;
        curr=curr->suivant;
    }
    return score;
}


int main(int argc, char *argv[]){
    FILE *f;
    f=fopen(argv[1],"r");
    int put1;
    int put2;
    sequence_t *seq=malloc(sizeof(sequence_t));
    seq->tete=NULL;
    sequence_t *seq2=malloc(sizeof(sequence_t));
    seq2->tete=NULL;

    int check=2;
    while (check==2){
        check=fscanf(f,"%d %d", &put1 ,&put2);
        if(check==2){ //for bug while inputing last number
        add_to_seq(seq,put1);
        add_to_seq(seq2,put2);
        }
    }

    int j=similarity_score(seq,seq2);
    printf("score=%d\n",j);

    int i=calculate_diff(seq,seq2);
    printf("difference=%d\n",i);

    free_sequence(seq);
    free_sequence(seq2);
    return 0;
}
