#include <stdio.h>

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
    float punctaj;
    struct node *next;
};

typedef struct node Node;

struct m {
    Node *n1, *n2;
    struct m *next;
};

typedef struct m Meci;

struct q {
    Meci *rear, *front;
};

typedef struct q Queue;

struct treeNode {
    char nume_echipa[50];
    float punctaj;
    struct treeNode *st, *dr;
};

typedef struct treeNode BST;

//2
//void printPoints (Node *head); 
//Node* find_min(Node *head);
void delete (Node **head);
int power(int n, int m);
void elim(Node **head, int n);

//3

Queue* createQueue();
void deleteQueue(Queue *q);
void deQ_toStack(Queue *q, Node **top_l, Node **top_w);// 
//void simulare_meciuri(Queue *q, Node **castig, Node **inv);
void enQ_stack_list(Queue **q, Node **top, FILE *f);
//int isEmptyQ(Queue*q);
int printS(Node *top, FILE *f);
void printQ(Queue *q, FILE *f);
void deleteStack(Node**top);

//void push(Node**top, Node *n);

void matchMaking(Node **head, BST **root, FILE *f);

//4

BST* createLeaf(Node *node);
BST* insert_BST(BST *root, Node *top);
void inordine(BST *root, FILE* f);
int alpha(char s1[], char s2[]);

void clasament(BST *root, FILE* f);
