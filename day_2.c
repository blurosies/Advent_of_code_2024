#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structure.h"

// clang day_2.c structure.o -o day_2

int is_safe(sequence_t *s){
    if (s->tete==NULL)
        return 0;
    element_t *curr = s->tete;
    if (s->tete->value > s->tete->suivant->value){
        while (curr->suivant != NULL){
            int val = curr->value;
            int s_val= curr->suivant->value; //trying to shorten long bool expression lol
            if (val < s_val || val-s_val > 3 || val-s_val < 1)
                return 0;
            curr=curr->suivant;}
    }else {
        while (curr->suivant != NULL){
            int val = curr->value;
            int s_val= curr->suivant->value;
            if (val > s_val || s_val-val > 3 || s_val-val < 1)
                return 0;
            curr=curr->suivant;}
    }
    return 1;
}

int main(int argc, char *argv[]){
    FILE *f;
    f=fopen(argv[1],"r");
    char line[256];
    char temp[10];
    int j=0;
    int cpt=0; // safe sequence counter

    sequence_t *seq=malloc(sizeof(sequence_t));
    seq->tete=NULL;
    char c=fgetc(f);

    while (c!=EOF)
    {
        if(c=='\n'){
            temp[j]='\0';
            add_to_seq(seq,atoi(temp));
            if (is_safe(seq))
                cpt++;
            empty_sequence(seq);
            temp[1]='\0';
            j=0;
        }
        else if(c==' '){
            temp[j]='\0';
            add_to_seq(seq,atoi(temp));
            temp[1]='\0';
            j=0;
        }
        else{
            temp[j]=c;
            j++;
        }
        c=fgetc(f);
    }
    if (is_safe(seq))
        cpt++;

        
    printf("cpt=%d\n",cpt);
    fclose(f);
    free_sequence(seq);
}