#include "ts.h"

// Fonction de hachage
unsigned int hash(char* str, int tableSize) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; 
    return hash % tableSize;
}

// Création de la table des symboles
SymbolTable* createSymbolTable() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->size = INITIAL_TABLE_SIZE;
    table->count = 0;
    table->buckets = (void**)malloc(sizeof(void*) * table->size);
    for (int i = 0; i < table->size; i++)
        table->buckets[i] = NULL;
    return table;
}

// Redimensionnement de la table
void resizeSymbolTable(SymbolTable* table) {
    int newSize = table->size * 2;
    void** newBuckets = (void**)malloc(sizeof(void*) * newSize);
    
    for (int i = 0; i < newSize; i++)
        newBuckets[i] = NULL;

    for (int i = 0; i < table->size; i++) {
        void* current = table->buckets[i];
        while (current) {
            void* next;
            if (table == separatorTable || table == keywordTable) {
                SimpleElement* simpleCurrent = (SimpleElement*)current;
                next = simpleCurrent->next;
                unsigned int newIndex = hash(simpleCurrent->name, newSize);
                simpleCurrent->next = (SimpleElement*)newBuckets[newIndex];
                newBuckets[newIndex] = simpleCurrent;
            } else {
                ComplexElement* complexCurrent = (ComplexElement*)current;
                next = complexCurrent->next;
                unsigned int newIndex = hash(complexCurrent->name, newSize);
                complexCurrent->next = (ComplexElement*)newBuckets[newIndex];
                newBuckets[newIndex] = complexCurrent;
            }
            current = next;
        }
    }

    free(table->buckets);
    table->buckets = newBuckets;
    table->size = newSize;
}
// Insertion d'un élément simple (pour séparateurs et mots-clés)
void insertSimple(SymbolTable* table, char* entite, char* code) {
    if ((float)table->count / table->size > LOAD_FACTOR) {
        resizeSymbolTable(table);
    }

    unsigned int index = hash(entite, table->size);
    SimpleElement* newElement = (SimpleElement*)malloc(sizeof(SimpleElement));
    strcpy(newElement->name, entite);
    strcpy(newElement->code, code);
    newElement->next = (SimpleElement*)table->buckets[index];
    table->buckets[index] = newElement;
    
    table->count++;
}
// Insertion d'un élément complexe (pour identificateurs)
void insertComplex(SymbolTable* table, char* entite, char* code, char* type, float val) {
    if ((float)table->count / table->size > LOAD_FACTOR) {
        resizeSymbolTable(table);
    }

    unsigned int index = hash(entite, table->size);
    ComplexElement* newElement = (ComplexElement*)malloc(sizeof(ComplexElement));
    strcpy(newElement->name, entite);
    strcpy(newElement->code, code);
    strcpy(newElement->type, type);
    strcpy(newElement->scope, getCurrentScope()); // Ajout de la portée
    newElement->val = val;
    newElement->next = (ComplexElement*)table->buckets[index];
    table->buckets[index] = newElement;
    
    table->count++;
}

// Recherche ou insertion d'un élément simple (pour séparateurs et mots-clés)
SimpleElement* searchOrInsertSimple(SymbolTable* table, char* entite, char* code) {
    unsigned int index = hash(entite, table->size);
    SimpleElement* current = (SimpleElement*)table->buckets[index];
    while (current) {
        if (strcmp(current->name, entite) == 0)
            return current;
        current = current->next;
    }
    insertSimple(table, entite, code);
    return (SimpleElement*)table->buckets[index];
}

