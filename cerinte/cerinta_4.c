#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

//creeaza nod arbore din nod stiva 

BST* createLeaf(Node *node){
    BST *leaf=(BST*)malloc(sizeof(BST));
    strcpy(leaf->nume_echipa, node->nume_echipa);
    leaf->punctaj=node->punctaj;
    leaf->dr=leaf->st=NULL;
    return leaf;
}

//sorteaza in ordine alfabetica

int alpha(char s1[], char s2[]){
	char a=s1[0], b=s2[0];

	int i=0;
	if (a<90 && a>64) a+=32;
	if (b<90 && b>64) b+=32;

	while (a==b){
		a=s1[++i];
		b=s2[++i];
	}

	return (a<b);
}

//insereaza elemente in arborele binar de cautare recursiv
BST* insert_BST(BST *root, Node *top) {
    if(!root) return createLeaf(top);
        
    if (top->punctaj < root->punctaj)
        root->dr = insert_BST(root->dr, top);

    else {
        if (top->punctaj > root->punctaj)
            root->st = insert_BST(root->st, top);

        else {
            if (top->punctaj == root->punctaj){
                if (alpha(top->nume_echipa, root->nume_echipa)==1)
                root->dr = insert_BST(root->dr, top);
            
                else if (alpha(top->nume_echipa, root->nume_echipa)==0)
                root->st = insert_BST(root->st, top);
            }
        }
    }
    return root;
}

//parcurge arborele in ordine SRD

void inordine(BST *root, FILE* f){
    if(root){
        inordine(root->st, f);
        fprintf(f, "%-33s -  %.2f\n", root->nume_echipa, root->punctaj);
        inordine(root->dr, f);
    }
}

//afiseaza clasament echipe

void clasament(BST *root, FILE* f){
    fprintf(f, "\nTOP 8 TEAMS:\n");
    inordine(root, f);
}