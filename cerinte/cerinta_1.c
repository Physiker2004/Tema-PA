#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void createNode (FILE *f, Node **head) {
    Node* echipa = (Node*) malloc(sizeof(Node));
    int i;

    fscanf(f, "%d ", &echipa->nr_membrii);
    fgets(echipa->nume_echipa, 50, f);
    fflush(stdin);


    for (i=0;i<echipa->nr_membrii;i++){
        fscanf(f, "%s %s %d", (echipa->jucatori[i]).nume, (echipa->jucatori[i]).prenume, &((echipa->jucatori[i]).puncte));
    }
    echipa->next=*head;
    *head = echipa;
}

void printList(FILE* f, Node *head) {
    if (head==NULL) return;
    else {
        fputs(head->nume_echipa, f);
        printList(f, head->next);
    }
}

void cerinta12(FILE* f, FILE* g, Node **head, int* nr_echipe) {
    int i;
    *head = NULL;  
    fscanf(f, "%d", nr_echipe);
    for (i=0;i<*nr_echipe;i++) createNode(f, head);
}

float punctaj(Node *n);
void printPoints (Node *head); 
Node* find_min(Node *head);
void delete (Node **head);
int power(int n, int m);
void elim(Node **head, int n);

int main(int argc, char *argv[]){
    FILE* f1_in= fopen(argv[1], "rt");
    FILE* f1_out= fopen(argv[2], "wt");
    Node* head;
    int n;
    
    cerinta12(f1_in, f1_out, &head, &n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[3], "rt");
    f1_out= fopen(argv[4], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[5], "rt");
    f1_out= fopen(argv[6], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[7], "rt");
    f1_out= fopen(argv[8], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    //printPoints(head);
    elim(&head, n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[9], "rt");
    f1_out= fopen(argv[10], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    elim(&head, n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[11], "rt");
    f1_out= fopen(argv[12], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    elim(&head, n);
    printList(f1_out, head);

    fclose(f1_in);
    fclose(f1_out);

    return 0;
}