// Recherche ou insertion d'un élément complexe (pour identificateurs)
ComplexElement* searchOrInsertComplex(SymbolTable* table, char* entite, char* code, char* type, float val) {
    unsigned int index = hash(entite, table->size);
    ComplexElement* current = (ComplexElement*)table->buckets[index];
    while (current) {
        if (strcmp(current->name, entite) == 0)
            return current;
        current = current->next;
    }
    insertComplex(table, entite, code, type, val);
    return (ComplexElement*)table->buckets[index];
}
// Affichage de la table simple (pour séparateurs et mots-clés)
void displaySimpleTable(SymbolTable* table, char* tableName) {
    printf("\nTable des Symboles: %s (Taille: %d, Éléments: %d)\n", tableName, table->size, table->count);
    printf("----------------------------------------\n");
    printf("| Nom        | Code       |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < table->size; i++) {
        SimpleElement* current = (SimpleElement*)table->buckets[i];
        while (current) {
            printf("| %-10s | %-10s |\n", current->name, current->code);
            current = current->next;
        }
    }
    printf("----------------------------------------\n");
}

// Affichage de la table complexe (pour identificateurs)
void displayComplexTable(SymbolTable* table, char* tableName) {
    printf("\nTable des Symboles: %s (Taille: %d, Éléments: %d)\n", tableName, table->size, table->count);
    printf("------------------------------------------------------------\n");
    printf("| Nom        | Code       | Type       | Portée      | Valeur |\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < table->size; i++) {
        ComplexElement* current = (ComplexElement*)table->buckets[i];
        while (current) {
            printf("| %-10s | %-10s | %-10s | %-10s | %-6g |\n",
                   current->name, current->code, current->type, current->scope, current->val);
            current = current->next;
        }
    }
    printf("------------------------------------------------------------\n");
}
// Libérer la mémoire
void freeSymbolTable(SymbolTable* table) {
    for (int i = 0; i < table->size; i++) {
        void* current = table->buckets[i];
        while (current) {
            void* temp = current;
            if (table == separatorTable || table == keywordTable) {
                current = ((SimpleElement*)current)->next;
                free(temp);
            } else {
                current = ((ComplexElement*)current)->next;
                free(temp);
            }
        }
    }
    free(table->buckets);
    free(table);
}

// Recherche d'un identificateur dans la table des symboles
ComplexElement* chercher_position(SymbolTable* table, char entite[]) {
    if (table == NULL) return NULL;

    unsigned int index = hash(entite, table->size);
    ComplexElement* current = (ComplexElement*)table->buckets[index];

    while (current) {
        if (strcmp(current->name, entite) == 0) {
            // Vérifier si l'élément est dans la portée actuelle ou parente
            char* currentScope = getCurrentScope();
            if (strstr(currentScope, current->scope) == currentScope || strcmp(current->scope, "global") == 0) {
                return current;
            }
        }
        current = current->next;
    }
    return NULL;
}
// Vérifier si un identificateur est déclaré
int estDeclare(SymbolTable* table, char* entite) {
    ComplexElement* pos = chercher_position(table, entite);
    return (pos != NULL); // Retourne 1 si trouvé, 0 sinon
}
// Mise à jour du type d'un identificateur
void maj_type(SymbolTable* table, char* entite, char* type) {
    ComplexElement* pos = chercher_position(table, entite);
    if (pos != NULL) {
        strncpy(pos->type, type, sizeof(pos->type) - 1);
        pos->type[sizeof(pos->type) - 1] = '\0'; // Sécurité contre le débordement
    }
}
// Mise à jour de la valeur d'un identificateur
void maj_valeur(SymbolTable* table, char* entite, float* valeur) {
    ComplexElement* pos = chercher_position(table, entite);
    if (pos != NULL) {
        pos->val = *valeur;
    }
}
// Obtenir le type d'un identificateur
char* get_type(SymbolTable* table, char* entite) {
    ComplexElement* pos = chercher_position(table, entite);
    if (pos == NULL) return NULL;
    return pos->type; // Retour direct sans allocation dynamique
}
// Obtenir la valeur d'un identificateur
void get_val(SymbolTable* table, char* entite, float* val) {
    ComplexElement* pos = chercher_position(table, entite);
    if (pos != NULL) {
        *val = pos->val;
    }
}
#define MAX_SCOPE_DEPTH 100
char scopeStack[MAX_SCOPE_DEPTH][50]; // Pile pour stocker les portées
int scopeDepth = 0; // Profondeur actuelle de la pile

