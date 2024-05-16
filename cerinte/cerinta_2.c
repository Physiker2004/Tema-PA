#include <stdio.h>
#include <stdlib.h>
#include "player.h"

float punctaj(Node *n){
    int i;
    float sum = 0.0;
    for (i=0;i<n->nr_membrii;i++) sum+= (float)(n->jucatori[i]).puncte;
    sum/=n->nr_membrii;
    return sum;
}

void printPoints (Node *head) {
    if (head==NULL) return;
    else {
        puts(head->nume_echipa);
        printf("%f\n", punctaj(head));
        printPoints(head->next);
    }
}

Node* find_min(Node *head) {
    Node *p, *pmin;
    int i;
    float pct, min = 100.00;
    for (p=head;p!=NULL;p=p->next){
        pct=punctaj(p);
        if (pct<min){
            min=pct;
            pmin=p;
        }
    }
    return pmin;
}

void delete (Node **head){
    if (*head == NULL) return;
    Node *headcopy = *head, *p=find_min(*head);
    //puts(p->nume_echipa);

    if (headcopy==p){
        //puts(headcopy->nume_echipa);//
        //printf("%f\n", punctaj(headcopy));//
        *head=(*head)->next;
        free (headcopy);
        return;
    }

    Node *prev=*head; 
    while (headcopy!=NULL){
        if (headcopy!=p){
            prev=headcopy;
            headcopy=headcopy->next;
        }
        
        else {
            //puts(headcopy->nume_echipa);
            //printf("%f\n", punctaj(headcopy));
            prev->next=headcopy->next;
            free(headcopy);
            return;
        }
    } 
}

int power(int n, int m) {
    if (m==0) return 1;
    else return n*power(n, m-1);
}

void elim(Node **head, int n) {
    int m=0, max=0;
    while (power(2,m)<n) m++;
    max=power(2,m-1);
    while (n>max){
        delete(head);
        n--;
        //printf("%d", n);
    }
    //printf("---------------\n");
}