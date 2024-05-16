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

