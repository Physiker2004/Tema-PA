#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

int alpha(char s1[], char s2[]){
	char a=s1[0], b=s2[0];
	//char *c1, *c2;

	int i=0;
	if (a<90 && a>64) a+=32;
	if (b<90 && b>64) b+=32;

	/*strcpy(c1,s1);
	c1=strtok(s1, " ");
	strcpy(c2,s2);
	c2=strcpy(s2, " ");

	while (c1){
		while(c2){
			if(c1[0]<c2[0]) return 0;
			c2=strtok(NULL, " ");
		}
	}*/

	while (a==b){
		a=s1[++i];
		b=s2[++i];
	}

	return (a<b);
}

/*int isEmptyQ(Queue*q){
	return (q->front==NULL);
}*/

void deleteQueue(Queue *q){
	Meci *aux;
	while(q->front){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}

//afiseaza coada de meciuri

void printQ(Queue *q, FILE *f){
	char buf[50];
	Meci *m=q->front;
	

	while (m!=NULL){
		fprintf(f, "%-33s-%33s\n", m->n1->nume_echipa, m->n2->nume_echipa);
		m=m->next;

		/*strcpy((m->n1)->nume_echipa, buf);
		strtok(buf, " ");
		while(buf!=NULL){
			fprintf(f, "%s ", buf);
			strtok(NULL, " ");
		}

		fprintf(f, " - ");

		strcpy((m->n2)->nume_echipa, buf);
		strtok(buf, " ");
		while(buf!=NULL){
			fprintf(f, " %s", buf);
			strtok(NULL, " ");
		}

		fprintf(f, "\n");*/
		
	}
	
}

int printS(Node* top, FILE* f){
	int count=0;
	while (top) {
		//fputs(top->nume_echipa, f);
		fprintf(f, "%-33s -  %.2f\n", top->nume_echipa, top->punctaj);
		top=top->next;
		count++;
	}
	return count;
}

//creeaza coada de meciuri din lista initiala/stiva de castigatori (ambele se parcurg prin acelasi mecanism)

void enQ_stack_list(Queue **q, Node **top, FILE *f) {
	Node *temp1, *temp2;
	while (*top){
		Meci *newNode=(Meci*)malloc(sizeof(Meci));

		temp1=(*top);
		temp2=(*top)->next;
		newNode->n1=temp1;
		newNode->n2=temp2;

		*top=(*top)->next->next;

		newNode->next=NULL;
	
		//fprintf(f, "%s vs. %s\n", newNode->n1->nume_echipa, newNode->n2->nume_echipa);

		if ((*q)->rear==NULL) (*q)->rear=newNode; 
		else{
			((*q)->rear)->next=newNode;
			((*q)->rear)=newNode;
		}
		if ((*q)->front==NULL) (*q)->front=(*q)->rear; 	

		//free(temp1);
		//free(temp2);
	}
}

//creeaza doua stive din coada, una de castigatori si una de invinsi

void deQ_toStack(Queue *q, Node **top_l, Node **top_w, FILE *f) {
	Node *no1, *no2;
	Meci *aux;
	int i;

	while((q)->front){
        no1=(q->front)->n1;
        no2=(q->front)->n2;
		//aux=(*q)->front; 

        //n1=aux->n1;
        //n2=aux->n2;

        if (no1->punctaj > no2->punctaj) { 
            no1->next=*top_w;
    		*top_w=no1;
            no2->next=*top_l;
    		*top_l=no2;
			(no1->punctaj)++;
        }
        else {
			no1->next=*top_l;
    		*top_l=no1;
            no2->next=*top_w;
    		*top_w=no2;
			(no2->punctaj)++;
        }

        //fprintf(f, "%s\n", (*top_w)->nume_echipa);
		q->front=(q->front)->next;
        //free(aux);
    }
	
} 

void deleteStack(Node **top){
	Node  *temp;
	while ((*top)!=NULL){ // !isEmpty(*top)
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

/*void push(Node**top, Node *node) {
    node->next=*top;
    *top=node;
}*/

//simuleaza meciurile dintre echipele din lista initiala pana se ajunge la primele 8 echipe castigatoare

void matchMaking(Node **head, FILE *f){
    Queue* Q=createQueue();
	Node *top_w=NULL, *top_l=NULL;
    int n, round=1;

	fprintf(f, "\n--- ROUND NO:%d\n", round);
    enQ_stack_list(&Q, head, f);
	printQ(Q, f);// - printQ incorporat in enQ...
	deleteStack(head);
	*head=NULL;

	fprintf(f, "\nWINNERS OF ROUND NO:%d\n", round);
    deQ_toStack(Q, &top_l, &top_w, f);
	deleteQueue(Q);
	n=printS(top_w, f);
    deleteStack(&top_l);
	round++;

	//printf("%d", n);
    
    while (n>1) {
        Q=createQueue();
		top_l=NULL;

		fprintf(f, "\n--- ROUND NO:%d\n", round);
		enQ_stack_list(&Q, &top_w, f);
		printQ(Q, f);
		deleteStack(&top_w);
		top_w=NULL;

		fprintf(f, "\nWINNERS OF ROUND NO:%d\n", round);
		deQ_toStack(Q, &top_l, &top_w, f);
		deleteQueue(Q);
		n=printS(top_w, f);
		deleteStack(&top_l);
		round++;
    }
}

