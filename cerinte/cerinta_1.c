//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

//1

//adauga date echipe in lista

void createNode (FILE *f, Node **head) {

    Node* echipa = (Node*) malloc(sizeof(Node));
    char buf[50];
    int i;
    float sum = 0.00;

    fscanf(f, "%d ", &echipa->nr_membrii);
    fgets(buf, 50, f);
    strcpy(buf+strlen(buf)-1, buf+strlen(buf));
    strcpy(echipa->nume_echipa, buf);
    fflush(stdin);


    for (i=0;i<echipa->nr_membrii;i++){
        fscanf(f, "%s %s %d", (echipa->jucatori[i]).nume, (echipa->jucatori[i]).prenume, &((echipa->jucatori[i]).puncte));
        sum+= (float) (echipa->jucatori[i]).puncte;
    }

    sum/= echipa->nr_membrii;
    echipa->punctaj=sum;

    echipa->next=*head;
    *head = echipa;
}

//afiseaza numele echipelor

void printList(FILE* f, Node *head) {
    if (head==NULL) return;
    else {
        fputs(head->nume_echipa, f);
        fprintf(f, "\n");
        printList(f, head->next);
    }
}

//creeaza lista echipelor

void cerinta12(FILE* f, FILE* g, Node **head, int *nr_echipe) {
    int i;
    *head = NULL;  
    fscanf(f, "%d", nr_echipe);
    for (i=0;i<*nr_echipe;i++) createNode(f, head);
}

int main(int argc, char *argv[]){
    int i, j, test=0, n;
    Node *head;
    BST *root;
    FILE* fc= fopen(argv[1], "rt");
    FILE* f1_in= fopen(argv[2], "rt");
    FILE* f1_out= fopen(argv[3], "wt");

    for (i=0;i<5;i++) {
        fscanf(fc, "%d", &j);
        test += j;
    }
    

    if(test == 1) {
        head=NULL;
        n=0;

        cerinta12(f1_in, f1_out, &head, &n);
        printList(f1_out, head);

        fclose(fc);
        fclose(f1_in);
        fclose(f1_out);
    }

    if(test == 2) {
        head=NULL;
        n=0;

        cerinta12(f1_in, f1_out, &head, &n);
        elim(&head, n);
        printList(f1_out, head);

        fclose(fc);
        fclose(f1_in);
        fclose(f1_out);
    }

    if(test == 3) {
        head=NULL;
        n=0;

        cerinta12(f1_in, f1_out, &head, &n);
        elim(&head, n);
        printList(f1_out, head);
        matchMaking(&head, &root, f1_out);

        fclose(fc);
        fclose(f1_in);
        fclose(f1_out);
    }

    if(test == 4) {
        head=NULL;
        root=NULL;
        n=0;

        cerinta12(f1_in, f1_out, &head, &n);
        elim(&head, n);
        printList(f1_out, head);

        matchMaking(&head, &root, f1_out);

        clasament(root, f1_out);

        fclose(fc);
        fclose(f1_in);
        fclose(f1_out);
    }

    return 0;
}