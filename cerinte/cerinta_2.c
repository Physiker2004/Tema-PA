#include <stdio.h>
#include <stdlib.h>
#include "player.h"

//afiseaza punctajul tuturor echipelor (debug)

/*void printPoints (Node *head) {
    if (head==NULL) return;
    else {
        puts(head->nume_echipa);
        printf("%f\n", head->punctaj);
        printPoints(head->next);
    }
}*/


//sterge echipa cu pctj cel mai mic
void delete (Node **head){
    if (*head == NULL) return;

    Node *headcopy = *head, *p;

    float min = (*head)->punctaj;
    for (p=*head;p!=NULL;p=p->next)
        if (p->punctaj<min) min=p->punctaj;

    if (headcopy->punctaj==min){
        *head=(*head)->next;
        free(headcopy);
        return;
    }

    Node *prev=*head; 
    while (headcopy!=NULL){
        if (headcopy->punctaj!=min){
            prev=headcopy;
            headcopy=headcopy->next;
        }
        
        else {
            prev->next=headcopy->next;
            free(headcopy);
            return;
        }
    } 
}

//ridicare la putere

int power(int n, int m) {
    if (m==0) return 1;
    else return n*power(n, m-1);
}

//sterge elemente din lista pana la cea mai apropiata putere a lui 2 

void elim(Node **head, int n) {
    int m=0, max=0;
    while (power(2,m)<=n) m++;
    max=power(2,m-1);
    while (n>max){
        delete(head);
        n--;
    }
}
