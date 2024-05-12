#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct p {
    char nume[20];
    char prenume[20];
    int puncte;
};

typedef struct p persoana;

struct node {
    int nr_membrii;
    char nume_echipa[50];
    persoana jucatori[50];
    struct node *next;
};

typedef struct node Node;

void createNode (FILE *f, Node **head) {
    Node* echipa = (Node*) malloc(sizeof(Node));
    int i;
    char buf[50];

    fscanf(f, "%d ", &echipa->nr_membrii);
    fgets(buf, 50, f);
    strcpy(echipa->nume_echipa, buf);
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

int main(int argc, char *argv[]){
    FILE* f_in= fopen(argv[1], "rt");
    FILE* f_out= fopen(argv[2], "wt");
    int nr_echipe;
    int i;
    Node* head = NULL;  

    fscanf(f_in, "%d", &nr_echipe);

    for (i=0;i<nr_echipe;i++){
        createNode(f_in, &head);
    }

    printList(f_out, head);

    fclose(f_in);
    fclose(f_out);
    return 0;
}