#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TABLE_SIZE 100  
#define LOAD_FACTOR 0.7         

// Structure pour les séparateurs et les mots-clés (2 champs)
typedef struct SimpleElement {
    char name[50];
    char code[20];
    struct SimpleElement* next;
} SimpleElement;

// Structure pour les identificateurs (4 champs)
typedef struct ComplexElement {
    char name[50];       // Nom de l'identificateur
    char code[20];       // Code (par exemple, "VAR", "PARAM", "ATTR")
    char type[20];       // Type de la variable (int, float, etc.)
    char scope[50];      // Portée (par exemple, "global", "class:MyClass", "method:myMethod")
    float val;           // Valeur (si applicable)
    struct ComplexElement* next; // Pointeur vers le prochain élément
} ComplexElement;

// Structure de la table des symboles
typedef struct {
    void** buckets; // Pointeur générique pour gérer les deux types d'éléments
    int size;
    int count;
} SymbolTable;

// Déclaration des variables globales
extern SymbolTable* separatorTable;
extern SymbolTable* keywordTable;

// Déclaration des fonctions
unsigned int hash(char* str, int tableSize);
SymbolTable* createSymbolTable();
void resizeSymbolTable(SymbolTable* table);
void insertSimple(SymbolTable* table, char* entite, char* code);
void insertComplex(SymbolTable* table, char* entite, char* code, char* type, float val);
SimpleElement* searchOrInsertSimple(SymbolTable* table, char* entite, char* code);
ComplexElement* searchOrInsertComplex(SymbolTable* table, char* entite, char* code, char* type, float val);
void displaySimpleTable(SymbolTable* table, char* tableName);
void displayComplexTable(SymbolTable* table, char* tableName);
void freeSymbolTable(SymbolTable* table);

// Recherche un élément dans la table des identificateurs
ComplexElement* chercher_position(SymbolTable* table, char* entite);

// Met à jour le type d'un identificateur
void maj_type(SymbolTable* table, char* entite, char* type);

// Met à jour la valeur d'un identificateur
void maj_valeur(SymbolTable* table, char* entite, float* valeur);
void maj_val_fonction(SymbolTable* table, char* fonction, float* valeurRetour);


// Retourne le type d'un identificateur
char* get_type(SymbolTable* table, char* entite);

// Récupère la valeur d'un identificateur
void get_val(SymbolTable* table, char* entite, float* val);

int estDeclare(SymbolTable* table, char* entite);

int estDeclareDansaportee(SymbolTable* table, char* entite);
char* getParentClassScope(char* currentScope);
char* get_codeentite(SymbolTable* table, char* entite);


void pushScope(char* scope);
void popScope();
char* getCurrentScope();






#endif  // TS_H