// Empiler une portée
void pushScope(char* scope) {
    if (scopeDepth < MAX_SCOPE_DEPTH) {
        strcpy(scopeStack[scopeDepth], scope);
        scopeDepth++;
    } else {
        fprintf(stderr, "Erreur : Profondeur de portée maximale atteinte\n");
    }
}

// Dépiler une portée
void popScope() {
    if (scopeDepth > 0) {
        scopeDepth--;
    } else {
        fprintf(stderr, "Erreur : Tentative de dépiler une portée vide\n");
    }
}
// Obtenir la portée actuelle
char* getCurrentScope() {
    if (scopeDepth > 0) {
        return scopeStack[scopeDepth - 1];
    }
    return "global"; // Portée globale par défaut
}

// Vérifie si une variable est déjà déclarée dans sa portée actuelle ou parente
int estDeclareDansaportee(SymbolTable* table, char* entite) {
    if (table == NULL) return 0;

    unsigned int index = hash(entite, table->size);
    ComplexElement* current = (ComplexElement*)table->buckets[index];

    while (current) {
        if (strcmp(current->name, entite) == 0) {
            // Vérifier si l'élément est dans la portée actuelle ou une portée parente
            for (int i = scopeDepth - 1; i >= 0; i--) {
                if (strcmp(current->scope, scopeStack[i]) == 0) {
                    return 1; // La variable est déclarée dans cette portée ou une portée parente
                }
            }

            // Vérifier si la variable est déclarée dans la classe mère
            char* parentScope = getParentClassScope(getCurrentScope());
            while (parentScope != NULL) {
                if (strcmp(current->scope, parentScope) == 0) {
                    return 1; // La variable est déclarée dans la classe mère
                }
                parentScope = getParentClassScope(parentScope); // Vérifier la classe parente de la classe mère
            }
        }
        current = current->next;
    }

    return 0; // La variable n'est pas déclarée dans cette portée ni dans une classe mère
}

char* getParentClassScope(char* currentScope) {
    // Simulation : extraire la classe mère d'une sous-classe en supposant un séparateur "::"
    static char parentScope[50]; // Stock temporaire
    strcpy(parentScope, currentScope);
    char* sep = strrchr(parentScope, '.'); // Supposons que les classes soient notées "ClasseMere.ClasseFille"
    if (sep) {
        *sep = '\0'; // Tronquer pour obtenir la classe mère
        return parentScope;
    }
    return "global"; // Si pas de parent, retour à global
}


// Obtenir le code d'un identificateur dans la table des symboles
char* get_codeentite(SymbolTable* table, char* entite) {
    if (table == NULL) return NULL;

    unsigned int index = hash(entite, table->size);
    ComplexElement* current = (ComplexElement*)table->buckets[index];

    while (current) {
        if (strcmp(current->name, entite) == 0) {
            return current->code; // Retourne le code associé à l'identificateur
        }
        current = current->next;
    }

    return NULL; // Retourne NULL si l'identificateur n'est pas trouvé
}


// Mise à jour de la valeur de retour d'une fonction dans la table des symboles (sans vérification de portée)
void maj_val_fonction(SymbolTable* table, char* fonction, float* valeurRetour) {
    if (table == NULL || valeurRetour == NULL) return;

    unsigned int index = hash(fonction, table->size);
    ComplexElement* current = (ComplexElement*)table->buckets[index];

    while (current) {
        if (strcmp(current->name, fonction) == 0) {
            current->val = *valeurRetour;
            printf("[DEBUG] Valeur de retour mise à jour : %s = %f\n", fonction, *valeurRetour);
            return;
        }
        current = current->next;
    }

    fprintf(stderr, "[WARN] La fonction '%s' n'existe pas dans la table des symboles.\n", fonction);
}
