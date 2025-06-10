#include "quad.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "ts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_QUADS 1000
#define MAX_OPTIMIZATION_PASSES 20
#define MAX_LABEL_LEN 32

// Variables globales
qdr quad[MAX_QUADS];
int qc = 0;
int boolqc = 0;
SymbolTable* idfTable;

// Fonctions utilitaires
bool is_temp_var(const char *var) {
    return var && var[0] == 'T' && isdigit(var[1]);
}

bool is_sep(const char *var) {
    static const char *control_ops[] = {
        "BOUNDS", "BL", "BG", "BE", "BNE", "BR", "BLE", "BGE",
        "BZ", "BNZ", "ADEC", "return", "call", "new", NULL
    };
    
    if (!var) return false;
    
    for (int i = 0; control_ops[i]; i++) {
        if (strcmp(var, control_ops[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool is_vide(const char *str) {
    if (!str || str[0] == '\0') return true;
    return strcasecmp(str, "vide") == 0;
}

bool is_number(const char *str) {
    if (!str) return false;
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

// Fonctions de base
void quadr(char opr[], char op1[], char op2[], char res[]) {
    if (qc >= MAX_QUADS) {
        fprintf(stderr, "Erreur: Dépassement du tableau de quadruplets\n");
        return;
    }
    
    strncpy(quad[qc].oper, opr ? opr : "vide", MAX_LABEL_LEN);
    strncpy(quad[qc].op1, op1 ? op1 : "vide", MAX_LABEL_LEN);
    strncpy(quad[qc].op2, op2 ? op2 : "vide", MAX_LABEL_LEN);
    strncpy(quad[qc].res, res ? res : "vide", MAX_LABEL_LEN);
    quad[qc].used = false;
    qc++;
}

void updateQuad(int num_quad, int colon_quad, char val[]) {
    if (num_quad < 0 || num_quad >= qc) {
        fprintf(stderr, "Erreur: Numéro de quad invalide %d\n", num_quad);
        return;
    }
    
    char *target = NULL;
    switch (colon_quad) {
        case 0: target = quad[num_quad].oper; break;
        case 1: target = quad[num_quad].op1; break;
        case 2: target = quad[num_quad].op2; break;
        case 3: target = quad[num_quad].res; break;
        default:
            fprintf(stderr, "Erreur: Numéro de colonne invalide %d\n", colon_quad);
            return;
    }
    
    strncpy(target, val ? val : "vide", MAX_LABEL_LEN);
}

void afficher_qdr() {
    printf("*********** Les Quadruplets ***********\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < qc; i++) {
        printf("%4d - (%-8s, %-10s, %-10s, %-10s) %s\n", 
               i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res,
               quad[i].used ? "[used]" : "");
        printf("---------------------------------------\n");
    }
}

// Nouvelle fonction pour gérer correctement les boucles
void fix_loop_quads() {
    // Première passe: identifier toutes les cibles de saut
    bool is_branch_target[MAX_QUADS] = {false};
    int loop_start_stack[MAX_QUADS] = {0};
    int loop_stack_top = -1;

    for (int i = 0; i < qc; i++) {
        if (strcmp(quad[i].oper, "BL") == 0) {
            // Empiler le début de boucle
            loop_stack_top++;
            loop_start_stack[loop_stack_top] = i;
        }
        else if (strcmp(quad[i].oper, "BR") == 0 && loop_stack_top >= 0) {
            // Marquer la cible de retour de boucle
            int target = atoi(quad[i].op1);
            if (target >= 0 && target < qc) {
                is_branch_target[target] = true;
            }
            // Dépiler le début de boucle
            loop_stack_top--;
        }
        else if (is_sep(quad[i].oper)) {
            // Marquer toutes les cibles de saut
            if (isdigit(quad[i].op1[0])) {
                int target = atoi(quad[i].op1);
                if (target >= 0 && target < qc) {
                    is_branch_target[target] = true;
                }
            }
        }
    }

    // Deuxième passe: s'assurer que toutes les cibles sont valides
    for (int i = 0; i < qc; i++) {
        if (is_sep(quad[i].oper)) {
            if (isdigit(quad[i].op1[0])) {
                int target = atoi(quad[i].op1);
                if (target < 0 || target >= qc || !is_branch_target[target]) {
                    // Corriger les cibles invalides
                    char new_target[10];
                    snprintf(new_target, sizeof(new_target), "%d", qc);
                    strncpy(quad[i].op1, new_target, MAX_LABEL_LEN);
                    
                    // Ajouter des quads vides si nécessaire
                    while (qc <= target) {
                        quadr("vide", "vide", "vide", "vide");
                    }
                }
            }
        }
    }
}

// Optimisations améliorées
void propagation_copie() {
    for (int i = 0; i < qc; i++) {
        // Vérifie : dest = src ; avec src ≠ variable temporaire, op2 vide
        if (strcmp(quad[i].oper, "=") == 0 && is_vide(quad[i].op2) && !is_temp_var(quad[i].op1)) {
            const char *src = quad[i].op1;
            const char *dest = quad[i].res;

            for (int j = i + 1; j < qc; j++) {
                // Stopper à un séparateur logique (ex: jump, label...)
                if (is_sep(quad[j].oper)) break;

                // Stopper si dest est modifiée dans res
                if (strcmp(quad[j].res, dest) == 0) break;

                // Remplacer op1 si égal à dest et pas un accès tableau
                if (!is_vide(quad[j].op1) && strchr(quad[j].op1, '[') == NULL && strcmp(quad[j].op1, dest) == 0) {
                    printf("Propagation de copie: %s -> %s au quad %d (op1)\n", dest, src, j);
                    strncpy(quad[j].op1, src, MAX_LABEL_LEN);
                    boolqc = 1;
                }

                // Remplacer op2 si égal à dest et pas un accès tableau
                if (!is_vide(quad[j].op2) && strchr(quad[j].op2, '[') == NULL && strcmp(quad[j].op2, dest) == 0) {
                    printf("Propagation de copie: %s -> %s au quad %d (op2)\n", dest, src, j);
                    strncpy(quad[j].op2, src, MAX_LABEL_LEN);
                    boolqc = 1;
                }
            }
        }
    }
}


void elimination_redondantes() {
    bool is_jump_target[MAX_QUADS] = {false};
    
    // Marquer les cibles de saut
    for (int i = 0; i < qc; i++) {
        if (is_sep(quad[i].oper) && isdigit(quad[i].op1[0])) {
            int target = atoi(quad[i].op1);
            if (target >= 0 && target < qc) {
                is_jump_target[target] = true;
                quad[target].used = true;
            }
        }
    }
    
    for (int i = 0; i < qc; i++) {
        if (is_sep(quad[i].oper) || is_jump_target[i]) continue;
        
        // Ne pas éliminer les accès aux tableaux
        if (strchr(quad[i].op1, '[') != NULL || strchr(quad[i].op2, '[') != NULL) continue;
        
        for (int j = i + 1; j < qc; j++) {
            if (is_sep(quad[j].oper)) break;// ??
            if (is_jump_target[j]) continue;
            
            if (strcmp(quad[i].oper, quad[j].oper) == 0 &&
                strcmp(quad[i].op1, quad[j].op1) == 0 &&
                strcmp(quad[i].op2, quad[j].op2) == 0) {
                
                printf("Redondance trouvée entre les quads %d et %d\n", i, j);
                
                // Mettre à jour les références
                for (int k = j + 1; k < qc; k++) {
                    if (strcmp(quad[k].op1, quad[j].res) == 0) {
                        strncpy(quad[k].op1, quad[i].res, MAX_LABEL_LEN);
                    }
                    if (strcmp(quad[k].op2, quad[j].res) == 0) {
                        strncpy(quad[k].op2, quad[i].res, MAX_LABEL_LEN);
                    }
                }
                
                // Mettre à jour les sauts
                for (int k = 0; k < qc; k++) {
                    if (is_sep(quad[k].oper) && isdigit(quad[k].op1[0])) {
                        int target = atoi(quad[k].op1);
                        if (target > j) {
                            char new_target[10];
                            snprintf(new_target, sizeof(new_target), "%d", target - 1);
                            strncpy(quad[k].op1, new_target, MAX_LABEL_LEN);
                        }
                        else if (target == j) {
                            char new_target[10];
                            snprintf(new_target, sizeof(new_target), "%d", i);
                            strncpy(quad[k].op1, new_target, MAX_LABEL_LEN);
                        }
                    }
                }
                
                // Supprimer le quad redondant
                for (int k = j; k < qc - 1; k++) {
                    quad[k] = quad[k + 1];
                }
                qc--;
                boolqc = 1;
                j--;
            }
        }
    }
}

float to_float(const char *s) {
    if (s == NULL || strlen(s) == 0) return -1;
    return atof(s);
}

// Fonction helper pour vérifier si une variable est utilisée dans un branchement
static int is_loop_var(const char* var) {
    for (int j = 0; j < qc; j++) {
        if (strcmp(quad[j].op1, var) == 0 || strcmp(quad[j].op2, var) == 0) {
            if (strcmp(quad[j].oper, "BG") == 0 || strcmp(quad[j].oper, "BR") == 0 || 
                strcmp(quad[j].oper, "BR<") == 0 || strcmp(quad[j].oper, "BR>") == 0 ||
                strcmp(quad[j].oper, "BR<=") == 0 || strcmp(quad[j].oper, "BR>=") == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void simplification_algebrique() {
    for (int i = 0; i < qc; i++) {
        if (is_sep(quad[i].oper)) continue;

        char *op = quad[i].oper;
        char *op1 = quad[i].op1;
        char *op2 = quad[i].op2;
        char *res = quad[i].res;

        float fop1 = to_float(op1);
        float fop2 = to_float(op2);

        // Vérifier si le résultat est une variable de boucle ou auto-affectation
        int skip_simplification = is_loop_var(res) || strcmp(res, op1) == 0 || strcmp(res, op2) == 0;

        // Multiplication
        if (strcmp(op, "*") == 0) {
            if (skip_simplification) continue;
            
            if ((is_number(op1) && fop1 == 0.0) || (is_number(op2) && fop2 == 0.0)) {
                printf("Simplification: %s * %s → 0 (quad %d)\n", op1, op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, "0", MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op1) && fop1 == 1.0) {
                printf("Simplification: 1 * %s → %s (quad %d)\n", op2, op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op2, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op2) && fop2 == 1.0) {
                printf("Simplification: %s * 1 → %s (quad %d)\n", op1, op1, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op1, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op1) && fop1 == 2.0) {
                printf("Optimisation: %s = 2 * %s → %s = %s + %s (quad %d)\n", res, op2, res, op2, op2, i);
                strncpy(quad[i].oper, "+", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op2, MAX_LABEL_LEN);
                strncpy(quad[i].op2, op2, MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op2) && fop2 == 2.0) {
                printf("Optimisation: %s = %s * 2 → %s = %s + %s (quad %d)\n", res, op1, res, op1, op1, i);
                strncpy(quad[i].oper, "+", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op1, MAX_LABEL_LEN);
                strncpy(quad[i].op2, op1, MAX_LABEL_LEN);
                boolqc = 1;
            }
        }

        // Addition
        else if (strcmp(op, "+") == 0) {
            if (skip_simplification) continue;
            
            if (is_number(op1) && fop1 == 0.0) {
                printf("Simplification: 0 + %s → %s (quad %d)\n", op2, op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op2, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op2) && fop2 == 0.0) {
                printf("Simplification: %s + 0 → %s (quad %d)\n", op1, op1, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op1, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            }
        }

        // Soustraction
        else if (strcmp(op, "-") == 0) {
            if (skip_simplification) continue;
            
            if (is_number(op2) && fop2 == 0.0) {
                printf("Simplification: %s - 0 → %s (quad %d)\n", op1, op1, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op1, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (strcmp(op1, op2) == 0) {
                printf("Simplification: %s - %s → 0 (quad %d)\n", op1, op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, "0", MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            }
        }

        // Division
        else if (strcmp(op, "/") == 0) {
            if (skip_simplification) continue;
            
            if (is_number(op1) && fop1 == 0.0 && fop2 != 0.0) {
                printf("Simplification: 0 / %s → 0 (quad %d)\n", op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, "0", MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (is_number(op2) && fop2 == 1.0) {
                printf("Simplification: %s / 1 → %s (quad %d)\n", op1, op1, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, op1, MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            } else if (strcmp(op1, op2) == 0 && fop2 != 0.0) {
                printf("Simplification: %s / %s → 1 (quad %d)\n", op1, op2, i);
                strncpy(quad[i].oper, "=", MAX_LABEL_LEN);
                strncpy(quad[i].op1, "1", MAX_LABEL_LEN);
                strncpy(quad[i].op2, "vide", MAX_LABEL_LEN);
                boolqc = 1;
            }
        }
    }
}


void elimination_code_inutile() {
    bool is_used[MAX_QUADS] = {false};
    bool is_jump_target[MAX_QUADS] = {false};
    
    // Marquer les quads de contrôle et leurs cibles comme utilisés
    for (int i = 0; i < qc; i++) {
        if (is_sep(quad[i].oper)) {
            is_used[i] = true;
            
            if (isdigit(quad[i].op1[0])) {
                int target = atoi(quad[i].op1);
                if (target >= 0 && target < qc) {
                    is_jump_target[target] = true;
                    is_used[target] = true;
                }
            }
        }
    }
    
    // Protéger toutes les variables non temporaires et les accès aux tableaux
    for (int i = 0; i < qc; i++) {
        // Si le résultat n'est pas une variable temporaire OU c'est un accès tableau
        if (!is_temp_var(quad[i].res) || strstr(quad[i].res, "[") || 
            strstr(quad[i].op1, "[") || strstr(quad[i].op2, "[")) {
            is_used[i] = true;
        }
    }
    
    // Marquage des dépendances en arrière
    for (int i = qc - 1; i >= 0; i--) {
        if (is_used[i] || is_sep(quad[i].oper)) {
            // Marquer les quads qui produisent les opérandes
            if (!is_number(quad[i].op1) && !is_temp_var(quad[i].op1)) {
                // Variable non temporaire - doit être protégée
                is_used[i] = true;
            }
            else if (!is_number(quad[i].op1)) {
                // Variable temporaire - suivre la dépendance
                for (int j = i - 1; j >= 0; j--) {
                    if (strcmp(quad[j].res, quad[i].op1) == 0) {
                        is_used[j] = true;
                        break;
                    }
                }
            }
            
            if (!is_number(quad[i].op2) && !is_temp_var(quad[i].op2)) {
                // Variable non temporaire - doit être protégée
                is_used[i] = true;
            }
            else if (!is_number(quad[i].op2)) {
                // Variable temporaire - suivre la dépendance
                for (int j = i - 1; j >= 0; j--) {
                    if (strcmp(quad[j].res, quad[i].op2) == 0) {
                        is_used[j] = true;
                        break;
                    }
                }
            }
        }
    }
    
    // Suppression sécurisée
    for (int i = qc - 1; i >= 0; i--) {
        if (!is_used[i] && !is_sep(quad[i].oper) && 
            is_temp_var(quad[i].res) && 
            !strstr(quad[i].op1, "[") && !strstr(quad[i].op2, "[")) {
            
            printf("Élimination de code inutile au quad %d: (%s, %s, %s, %s)\n",
                  i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
            
            // Mettre à jour les sauts
            for (int j = 0; j < qc; j++) {
                if (is_sep(quad[j].oper) && isdigit(quad[j].op1[0])) {
                    int target = atoi(quad[j].op1);
                    if (target > i) {
                        char new_target[10];
                        snprintf(new_target, sizeof(new_target), "%d", target - 1);
                        strncpy(quad[j].op1, new_target, MAX_LABEL_LEN);
                    }
                }
            }
            
            // Supprimer le quad
            for (int j = i; j < qc - 1; j++) {
                quad[j] = quad[j + 1];
            }
            qc--;
            boolqc = 1;
        }
    }
}

void optimiser() {
    int pass_count = 0;
    
    printf("\nDébut de l'optimisation...\n");
    
    do {
        boolqc = 0;
        pass_count++;
        
        printf("\n--- Passe d'optimisation %d ---\n", pass_count);
        
        // Corriger d'abord la structure des boucles
        fix_loop_quads();
        
        // Appliquer les optimisations dans un ordre logique
        elimination_redondantes();
        propagation_copie();
        simplification_algebrique();
        elimination_code_inutile();
        
        // Vérifier les boucles infinies
        for (int i = 0; i < qc; i++) {
            if (is_sep(quad[i].oper) && isdigit(quad[i].op1[0])) {
                int target = atoi(quad[i].op1);
                if (target == i) {
                    printf("Attention: Boucle infinie potentielle détectée au quad %d\n", i);
                    // Corriger en sautant au quad suivant
                    char new_target[10];
                    snprintf(new_target, sizeof(new_target), "%d", i + 1);
                    strncpy(quad[i].op1, new_target, MAX_LABEL_LEN);
                    boolqc = 1;
                }
            }
        }
        
        if (pass_count >= MAX_OPTIMIZATION_PASSES) {
            printf("Attention: Nombre maximum de passes atteint (%d)\n", MAX_OPTIMIZATION_PASSES);
            break;
        }
    } while (boolqc == 1);
    
    printf("\nOptimisation terminée en %d passes\n", pass_count);
}

// Fonction pour vérifier si une chaîne représente un entier malgré un point décimal
int is_really_integer(const char* str) {
    char* dot = strchr(str, '.');
    if (!dot) return 0; // Pas de point décimal
    
    // Vérifie que tous les caractères après le point sont des zéros
    for (char* p = dot + 1; *p; p++) {
        if (*p != '0') return 0;
    }
    return 1;
}

void float_to_int_if_possible(char *num_str) {
    char *dot = strchr(num_str, '.');
    if (!dot) {
        // Pas de point décimal => pas besoin de conversion
        return;
    }

    // Vérifier que tout ce qui suit le '.' est des '0'
    for (char *p = dot + 1; *p != '\0'; p++) {
        if (*p != '0') {
            return; // Il y a une partie décimale non nulle => ne rien faire
        }
    }

    // On peut tronquer la chaîne au niveau du '.'
    *dot = '\0';
}

void generer_code_assembleur(const char* nom_fichier, SymbolTable* idfTable) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (!fichier) {
        perror("Erreur lors de la création du fichier assembleur");
        return;
    }

    // Tableau pour suivre les éléments déjà déclarés
    char declared_items[1000][100] = {0};
    int item_count = 0;
    int main_proc_declared = 0;

    // Variables externes pour les tailles de tableaux
    extern float taille; // Pour les tableaux 1D
    extern float i, j;   // Pour les tableaux 2D

    // 1. En-tête du programme
    fprintf(fichier, "; Fichier généré automatiquement par le compilateur\n");
    fprintf(fichier, "; Code compatible avec EMU8086\n\n");

    // 2. Segment de données (avant le segment de code pour EMU8086)
    fprintf(fichier, ".MODEL SMALL\n");
    fprintf(fichier, ".STACK 100h\n\n");
    
    fprintf(fichier, ".DATA\n");
    fprintf(fichier, "    ERR_UNDERFLOW_MSG DB 'Erreur: indice inferieur a 0$'\n");
    fprintf(fichier, "    ERR_OVERFLOW_MSG DB 'Erreur: indice superieur a la taille$'\n");
    fprintf(fichier, "    DIV_ZERO_MSG DB 'Erreur: Division par zero$'\n");
    fprintf(fichier, "    MSG_RESULT DB 'Resultat: $'\n");
    fprintf(fichier, "    BUFFER DB 10 DUP('$')\n");
    // FLoat
    fprintf(fichier, "    ; Variables pour la partie entière et décimale\n");
    fprintf(fichier, "    INT_PART DW ?\n");
    fprintf(fichier, "    DEC_PART DB ?\n");
    fprintf(fichier, "    NEWLINE DB 13,10,'$'\n");
    fprintf(fichier, "    FLOAT_POINT DB '.','$'\n");

    // Messages standardisés
    fprintf(fichier, "    MSG_ADD_INT DB 'INT ADD: $'\n");
    fprintf(fichier, "    MSG_SUB_INT DB 'INT SUB: $'\n");
    fprintf(fichier, "    MSG_MUL_INT DB 'INT MUL: $'\n");
    fprintf(fichier, "    MSG_DIV_INT DB 'INT DIV: $'\n");
    fprintf(fichier, "    MSG_ADD_FLOAT DB 'FLOAT ADD: $'\n");
    fprintf(fichier, "    MSG_SUB_FLOAT DB 'FLOAT SUB: $'\n");
    fprintf(fichier, "    MSG_MUL_FLOAT DB 'FLOAT MUL: $'\n");
    fprintf(fichier, "    MSG_DIV_FLOAT DB 'FLOAT DIV: $'\n");
    
    // Déclarer TRUE et FALSE
    fprintf(fichier, "    TRUE DW 1\n");
    fprintf(fichier, "    FALSE DW 0\n");
    strcpy(declared_items[item_count++], "true");
    strcpy(declared_items[item_count++], "false");

    // Variables de la table des symboles
    for (int idx = 0; idx < idfTable->size; idx++) {
        ComplexElement* current = (ComplexElement*)idfTable->buckets[idx];
        while (current) {
            char safe_name[100];
            strncpy(safe_name, current->name, sizeof(safe_name));
            safe_name[sizeof(safe_name)-1] = '\0'; // Assurance null-termination
            
            // Nettoyage du nom (minuscules et remplacement des . par _)
            for (int i = 0; safe_name[i]; i++) {
                safe_name[i] = tolower(safe_name[i]);
                if (safe_name[i] == '.') safe_name[i] = '_';
                if (!isalnum(safe_name[i]) && safe_name[i] != '_') safe_name[i] = '_';
            }
    
            // Ajout d'un préfixe si le nom commence par un chiffre
            if (isdigit(safe_name[0])) {
                char temp[100];
                snprintf(temp, sizeof(temp), "val_%s", safe_name);
                strncpy(safe_name, temp, sizeof(safe_name));
                safe_name[sizeof(safe_name)-1] = '\0';
            }
        
            // Vérifier si déjà déclaré
            int already_declared = 0;
            for (int i = 0; i < item_count; i++) {
                if (strcmp(declared_items[i], safe_name) == 0) {
                    already_declared = 1;
                    break;
                }
            }
            
            if (!already_declared) {
                // Gestion des noms réservés
                if (strcmp(safe_name, "main") == 0) {
                    strcpy(safe_name, "main_var");
                    main_proc_declared = 1;
                }
                
                // Gestion des tableaux
                if (strstr(current->type, "[") != NULL) {
                    if (strstr(current->type, "[][") != NULL) {
                        fprintf(fichier, "    %s DW %d DUP(0) ; Tableau 2D %dx%d\n", 
                                safe_name, (int)(i*j), (int)i, (int)j);
                    } else {
                        fprintf(fichier, "    %s DW %d DUP(0) ; Tableau de taille %d\n", 
                                safe_name, (int)taille, (int)taille);
                    }
                } 
                else {
                    // Variables simples
                    if (strchr(current->name, '.')) {
                        // Flottant - stocké ×10
                        char* endptr;
                        float val = strtof(current->name, &endptr);
                        int scaled_val = (int)round(val * 10);
                        fprintf(fichier, "    %s DW %d     ; %.1f (valeur ×10)\n", 
                                safe_name, scaled_val, val);
                    } 
                    else if (isdigit(current->name[0])) {
                        // Constante entière - on utilise le nom original pour la valeur
                        fprintf(fichier, "    %s DW %s\n", safe_name, current->name);
                    } 
                    else {
                        // Variable normale
                        fprintf(fichier, "    %s DW 0\n", safe_name);
                    }
                }
                strcpy(declared_items[item_count++], safe_name);
            }
            current = current->next;
        }
    }
    
    // Variables temporaires
    for (int idx = 0; idx < qc; idx++) {
        if (is_temp_var(quad[idx].res)) {
            char safe_temp[100];
            strncpy(safe_temp, quad[idx].res, sizeof(safe_temp));
            safe_temp[sizeof(safe_temp)-1] = '\0';
            
            // Nettoyage du nom temporaire
            for (int i = 0; safe_temp[i]; i++) {
                safe_temp[i] = tolower(safe_temp[i]);
                if (safe_temp[i] == '.') safe_temp[i] = '_';
                if (!isalnum(safe_temp[i]) && safe_temp[i] != '_') safe_temp[i] = '_';
            }
    
            int already_declared = 0;
            for (int i = 0; i < item_count; i++) {
                if (strcmp(declared_items[i], safe_temp) == 0) {
                    already_declared = 1;
                    break;
                }
            }
            
            if (!already_declared) {
                if (strchr(quad[idx].res, '.')) {
                    // Temporaire flottant
                    float val = atof(quad[idx].res);
                    int scaled_val = (int)(val * 10);
                    fprintf(fichier, "    %s DW %d     ; %.1f temporaire (valeur ×10)\n", 
                            safe_temp, scaled_val, val);
                } else {
                    // Temporaire entier
                    fprintf(fichier, "    %s DW 0 ; Variable temporaire\n", safe_temp);
                }
                strcpy(declared_items[item_count++], safe_temp);
            }
        }
    }

    // Chaînes constantes (inchangé)
    for (int idx = 0; idx < qc; idx++) {
        if (quad[idx].op1[0] == '"') {
            fprintf(fichier, "    STR%d DB %s, '$' ; Chaîne constante\n", idx, quad[idx].op1);
        }
    }
    
    // 3. Segment de code
    fprintf(fichier, "\n.CODE\n");

    // Détection des labels - augmenté la taille à 10000
    int labels[10000] = {0};  // Tableau pour marquer les quads qui ont besoin de labels

    // Premier passage : Identifier toutes les positions de quads qui ont besoin de labels
    for (int idx = 0; idx < qc; idx++) {
        // Gérer toutes les instructions de branchement (BL, BG, BE, BNE, etc.)
        if (quad[idx].oper[0] == 'B' && strlen(quad[idx].oper) > 1) {
            int target = atoi(quad[idx].op1);
            if (target >= 0 && target < 10000) {
                labels[target] = 1;  // Marquer ce quad comme nécessitant un label
            }
        }
    }
    
    // Point d'entrée principal
    fprintf(fichier, "\nMAIN PROC FAR\n");
    fprintf(fichier, "    ; Initialisation des segments de données\n");
    fprintf(fichier, "    MOV AX, @DATA\n");
    fprintf(fichier, "    MOV DS, AX\n\n");


    // Traduction des quadruplets
    for (int idx = 0; idx < qc; idx++) {
        // Insérer un label si ce quad est une cible de saut
        if (labels[idx]) {
            fprintf(fichier, "LABEL_%d:\n", idx);
        }

        fprintf(fichier, "    ; Quadruplet %d: (%s, %s, %s, %s)\n", 
                idx, quad[idx].oper, quad[idx].op1, quad[idx].op2, quad[idx].res);
        
        char op1[100] = "", op2[100] = "", res[100] = "";

        // si op1 ou op2 contient un chiffre entier sous forme float 1.00000 il doit etre 1
        strcpy(op1, quad[idx].op1);
        strcpy(op2, quad[idx].op2);
        strcpy(res, quad[idx].res);

        float_to_int_if_possible(op1);
        float_to_int_if_possible(op2);
        strcpy(quad[idx].op1, op1);
        strcpy(quad[idx].op2, op2);

        // Traiter op1
        if (!is_vide(quad[idx].op1)) {
            strcpy(op1, quad[idx].op1);
            if (strchr(op1, '.')) *strchr(op1, '.') = '\0';
            if (strcmp(op1, "true") == 0) strcpy(op1, "TRUE");
            if (strcmp(op1, "false") == 0) strcpy(op1, "FALSE");
        }

        // Traiter op2
        if (!is_vide(quad[idx].op2)) {
            strcpy(op2, quad[idx].op2);
            if (strchr(op2, '.')) *strchr(op2, '.') = '\0';
            if (strcmp(op2, "true") == 0) strcpy(op2, "TRUE");
            if (strcmp(op2, "false") == 0) strcpy(op2, "FALSE");
        }

        // Traiter res
        if (!is_vide(quad[idx].res)) {
            strcpy(res, quad[idx].res);
            if (strchr(res, '.')) *strchr(res, '.') = '\0';
        }

        // Fonction locale pour traiter les accès aux tableaux
        char* handle_array_access(char* var) {
            static char buffer[100];
            if (strstr(var, "[") != NULL) {
                char tmp_var[100];
                strcpy(tmp_var, var);
                
                char* name = strtok(tmp_var, "[");
                char* index = strtok(NULL, "]");
                
                fprintf(fichier, "    ; Accès au tableau %s avec index %s\n", name, index);
                fprintf(fichier, "    MOV AX, %s\n", index);
                fprintf(fichier, "    CMP AX, 0\n");
                fprintf(fichier, "    JL ERR_UNDERFLOW\n");
                
                // Get array size from symbol table
                int array_size = 0;
                for (int i = 0; i < idfTable->size; i++) {
                    ComplexElement* current = (ComplexElement*)idfTable->buckets[i];
                    while (current) {
                        if (strcmp(current->name, name) == 0) {
                            if (strstr(current->type, "[][") != NULL) {
                                array_size = (int)(i * j) - 1;
                            } else if (strstr(current->type, "[") != NULL) {
                                array_size = (int)taille - 1;
                            }
                            break;
                        }
                        current = current->next;
                    }
                }
                
                fprintf(fichier, "    CMP AX, %d\n", array_size);
                fprintf(fichier, "    JG ERR_OVERFLOW\n");
                
                fprintf(fichier, "    MOV BX, AX\n");
                fprintf(fichier, "    SHL BX, 1 ; Multiplier par 2 pour des mots\n");
                
                sprintf(buffer, "%s[BX]", name);
                return buffer;
            }
            return var;
        }
        
        // Appliquer la fonction aux opérandes si nécessaire
        if (strstr(op1, "[") != NULL) strcpy(op1, handle_array_access(op1));
        if (strstr(op2, "[") != NULL) strcpy(op2, handle_array_access(op2));
        if (strstr(res, "[") != NULL) strcpy(res, handle_array_access(res));
        #define IS_FLOAT(op) ((strchr((op), '.') != NULL) && !is_really_integer((op)))

        // Traduction des opérations
        // Affectation simple
        if (strcmp(quad[idx].oper, "=") == 0 && is_vide(quad[idx].op2)) {
            if (quad[idx].op1[0] == '"') {
                // Chaîne constante
            } else if (!is_vide(quad[idx].op1) && !is_vide(quad[idx].res)) {
                int is_float = IS_FLOAT(quad[idx].op1) || IS_FLOAT(quad[idx].res);
                
                if (isdigit(quad[idx].op1[0])) {
                    if (is_float) {
                        float val = strtof(quad[idx].op1, NULL);
                        fprintf(fichier, "    MOV AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                    } else {
                        int int_val = atoi(quad[idx].op1);
                        fprintf(fichier, "    MOV AX, %d\n", int_val);
                    }
                } else {
                    fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
                }
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
                
                // Affichage avec le bon type
                fprintf(fichier, "    LEA DX, MSG_RESULT\n");
                fprintf(fichier, "    MOV AH, 09h\n");
                fprintf(fichier, "    INT 21h\n");
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
                fprintf(fichier, "    %s\n", is_float ? "CALL PRINT_FLOAT" : "CALL PRINT_NUM");
                fprintf(fichier, "    CALL PRINT_NEWLINE\n");
            }
        }
        else if (strcmp(quad[idx].oper, "+") == 0) {
            int is_float = IS_FLOAT(quad[idx].op1) || IS_FLOAT(quad[idx].op2) || IS_FLOAT(quad[idx].res);
            
            fprintf(fichier, "    ; %s\n", is_float ? "Addition flottante" : "Addition entière");
            fprintf(fichier, "    MOV DX, OFFSET %s\n", is_float ? "MSG_ADD_FLOAT" : "MSG_ADD_INT");
            fprintf(fichier, "    CALL PRINT_MSG\n");
            
            // Chargement op1
            if (isdigit(quad[idx].op1[0])) {
                if (is_float) {
                    float val = strtof(quad[idx].op1, NULL);
                    fprintf(fichier, "    MOV AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                } else {
                    if (isdigit(quad[idx].op1[0])&&isdigit(quad[idx].op2[0])) {  // Si op2 est aussi une constante
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].op2);  // On charge op2
                    } else {
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);  // Sinon on charge res
                    }
                }
            } else {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            }
            
            // Addition op2
            if (!is_vide(quad[idx].op2)) {
                if (isdigit(quad[idx].op2[0])) {
                    if (is_float) {
                        float val = strtof(quad[idx].op2, NULL);
                        fprintf(fichier, "    ADD AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                    } else {
                        fprintf(fichier, "    ADD AX, %s\n", quad[idx].op1);
                    }
                } else {
                    fprintf(fichier, "    ADD AX, %s\n", quad[idx].op1);
                }
            }
            
            // Stockage résultat
            if (!is_vide(quad[idx].res)) {
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
            }
            
            // Affichage avec le bon type
            fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
            fprintf(fichier, "    %s\n", is_float ? "CALL PRINT_FLOAT" : "CALL PRINT_NUM");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        else if (strcmp(quad[idx].oper, "-") == 0) {
            int is_float = IS_FLOAT(quad[idx].op1) || IS_FLOAT(quad[idx].op2) || IS_FLOAT(quad[idx].res);
            
            fprintf(fichier, "    ; %s\n", is_float ? "Soustraction flottante" : "Soustraction entière");
            fprintf(fichier, "    MOV DX, OFFSET %s\n", is_float ? "MSG_SUB_FLOAT" : "MSG_SUB_INT");
            fprintf(fichier, "    CALL PRINT_MSG\n");
            
            // Chargement op1
            if (isdigit(quad[idx].op1[0])) {
                if (is_float) {
                    float val = strtof(quad[idx].op1, NULL);
                    fprintf(fichier, "    MOV AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                } else {
                    if (isdigit(quad[idx].op1[0])&&isdigit(quad[idx].op2[0])) {  // Si op2 est aussi une constante
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].op2);  // On charge op2
                    } else {
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);  // Sinon on charge res
                    }
                }
            } else {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            }
            
            // Soustraction op2
            if (!is_vide(quad[idx].op2)) {
                if (isdigit(quad[idx].op2[0])) {
                    if (is_float) {
                        float val = strtof(quad[idx].op2, NULL);
                        fprintf(fichier, "    SUB AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                    } else {
                        fprintf(fichier, "    SUB AX, %s\n", quad[idx].op1);
                    }
                } else {
                    fprintf(fichier, "    SUB AX, %s\n", quad[idx].op1);
                }
            }
            
            // Stockage résultat
            if (!is_vide(quad[idx].res)) {
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
            }
            
            // Affichage avec le bon type
            fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
            fprintf(fichier, "    %s\n", is_float ? "CALL PRINT_FLOAT" : "CALL PRINT_NUM");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        else if (strcmp(quad[idx].oper, "*") == 0) {
            int is_float = IS_FLOAT(quad[idx].op1) || IS_FLOAT(quad[idx].op2) || IS_FLOAT(quad[idx].res);
            
            fprintf(fichier, "    ; %s\n", is_float ? "Multiplication flottante" : "Multiplication entière");
            fprintf(fichier, "    MOV DX, OFFSET %s\n", is_float ? "MSG_MUL_FLOAT" : "MSG_MUL_INT");
            fprintf(fichier, "    CALL PRINT_MSG\n");
            
            // Chargement op1
            if (isdigit(quad[idx].op1[0])) {
                if (is_float) {
                    float val = strtof(quad[idx].op1, NULL);
                    fprintf(fichier, "    MOV AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                } else {
                    if (isdigit(quad[idx].op1[0])&&isdigit(quad[idx].op2[0])) {  // Si op2 est aussi une constante
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].op2);  // On charge op2
                    } else {
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);  // Sinon on charge res
                    }
                }
            } else {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            }
            
            // Multiplication op2
            if (!is_vide(quad[idx].op2)) {
                if (isdigit(quad[idx].op2[0])) {
                    if (is_float) {
                        float val = strtof(quad[idx].op2, NULL);
                        fprintf(fichier, "    MOV BX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                    } else {
                        fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                    }
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                }
                
                fprintf(fichier, "    IMUL BX\n");
                
                // Pour les flottants, on doit diviser par 10 (car on a multiplié deux nombres ×10)
                if (is_float) {
                    fprintf(fichier, "    MOV BX, 10\n");
                    fprintf(fichier, "    IDIV BX\n");
                }
            }
            
            // Stockage résultat
            if (!is_vide(quad[idx].res)) {
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
            }
            
            // Affichage avec le bon type
            fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
            fprintf(fichier, "    %s\n", is_float ? "CALL PRINT_FLOAT" : "CALL PRINT_NUM");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        else if (strcmp(quad[idx].oper, "/") == 0) {
            int is_float = IS_FLOAT(quad[idx].op1) || IS_FLOAT(quad[idx].op2) || IS_FLOAT(quad[idx].res);
            
            fprintf(fichier, "    ; %s\n", is_float ? "Division flottante" : "Division entière");
            fprintf(fichier, "    MOV DX, OFFSET %s\n", is_float ? "MSG_DIV_FLOAT" : "MSG_DIV_INT");
            fprintf(fichier, "    CALL PRINT_MSG\n");
            
            // Chargement op1
            if (isdigit(quad[idx].op1[0])) {
                if (is_float) {
                    float val = strtof(quad[idx].op1, NULL);
                    fprintf(fichier, "    MOV AX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                } else {
                    if (isdigit(quad[idx].op1[0])&&isdigit(quad[idx].op2[0])) {  // Si op2 est aussi une constante
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].op2);  // On charge op2
                    } else {
                        fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);  // Sinon on charge res
                    }
                }
            } else {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            }
            
            // Pour les flottants, multiplier par 10 avant division
            if (is_float) {
                fprintf(fichier, "    MOV BX, 10\n");
                fprintf(fichier, "    IMUL BX\n");
            }
            
            // Division par op2
            if (!is_vide(quad[idx].op2)) {
                fprintf(fichier, "    CMP %s, 0\n", quad[idx].op2);
                fprintf(fichier, "    JE DIV_ZERO\n");
                
                if (isdigit(quad[idx].op2[0])) {
                    if (is_float) {
                        float val = strtof(quad[idx].op2, NULL);
                        fprintf(fichier, "    MOV BX, %d     ; %.1f ×10\n", (int)round(val * 10), val);
                    } else {
                        fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                    }
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                }
                
                fprintf(fichier, "    CWD\n");  // Convertir AX en DX:AX pour la division
                fprintf(fichier, "    IDIV BX\n");
            }
            
            // Stockage résultat
            if (!is_vide(quad[idx].res)) {
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
            }
            
            // Affichage avec le bon type
            fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
            fprintf(fichier, "    %s\n", is_float ? "CALL PRINT_FLOAT" : "CALL PRINT_NUM");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        else if (strcmp(quad[idx].oper, "%") == 0) {
            // Modulo est toujours une opération entière
            fprintf(fichier, "    ; Modulo entier\n");
            fprintf(fichier, "    MOV DX, OFFSET MSG_MOD_INT\n");
            fprintf(fichier, "    CALL PRINT_MSG\n");
            
            // Chargement op1
            if (isdigit(quad[idx].op1[0])) {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", quad[idx].op1);
            }
            
            // Modulo par op2
            if (!is_vide(quad[idx].op2)) {
                fprintf(fichier, "    CMP %s, 0\n", quad[idx].op2);
                fprintf(fichier, "    JE DIV_ZERO\n");
                
                if (isdigit(quad[idx].op2[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", quad[idx].op1);
                }
                
                fprintf(fichier, "    CWD\n");  // Convertir AX en DX:AX pour la division
                fprintf(fichier, "    IDIV BX\n");
                fprintf(fichier, "    MOV AX, DX\n");  // Garder le reste
            }
            
            // Stockage résultat
            if (!is_vide(quad[idx].res)) {
                fprintf(fichier, "    MOV %s, AX\n", quad[idx].res);
            }
            
            // Affichage
            fprintf(fichier, "    MOV AX, %s\n", quad[idx].res);
            fprintf(fichier, "    CALL PRINT_NUM\n");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        // Sauts conditionnels
        else if (strcmp(quad[idx].oper, "BZ") == 0) {
            if (!is_vide(op2)) {
                if (isdigit(op2[0])) {
                    fprintf(fichier, "    MOV AX, %s\n", op2);
                } else {
                    fprintf(fichier, "    MOV AX, %s\n", op2);
                }
                fprintf(fichier, "    CMP AX, 0\n");
                fprintf(fichier, "    JE LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BNZ") == 0) {
            if (!is_vide(op2)) {
                if (isdigit(op2[0])) {
                    fprintf(fichier, "    MOV AX, %s\n", op2);
                } else {
                    fprintf(fichier, "    MOV AX, %s\n", op2);
                }
                fprintf(fichier, "    CMP AX, 0\n");
                fprintf(fichier, "    JNE LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BL") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JL LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BG") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JG LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BLE") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JLE LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BGE") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JGE LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BE") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JE LABEL_%d\n", atoi(op1));
            }
        }
        else if (strcmp(quad[idx].oper, "BNE") == 0) {
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op2);
            }
            if (!is_vide(res)) {
                if (isdigit(res[0])) {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                } else {
                    fprintf(fichier, "    MOV BX, %s\n", res);
                }
                fprintf(fichier, "    CMP AX, BX\n");
                fprintf(fichier, "    JNE LABEL_%d\n", atoi(op1));
            }
        }
        // Saut inconditionnel
        else if (strcmp(quad[idx].oper, "BR") == 0) {
            fprintf(fichier, "    JMP LABEL_%d\n", atoi(op1));
        }
        // Décrémentation
        else if (strcmp(quad[idx].oper, "ADEC") == 0) {
            if (isdigit(op1[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op1);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op1);
            }
            fprintf(fichier, "    DEC AX\n");
            if (!is_vide(res)) {
                fprintf(fichier, "    MOV %s, AX\n", res);
            } else {
                fprintf(fichier, "    MOV %s, AX\n", op1); // Store back in original variable if no res
            }
            fprintf(fichier, "    LEA DX, MSG_RESULT\n");
            fprintf(fichier, "    MOV AH, 09h\n");
            fprintf(fichier, "    INT 21h\n");
            fprintf(fichier, "    MOV AX, %s\n", res);
            fprintf(fichier, "    CALL PRINT_NUM\n");
            fprintf(fichier, "    CALL PRINT_NEWLINE\n");
        }
        // Vérification des bornes
        else if (strcmp(quad[idx].oper, "BOUNDS") == 0) {
            fprintf(fichier, "    ; Vérification des bornes\n");
            if (isdigit(op1[0])) {
                fprintf(fichier, "    MOV AX, %s\n", op1);
            } else {
                fprintf(fichier, "    MOV AX, %s\n", op1);
            }
            fprintf(fichier, "    CMP AX, 0\n");
            fprintf(fichier, "    JL ERR_UNDERFLOW\n");
            if (isdigit(op2[0])) {
                fprintf(fichier, "    MOV BX, %s\n", op2);
            } else {
                fprintf(fichier, "    MOV BX, %s\n", op2);
            }
            fprintf(fichier, "    CMP AX, BX\n");
            fprintf(fichier, "    JG ERR_OVERFLOW\n");
        }

        fprintf(fichier, "\n");
    }

    // Ensure all referenced labels are defined (even if not in the original quads)
    for (int idx = 0; idx < qc; idx++) {
        if (quad[idx].oper[0] == 'B' && strlen(quad[idx].oper) > 1) {
            int target = atoi(quad[idx].op1);
            if (target >= 0 && target < 10000 && !labels[target]) {
                fprintf(fichier, "LABEL_%d:\n", target);
                labels[target] = 1; // Mark as defined
            }
        }
    }



    fprintf(fichier, "    JMP FIN\n\n");
    // Gestion des erreurs
    fprintf(fichier, "ERR_UNDERFLOW:\n");
    fprintf(fichier, "    LEA DX, ERR_UNDERFLOW_MSG\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    JMP FIN\n");

    fprintf(fichier, "ERR_OVERFLOW:\n");
    fprintf(fichier, "    LEA DX, ERR_OVERFLOW_MSG\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    JMP FIN\n");

    fprintf(fichier, "DIV_ZERO:\n");
    fprintf(fichier, "    LEA DX, DIV_ZERO_MSG\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    JMP FIN\n");

    // Fin du programme
    fprintf(fichier, "FIN:\n");
    fprintf(fichier, "    MOV AH, 4Ch\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "MAIN ENDP\n\n");


    // Ajouter les nouvelles procédures d'affichage à la fin
    fprintf(fichier, "\n; ======================================\n");
    fprintf(fichier, "; SOUS-PROGRAMMES D'AFFICHAGE\n");
    fprintf(fichier, "; ======================================\n");
    
    fprintf(fichier, "PRINT_MSG PROC NEAR\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_MSG ENDP\n\n");
    
    fprintf(fichier, "PRINT_NUM PROC NEAR\n");
    fprintf(fichier, "    PUSH BX\n");
    fprintf(fichier, "    PUSH CX\n");
    fprintf(fichier, "    PUSH DX\n");
    fprintf(fichier, "    MOV BX, 10\n");
    fprintf(fichier, "    XOR CX, CX\n");
    fprintf(fichier, "    TEST AX, AX\n");
    fprintf(fichier, "    JNZ CONVERT_LOOP\n");
    fprintf(fichier, "    MOV DL, '0'\n");
    fprintf(fichier, "    MOV AH, 02h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    JMP END_PRINT\n");
    fprintf(fichier, "CONVERT_LOOP:\n");
    fprintf(fichier, "    XOR DX, DX\n");
    fprintf(fichier, "    DIV BX\n");
    fprintf(fichier, "    PUSH DX\n");
    fprintf(fichier, "    INC CX\n");
    fprintf(fichier, "    TEST AX, AX\n");
    fprintf(fichier, "    JNZ CONVERT_LOOP\n");
    fprintf(fichier, "PRINT_LOOP:\n");
    fprintf(fichier, "    POP DX\n");
    fprintf(fichier, "    ADD DL, '0'\n");
    fprintf(fichier, "    MOV AH, 02h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    LOOP PRINT_LOOP\n");
    fprintf(fichier, "END_PRINT:\n");
    fprintf(fichier, "    POP DX\n");
    fprintf(fichier, "    POP CX\n");
    fprintf(fichier, "    POP BX\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_NUM ENDP\n\n");
    
    fprintf(fichier, "PRINT_FLOAT PROC NEAR\n");
    fprintf(fichier, "    PUSH BX\n");
    fprintf(fichier, "    PUSH CX\n");
    fprintf(fichier, "    PUSH DX\n");
    fprintf(fichier, "    ; Diviser par 10 pour séparer partie entière et décimale\n");
    fprintf(fichier, "    MOV BX, 10\n");
    fprintf(fichier, "    XOR DX, DX        ; Clear DX for division\n");
    fprintf(fichier, "    DIV BX            ; AX = partie entière, DX = partie décimale\n");
    fprintf(fichier, "    MOV INT_PART, AX  ; Stocke la partie entière (16 bits)\n");
    fprintf(fichier, "    MOV DEC_PART, DL  ; Stocke la partie décimale\n");
    fprintf(fichier, "    ; Afficher partie entière (16 bits)\n");
    fprintf(fichier, "    MOV AX, INT_PART\n");
    fprintf(fichier, "    CALL PRINT_NUM\n");
    fprintf(fichier, "    ; Afficher point décimal\n");
    fprintf(fichier, "    MOV DL, '.'\n");
    fprintf(fichier, "    MOV AH, 02h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    ; Afficher partie décimale\n");
    fprintf(fichier, "    MOV AL, DEC_PART\n");
    fprintf(fichier, "    CALL PRINT_SINGLE_DIGIT\n");
    fprintf(fichier, "    POP DX\n");
    fprintf(fichier, "    POP CX\n");
    fprintf(fichier, "    POP BX\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_FLOAT ENDP\n\n");
    
    fprintf(fichier, "PRINT_SINGLE_DIGIT PROC NEAR\n");
    fprintf(fichier, "    ADD AL, '0'\n");
    fprintf(fichier, "    MOV DL, AL\n");
    fprintf(fichier, "    MOV AH, 02h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_SINGLE_DIGIT ENDP\n\n");
    
    fprintf(fichier, "PRINT_NEWLINE PROC NEAR\n");
    fprintf(fichier, "    PUSH AX\n");
    fprintf(fichier, "    PUSH DX\n");
    fprintf(fichier, "    LEA DX, NEWLINE\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    POP DX\n");
    fprintf(fichier, "    POP AX\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_NEWLINE ENDP\n\n");
    
    fprintf(fichier, "PRINT_RESULT PROC NEAR\n");
    fprintf(fichier, "    PUSH AX\n");
    fprintf(fichier, "    PUSH DX\n");
    fprintf(fichier, "    LEA DX, MSG_RESULT\n");
    fprintf(fichier, "    MOV AH, 09h\n");
    fprintf(fichier, "    INT 21h\n");
    fprintf(fichier, "    POP DX\n");
    fprintf(fichier, "    POP AX\n");
    fprintf(fichier, "    ; Détection automatique du type\n");
    fprintf(fichier, "    CMP DX, 0\n");
    fprintf(fichier, "    JE PRINT_INT\n");
    fprintf(fichier, "    CALL PRINT_FLOAT\n");
    fprintf(fichier, "    JMP PRINT_END\n");
    fprintf(fichier, "PRINT_INT:\n");
    fprintf(fichier, "    CALL PRINT_NUM\n");
    fprintf(fichier, "PRINT_END:\n");
    fprintf(fichier, "    CALL PRINT_NEWLINE\n");
    fprintf(fichier, "    RET\n");
    fprintf(fichier, "PRINT_RESULT ENDP\n\n");
    
    fprintf(fichier, "END MAIN\n");

    fclose(fichier);
    printf("Fichier assembleur généré avec succès: %s\n", nom_fichier);
}