#include <stdio.h>
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
    //fscanf(f, "%s\n", echipa->nume_echipa);
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
        /*puts(head->nume_echipa);
        printf("%f\n", head->punctaj);
        printf("-------\n");*/
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
    FILE* f1_in= fopen(argv[1], "rt");
    FILE* f1_out= fopen(argv[2], "wt");
    Node *head;

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

    f1_in= fopen(argv[13], "rt");
    f1_out= fopen(argv[14], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    elim(&head, n);
    printList(f1_out, head);
    matchMaking(&head, f1_out);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[15], "rt");
    f1_out= fopen(argv[16], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    elim(&head, n);
    printList(f1_out, head);
    matchMaking(&head, f1_out);

    fclose(f1_in);
    fclose(f1_out);

    f1_in= fopen(argv[17], "rt");
    f1_out= fopen(argv[18], "wt");

    cerinta12(f1_in, f1_out, &head, &n);
    elim(&head, n);
    printList(f1_out, head);
    matchMaking(&head, f1_out);

    fclose(f1_in);
    fclose(f1_out);

    return 0;
}