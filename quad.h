#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ts.h"
extern float taille; // Pour les tableaux 1D
extern float i, j;   // Pour les tableaux 2D (lignes et colonnes)


// Déclaration de la structure quadruplets
typedef struct {
    char oper[100];
    char op1[100];
    char op2[100];
    char res[100];
    bool used;
} qdr;

extern qdr quad[1000];  // Tableau pour stocker les quadruplets
extern int qc;          // Compteur de quadruplets

// Fonction d'ajout d'un quadruplet
void quadr(char opr[], char op1[], char op2[], char res[]);

// Fonction de mise à jour d'un quadruplet
void updateQuad(int num_quad, int colon_quad, char val[]);

// Fonction d'affichage des quadruplets
void afficher_qdr();

// Fonction d'optimisation de quadruplets
void optimiser() ;

void generer_code_assembleur(const char* nom_fichier, SymbolTable* idfTable);

#endif
