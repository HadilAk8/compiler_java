%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include<stdbool.h>
    #include <math.h>
    #include"ts.h"
    #include"quad.h" 
    int nb_ligne = 1;
    int Col = 1;
    char save_type[50]; 
     char nom_fonction[50]; 
    char typeAffTable[50];
    float taille, i, j, n; // Variables pour la gestion des tableaux et matrices
    char nom_variable[50]; 
    char type_retour_methode[50]; // Stocke le type de retour de la méthode courante
    char loop_var[100]; // Variable globale pour stocker le nom de la variable de boucle for
    char tmp_name[100] = "";         // Pour les noms de la var dans la condition while
    char tmp_compare_value[100] = "";  // Pour stocker la valeur de comparaison while
    char tmp_name_dowhile[100] = "";         // Pour les noms de la var dans la condition dowhile
    char tmp_compare_value_dowhile[100] = "";  // Pour stocker la valeur de comparaison dowhile
    char tmp [20] , tm[20];
    char tmp1 [20] , tmp2[20] , tmpb [20];
    int fin_if = 0 ,fin_ifelse = 0 , deb_else = 0 , deb_dowhile = 0 , deb_for = 0 , qnt = 0 , jump = 0;
    extern int qc;
    char* factor_names[100];
    int factor_index = 0;
    int boolc = -1 , t = 0; // 0 false 1 true 
    int qc_save[100];
    int qc_index = 0;
    int jump_save[100];
    int jump_index = 0;
    // Déclaration des tables de symboles
    SymbolTable* idfTable;
    SymbolTable* separatorTable;
    SymbolTable* keywordTable;
    int yylex();  
    void yyerror(const char *msg) {
        fprintf(stderr, "Erreur syntaxique à la ligne %d, colonne %d: %s\n", nb_ligne, Col, msg);
    }
%}

%union {
    int entier;
    char *str;
    float reel;
}

%token <str>mc_int <str>mc_float <str>mc_boolean <str>mc_double mc_return mc_out <str>idf <reel>real  <entier>integer <str>chaine <str>mc_char mc_class mc_print mc_system  
mc_void mc_do mc_while mc_for mc_if mc_else mc_switch mc_break mc_case mc_default mc_try mc_catch mc_finally mc_final
mc_elseif mc_extends mc_public mc_private mc_protected mc_static <str>logic mc_new mc_this mc_throws mc_exception
mc_string mc_args mc_and mc_or mc_neq mc_eq mc_le mc_ge mc_arithmetic_exception mc_throw
mc_println

%start S
%left mc_or
%left mc_and
%left '!' 
%left '>' '<' '=' mc_eq mc_neq mc_le mc_ge
%left '+' '-'
%left '*' '/' '%'

%type <str>SPDEC
%type <str> TYPE
%type <reel> NUMB
%type <reel> EXPRESSION
%type <reel> LOGICAL_AND
%type <reel> LOGICAL_OR
%type <reel> RELATIONAL
%type <reel> TERM
%type <reel> FACTOR
%type <reel> ADDITIVE
%type <entier> A
%type <str> EXPRESSIONS
%type <reel> OBJFUN
%type <str> AFFTABLE

%debug
%error-verbose
%%

S: CLASSES {
        printf("Syntaxe correcte\n");
        YYACCEPT;
    };

CLASSES : CLASS CLASSES | CLASS ;

CLASS : PUBLIC mc_class idf '{' {
            if (estDeclare(idfTable, $3)) {
                printf("Erreur sémantique : Double déclaration de la classe '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $3, "IDF", "class", 0.0);
                pushScope($3); // Empiler la portée de la classe
            }
        } MULTIBLOCKS '}' {
            popScope(); // Sortie de la portée de la classe
        };
      
      | PUBLIC mc_class idf mc_extends idf '{' {
            if (estDeclare(idfTable, $3)) {
                printf("Erreur sémantique : Double déclaration de la classe '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $3, "IDF", "class", 0.0);
                pushScope($3);
            }
            if (!estDeclare(idfTable, $5)) {
                printf("Erreur sémantique : La classe parent '%s' n'est pas déclarée (ligne %d, colonne %d)\n", $5, nb_ligne, Col);
            }
        } MULTIBLOCKS '}' {
            popScope();
        };

PUBLIC : mc_public | ;

MULTIBLOCKS : BLOCKS MULTIBLOCKS | BLOCKS | CONSTRUCTOR MULTIBLOCKS | CONSTRUCTOR ;

BLOCKS : DEC | METHODE | CSTDEC;

CSTDEC : mc_final TYPE idf '=' NUMB ';' {
        if (estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            if (strcmp(save_type, "int") != 0 && strcmp(save_type, "float") != 0 && strcmp(save_type, "double") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu nombre) (ligne %d, colonne %d)\n", 
                       $3, save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $3, "CST", save_type, 0.0);
                float valeur = $5;
                maj_valeur(idfTable, $3, &valeur);
                sprintf(tmp, "%f", $5);
                quadr("=", tmp, "vide", $3);
                   }
                }
        }
    
    | mc_final TYPE idf '=' chaine ';' {
        if (estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            if (strcmp(save_type, "String") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu chaîne) (ligne %d, colonne %d)\n", 
                       $3, save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $3, "CST", save_type, 0.0);
                quadr("=", $5, "vide", $3);
            }
        }
    }
    
    | mc_final TYPE idf '=' logic ';' {
        if (estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       $3, save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $3, "CST", save_type, 0.0);
                float valeur = (strcmp($5, "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, $3, &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", $3);
            }
        }
    };



METHODE : TYPE idf '(' {
    if (estDeclareDansaportee(idfTable, $2)) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, $1);
        strcpy(nom_fonction, $2); // <<< ici on stocke le nom de la méthode
        insertComplex(idfTable, $2, "METH", type_retour_methode, 0.0);
        pushScope($2);
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", $2, nb_ligne);
    }
} ARGUMENT ')' THROWS '{' MULTIINST RETURN ';' '}' {
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", $2, nb_ligne);
    popScope();
};


       | mc_void idf '(' {
    if (estDeclareDansaportee(idfTable, $2)) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, "void");  // Sauvegarde du type de retour "void"
        insertComplex(idfTable, $2, "METH", "void", 0.0);
        pushScope($2);  // 🔹 Empiler la portée AVANT d'ajouter les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", $2, nb_ligne);
    }
} ARGUMENT ')' THROWS '{' MULTIINST '}' {  // Pas de RETURN pour void
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", $2, nb_ligne);
    popScope();
}



 | MODIFIERS TYPE idf '(' {
    if (estDeclareDansaportee(idfTable, $3)) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, $2);  // Sauvegarde du type de retour
        insertComplex(idfTable, $3, "METH", type_retour_methode, 0.0);
        pushScope($3);  // Empilage AVANT d'insérer les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", $3, nb_ligne);
    }
} ARGUMENT ')' THROWS '{' MULTIINST RETURN ';' '}' {
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", $3, nb_ligne);
    popScope();
}

| MODIFIERS mc_void idf '(' {
    if (estDeclareDansaportee(idfTable, $3)) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, "void");
        insertComplex(idfTable, $3, "METH", "void", 0.0);
        pushScope($3);  //  Empiler la portée AVANT d'ajouter les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", $3, nb_ligne);
    }
} ARGUMENT ')' THROWS '{' MULTIINST '}' {  // Pas de RETURN pour void
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", $3, nb_ligne);
    popScope();
};

CONSTRUCTOR : idf '(' ARGUMENT ')' '{' {
        if (strcmp($1, getCurrentScope()) != 0) {
            printf("Erreur sémantique : Le constructeur '%s' ne correspond pas au nom de la classe '%s' (ligne %d, colonne %d)\n",
                   $1, getCurrentScope(), nb_ligne, Col);
        }
        pushScope($1); // Entrée dans la portée du constructeur
    } MULTISPDEC '}' {
        popScope(); // Sortie de la portée du constructeur
    };


MULTISPDEC : SPDEC ';' MULTISPDEC | SPDEC ';';

SPDEC : idf '=' idf {
        float val;
        char type1[50], type2[50];

        if (estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $1));
                strcpy(type2, get_type(idfTable, $3));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                }
                get_val(idfTable, $3, &val);
                maj_valeur(idfTable, $1, &val);
            }
        }
        quadr("=",$3,"vide",$1);
    }
    | idf '=' NUMB {
        float val = (float)$3;
        char type1[50];

        if (!estDeclareDansaportee(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $1));
                
                if (strcmp(type1, "float") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et 'float' (ligne %d, colonne %d)\n", type1, nb_ligne, Col);
                }
                maj_valeur(idfTable, $1, &val);
            }
        }
        sprintf(tmp,"%f",$3);
        quadr("=",tmp,"vide",$1);
    }
    | idf '=' chaine { 
     char type1[50];
        if (!estDeclareDansaportee(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $1));
                
                if (strcmp(type1, "String") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type (ligne %d, colonne %d)\n", nb_ligne, Col);
                }
                
            }
        }
        quadr("=",$3,"vide",$1);
    }
    | TYPE idf '=' idf { 
        float val;
        char type1[50], type2[50];

        if (estDeclareDansaportee(idfTable, $2)) {
            printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
        } else {
            insertComplex(idfTable, $2, "IDF", save_type, 0.0);
            maj_type(idfTable, $2, save_type);
        }

        if (!estDeclareDansaportee(idfTable, $4)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $4, nb_ligne, Col);
        } else {
            if (strcmp(get_codeentite(idfTable, $2), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $2));
                strcpy(type2, get_type(idfTable, $4));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                }
                get_val(idfTable, $4, &val);
                maj_valeur(idfTable, $2, &val);
            }
        }
        quadr("=",$4,"vide",$2);
    }
    | TYPE idf '=' chaine {
        char type1[50];  
        if (strcmp(get_codeentite(idfTable, $2), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
            }
        else {insertComplex(idfTable, $2, "IDF", save_type, 0.0);
        maj_type(idfTable, $2, save_type);
        
     }
        quadr("=",$4,"vide",$2);
    }
    | TYPE idf '=' NUMB {
        float val = (float)$4;
        char type1[50];  
     if (strcmp(get_codeentite(idfTable, $2), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
            }
        else {insertComplex(idfTable, $2, "IDF", save_type, 0.0);
        maj_type(idfTable, $2, save_type);    
        maj_valeur(idfTable, $2, &val);}
        sprintf(tmp,"%f",$4);
        quadr("=",tmp,"vide",$2);
    }
    | mc_this'.'idf '=' idf {   
        float val;
        char type1[50], type2[50];
        if (!estDeclareDansaportee(idfTable, $5)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $5, nb_ligne, Col);
        }
        else {
             if (estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
             if (strcmp(get_codeentite(idfTable, $3), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            }
        } else { 
            strcpy(type1, get_type(idfTable, $5));
                strcpy(type2, get_type(idfTable, $3));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                } else{
                get_val(idfTable, $5, &val);
                maj_valeur(idfTable, $3, &val);}
        }
        }
        quadr("=",$5,"vide",$3);
    }
    
    | mc_this'.'idf '=' chaine {  
         char type1[50];
         if (!estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            
            if (strcmp(get_codeentite(idfTable, $3), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $3));
                
                if (strcmp(type1, "String") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type (ligne %d, colonne %d)\n", nb_ligne, Col);
                }
                
            }
        }
        quadr("=",$5,"vide",$3); 
        }

    | mc_this'.'idf '=' NUMB    { 
        float val = (float)$5;
        char type1[50];

        if (!estDeclareDansaportee(idfTable, $3)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
        } else {
            
            if (strcmp(get_codeentite(idfTable, $3), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, $3));
                
                if (strcmp(type1, "float") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et 'float' (ligne %d, colonne %d)\n", type1, nb_ligne, Col);
                }
                maj_valeur(idfTable, $3, &val);
            }
        }
        
        sprintf(tmp,"%f",$5);
        quadr("=",tmp,"vide",$3);  };

MULTIINST : INST MULTIINST | INST ;

INST : OUTPUT 
     | AFF ';'
     | DEC 
     | FUN 
     | OBJFUN ';' 
     | NEWTHROW 
     | TABLES
     | CSTDEC;

TABLES : TYPE '['']' idf ';' {
            if (estDeclareDansaportee(idfTable, $4)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $4, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $4, "IDF", save_type, 0.0);
                maj_type(idfTable, $4, save_type);
            }
            quadr("ADEC",$4,"vide","vide");
        }
       |TYPE '['']''['']' idf ';' {
            if (estDeclareDansaportee(idfTable, $6)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $6, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $6, "IDF", save_type, 0.0);
                maj_type(idfTable, $6, save_type);
            }
        }
       | idf '=' mc_new TYPE INTMATRIX ';' {
            char typeExist[50];
            if (!estDeclare(idfTable, $1)) {
                printf("Erreur : Utilisation de la matrice non déclarée '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                strcpy(typeExist, get_type(idfTable, $1));
                if (strcmp(typeExist, save_type) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", typeExist, save_type, nb_ligne, Col);
                } else {
                    maj_type(idfTable, $1, save_type);
                }
            }
        }

       | TYPE '['']' idf '=' mc_new TYPE INTMATRIX ';' {
            if (estDeclareDansaportee(idfTable, $4)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $4, nb_ligne, Col);
            } else {
                if (strcmp($1, $7) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", $1, $6, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, $4, "IDF", save_type, 0.0);
                }
            }
            quadr("ADEC",$4,"vide","vide");
        }
       | TYPE '['']''['']' idf '=' mc_new TYPE INTMATRIX ';' {
            if (estDeclareDansaportee(idfTable, $6)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $6, nb_ligne, Col);
            } else {
                if (strcmp($1, $9) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", $1, $6, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, $6, "IDF", save_type, 0.0);
                }
            }
            quadr("ADEC",$6,"vide","vide");
        }
       | TYPE '['']' idf '=' '{' VALUES '}' ';' {
            if (estDeclareDansaportee(idfTable, $4)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $4, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $4, "IDF", save_type, 0.0);
                maj_type(idfTable, $4, save_type);
            }
            quadr("ADEC",$4,"vide","vide");
        };
        | TYPE '['']''['']' idf '=' '{' VALUES '}' ';' {
            if (estDeclareDansaportee(idfTable, $6)) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", $6, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $6, "IDF", save_type, 0.0);
                maj_type(idfTable, $6, save_type);
            }
            quadr("ADEC",$6,"vide","vide");
        };
INTMATRIX : '['integer']' {
                taille = $2;  
                sprintf(tmp,"%f",taille);
                quadr("BOUNDS","0",tmp,"vide");
            }
          | '['idf']' {
                if (!estDeclare(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée en dehors de sa portée (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, $2));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour définir la taille de la matrice (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                    } else {
                        get_val(idfTable, $2, &taille);
                        sprintf(tmp,"%f",taille);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            }
          | '['integer']' '['integer']' {
                i = $2;
                j = $5;
                sprintf(tmp,"%f",i);
                quadr("BOUNDS","0",tmp,"vide");
                sprintf(tmp,"%f",j);
                quadr("BOUNDS","0",tmp,"vide");
            }
          | '['idf']' '['integer']' {
                if (!estDeclare(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée en dehors de sa portée (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, $2));
                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour définir la taille de la matrice (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                    } else {
                        get_val(idfTable, $2, &i);
                        j = $5;
                        sprintf(tmp,"%f",i);
                        quadr("BOUNDS","0",tmp,"vide");
                        sprintf(tmp,"%f",j);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            }
          | '['idf']' '['idf']' {
                if (!estDeclare(idfTable, $2) || !estDeclare(idfTable, $5)) {
                    printf("Erreur : variable utilisée comme indice mais non déclarées (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, $2) || !estDeclareDansaportee(idfTable, $5)) {
                    printf("Erreur :variable utilisée comme indice en dehors de leur portée (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else {
                    char typeVar1[50], typeVar2[50];
                    strcpy(typeVar1, get_type(idfTable, $2));
                    strcpy(typeVar2, get_type(idfTable, $5));

                    if (strcmp(typeVar1, "int") != 0 || strcmp(typeVar2, "int") != 0) {
                        printf("Erreur sémantique : '%s' et '%s' doivent être des entiers pour définir la taille de la matrice (ligne %d, colonne %d)\n", $2, $5, nb_ligne, Col);
                    } else {
                        get_val(idfTable, $2, &i);
                        get_val(idfTable, $5, &j);
                        sprintf(tmp,"%f",i);
                        quadr("BOUNDS","0",tmp,"vide");
                        sprintf(tmp,"%f",j);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            };
VALUES : MULTIVALUE | VALUE ;

MULTIVALUE : '{' VALUE '}' ',' MULTIVALUE  
           | '{' VALUE '}' ;

VALUE : NUMB ',' VALUE 
      | NUMB {   
            char typeVal[50];
            strcpy(typeVal, save_type); // Récupération du type attendu

            // Debug : affichage du type attendu et de la valeur fournie
            printf("[DEBUG] Type attendu : %s, Valeur fournie : %f (ligne %d, colonne %d)\n", typeVal, $1, nb_ligne, Col);

            // Cas où le type attendu est float mais que la valeur est un entier (aucune erreur en Java, mais avertissement)
            if (strcmp(typeVal, "float") == 0 && (int)$1 == $1) {
                printf("[AVERTISSEMENT] La valeur entière '%d' est affectée à un type '%s' (ligne %d, colonne %d)\n", (int)$1, typeVal, nb_ligne, Col);
            } 
            // Cas où le type attendu est int mais que la valeur est un float avec une partie décimale
            else if (strcmp(typeVal, "int") == 0 && (float)$1 != (int)$1) {
                printf("[ERREUR] La valeur '%f' ne peut pas être affectée à un type '%s' (ligne %d, colonne %d)\n", $1, typeVal, nb_ligne, Col);
            } 
            // Cas où le type attendu est boolean mais que la valeur est différente de 0 ou 1
            else if (strcmp(typeVal, "boolean") == 0 && ($1 != 0 && $1 != 1)) {
                printf("[ERREUR] La valeur '%f' est invalide pour un type '%s' (ligne %d, colonne %d)\n", $1, typeVal, nb_ligne, Col);
            } 
            else {
                printf("[DEBUG] Affectation correcte : Type '%s' avec valeur '%f'\n", typeVal, $1);
            }
        }
      |  chaine ',' VALUE 
      | chaine ;

NEWTHROW : mc_throw mc_new mc_arithmetic_exception '(' chaine ')' ';'
         | mc_throw mc_new mc_arithmetic_exception '('')' ';';

OUTPUT : mc_system'.'mc_out'.'mc_print'(' MESSEGE ')' ';'
       | mc_system'.'mc_out'.'mc_println'(' MESSEGE ')' ';';

MESSEGE : chaine '+' MESSEGE 
        | idf '+' MESSEGE {
            if (!estDeclareDansaportee(idfTable,$1)) {
                printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            }
        }
        | integer '+' MESSEGE 
        | real '+' MESSEGE
        | OBJFUN '+' MESSEGE
        | AFFTABLE '+' MESSEGE
        | chaine 
        | idf {
            if (!estDeclareDansaportee(idfTable,$1)) {
                printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            }
        }
        | integer 
        | real 
        | OBJFUN 
        | AFFTABLE 
        | ;

AFF : 
    idf '=' chaine {
        if (!estDeclare(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        }
        if (!estDeclareDansaportee(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        }

        // Vérification si $1 est une constante
        if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
            printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        } else {
            char typeVar[50];
            strcpy(typeVar, get_type(idfTable, $1));
            if (strcmp(typeVar, "String") != 0) {
                printf("Erreur sémantique : Incompatibilité de type. '%s' est de type '%s' mais reçoit une chaîne (ligne %d, colonne %d)\n", $1, typeVar, nb_ligne, Col);
            } else { 
                   strcpy(nom_variable, $1);  
            }
        }
        quadr("=", $3,"vide",$1);
    }

    | idf '=' EXPRESSION {   
        if (!estDeclare(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        }
        if (!estDeclareDansaportee(idfTable, $1)) {
            printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        }

        // Vérification si $1 est une constante
        if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
            printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
        }  maj_valeur(idfTable, $1, &$3);
        if(boolc==-1){
            quadr("=",factor_names[--factor_index],"vide",$1);
        }else{
            if(boolc==0){
                quadr("=","FALSE","vide",$1);
            }else{
                quadr("=","TRUE","vide",$1);
            }
            boolc = -1;
        }
        
    }

    | idf idf '=' mc_new idf '(' ARG ')' {
        if (estDeclareDansaportee(idfTable, $2)) {
            printf("Erreur : Double déclaration de l'argument '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
        } else {
             if (!estDeclareDansaportee(idfTable, $1)) {
             printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);}
             else{
            insertComplex(idfTable, (char*)$2, "IDF", save_type, 0.0);
            maj_type(idfTable, (char*)$2, $1); }
        }
        quadr("new",$5,"vide","Tm");
        quadr("=","Tm","vide", $2);
    }

    | idf idf '=' OBJFUN {
        if (estDeclareDansaportee(idfTable, $2)) {
            printf("Erreur : Double déclaration de l'argument '%s' (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
        } else { if (!estDeclareDansaportee(idfTable, $1)) {
             printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);}
             else{
            insertComplex(idfTable, (char*)$2, "IDF", save_type, 0.0);
            maj_type(idfTable, (char*)$2, $1);}
        }
    }
       | idf '=' idf DINTMATRIX  {
    if (!estDeclareDansaportee(idfTable, $1)) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    } if (!estDeclareDansaportee(idfTable, $3)) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    }
     else {
        char* typeGauche = get_type(idfTable, $1);   // type de la variable
        char* typeDroit = get_type(idfTable, $3);              // type de la case du tableau récupéré via AFFTABLE

        if (strcmp(typeGauche, typeDroit) != 0) {
            printf("Erreur sémantique : Incompatibilité de type. '%s' est de type '%s' mais reçoit un '%s' (ligne %d, colonne %d)\n",
                $1, typeGauche, typeDroit, nb_ligne, Col);
        } else {
            strcpy(nom_variable, $1);
        strcat(tmp,tmp1);
        quadr("=",tmp,"vide",$1); }
    }
}
    
    | AFFTABLE '=' NUMB
  {
         // Vérifie si typeAffTable est bien compatible avec un float
    if (strcmp(typeAffTable, "float") != 0 && strcmp(typeAffTable, "int") != 0) {
        printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit une valeur réelle (ligne %d, colonne %d)\n",
               $1, typeAffTable, nb_ligne, Col);
    } else {
        strcat(tmp,tmp1);
        sprintf(tmp2,"%f",$3);
        quadr("=",tmp2,"vide",tmp);
    }}

    | AFFTABLE '=' chaine{
    if (strcmp(typeAffTable, "String") != 0) {
        printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit une chaîne (ligne %d, colonne %d)\n",
               $1, typeAffTable, nb_ligne, Col);
    } else { //strcat(tmp,tmp1);
        quadr("=", $3, "vide", tmp);
    }
}

    | idf '+' '+' {
    if (!estDeclareDansaportee(idfTable, $1)) {
        printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    } else if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
        printf("Erreur : Tentative d'incrémentation de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    } else {
        float valeur = 0.0;
        get_val(idfTable, $1, &valeur); // Récupération de la valeur actuelle
        valeur += 1; // Incrémentation
        maj_valeur(idfTable, $1, &valeur); // Mise à jour dans la table des symboles
        printf("Mise à jour de '%s' : Nouvelle valeur = %f\n", $1, valeur);
    }
    strcpy(nom_variable, $1); // Sauvegarde avant modification
    quadr("+","1",$1,$1);
}
| AFFTABLE '=' idf {
    if (!estDeclareDansaportee(idfTable, $3)) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
    } else {
        char* type_droit = get_type(idfTable, $3);

        if (strcmp(typeAffTable, type_droit) != 0) {
            printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit un '%s' (ligne %d, colonne %d)\n",
                   $1, typeAffTable, type_droit, nb_ligne, Col);
        } else { strcat(tmp,tmp1);
            quadr("=", $3, "vide", tmp);
        }  
    }
}
| idf '-' '-' {
    if (!estDeclareDansaportee(idfTable, $1)) {
        printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    } else if (strcmp(get_codeentite(idfTable, $1), "CST") == 0) {
        printf("Erreur : Tentative de décrémentation de la constante '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    } else {
        float valeur = 0.0;
        get_val(idfTable, $1, &valeur); // Récupération de la valeur actuelle
        valeur -= 1; // Décrémentation
        maj_valeur(idfTable, $1, &valeur); // Mise à jour dans la table des symboles
        printf("Mise à jour de '%s' : Nouvelle valeur = %f\n", $1, valeur);
    }
    strcpy(nom_variable, $1); // Sauvegarde avant modification
    quadr("-",$1,"1",$1);
};

ARG : NUMB ',' ARG 
    | NUMB
    |chaine ',' ARG 
    | chaine
    | ;

FUN : BOUCLE | CONDIF | SWITCH | TRY;

BOUCLE : DOWHILE | FOR | WHILE;

DOWHILE : ADOWHILE'{' MULTIINST '}' mc_while '(' EXPRESSIONS ')' ';'{
    sprintf(tmp, "%d",deb_dowhile);
    quadr("BNE", tmp, tmp_name, tmp_compare_value);
    // Réinitialisation
    tmp_name[0] = '\0';
    tmp_compare_value[0] = '\0';
    };
ADOWHILE : mc_do { deb_dowhile = qc ;};

FOR : AFOR '{' MULTIINST '}' {
    // On génère d'abord le saut inconditionnel vers le début de la condition
    sprintf(tmp1, "%d", qc_save[qc_index - 1]);  // adresse début condition
    quadr("BR", tmp1, "vide", "vide");
    qc_index--;  // on décrémente après utilisation

    // On met à jour la branche conditionnelle pour sauter après la boucle (adresse de sortie)
    sprintf(tmp1, "%d", qc);
    updateQuad(jump_save[--jump_index], 1, tmp1);
};
AFOR : BFOR CONDFOR ';' INCDEC ')';
BFOR : mc_for '(' FORTYPE A ';' {
    qc_save[qc_index++] = qc;
} ;
A : idf '=' integer {
            if (estDeclareDansaportee(idfTable, $1)) {
                //printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $1, "IDF", "int", 0.0);
                maj_type(idfTable, $1, "int");
                float val = $3;
                maj_valeur(idfTable, $1, &val);
                $$ = $3;
            }
            strcpy(loop_var, $1); // Stocke le nom de la variable de boucle
            sprintf(tmp,"%d",$3);
            quadr("=",tmp,"vide",$1);
};
FORTYPE : TYPE | ;
CONDFOR :
    idf '<' idf {
        if(strcmp($1, loop_var) != 0 && strcmp($3, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BLE en BG pour la sortie de boucle
        quadr("BG", "", $1, $3);
    }
  | idf '>' idf {
        if(strcmp($1, loop_var) != 0 && strcmp($3, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BG en BL
        quadr("BL", "", $1, $3);
    }
  | idf mc_le idf {
        if(strcmp($1, loop_var) != 0 && strcmp($3, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BLE en BG
        quadr("BG", "", $1, $3);
    }
  | idf mc_ge idf {
        if(strcmp($1, loop_var) != 0 && strcmp($3, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BGE en BL
        quadr("BL", "", $1, $3);
    }
  // Pareil pour les versions avec nombre (NUMB)
  | idf '<' NUMB {
        if(strcmp($1, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", $3);
        jump_save[jump_index++] = qc;
        quadr("BG", "", $1, numStr);
    }
  | idf '>' NUMB {
        if(strcmp($1, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", $3);
        jump_save[jump_index++] = qc;
        quadr("BL", "", $1, numStr);
    }
  | idf mc_le NUMB {
        if(strcmp($1, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", $3);
        jump_save[jump_index++] = qc;
        quadr("BG", "", $1, numStr);
    }
  | idf mc_ge NUMB {
        if(strcmp($1, loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", $3);
        jump_save[jump_index++] = qc;
        quadr("BL", "", $1, numStr);
    }
;



INCDEC : idf '+' '+' {
    if(strcmp($1, loop_var) != 0) {
        printf("Erreur ligne %d: L'incrémentation doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
        yyerror("Erreur de variable de boucle");
        YYERROR;
    }
    float valeur = 0.0;
    get_val(idfTable, $1, &valeur);
    valeur += 1;
    maj_valeur(idfTable, $1, &valeur);
    char valStr[32];
    sprintf(valStr, "%f", 1.0);
    quadr("+", valStr, $1, $1);  // (+ , 1 , i , i)
}
| idf '-' '-' {
    if(strcmp($1, loop_var) != 0) {
        printf("Erreur ligne %d: La décrémentation doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
        yyerror("Erreur de variable de boucle");
        YYERROR;
    }
    float valeur = 0.0;
    get_val(idfTable, $1, &valeur);
    valeur -= 1;
    maj_valeur(idfTable, $1, &valeur);
    char valStr[32];
    sprintf(valStr, "%f", 1.0);
    quadr("-", valStr, $1, $1);  // (- , 1 , i , i)
};

WHILE: AWHILE '{' MULTIINST '}'{
    
    sprintf(tmp, "%d",deb_dowhile);
    quadr("BR",tmp,"vide","vide");
    sprintf(tmp, "%d",qc);
    updateQuad(deb_dowhile,1,tmp);
} ;
AWHILE : mc_while '(' EXPRESSIONS ')'{
    deb_dowhile = qc;
    // Génère le quad complet BE (adresse, var, valeur, vide)
    sprintf(tmp, "%d", qc+3);  // Adresse de saut
    quadr("BE", tmp, tmp_name, tmp_compare_value);
    // Réinitialisation
    tmp_name[0] = '\0';
    tmp_compare_value[0] = '\0';

};

CONDIF : BiF {
    sprintf(tmp, "%d", qc);
    updateQuad(fin_if,1,tmp);
}
       | BiF mc_else '{' MULTIINST '}' {
        sprintf(tmp, "%d", qc);
        updateQuad(fin_if,1,tmp);
       }
       | CiF mc_else '{' MULTIINST '}'{
        sprintf(tmp, "%d", qc);
        updateQuad(fin_if,1,tmp);
        updateQuad(fin_ifelse,1,tmp);
       } ;
CiF : DiF '{' MULTIINST '}'{
    fin_ifelse = qc;
    quadr("BR","","vide","vide");
    sprintf(tmp, "%d", qc);
    updateQuad(deb_else,1,tmp);
} ;
DiF : BiF mc_elseif '(' EXPRESSIONS ')'{
    deb_else = qc; // sauvgarder qc de BZ pour on peut faire une mise a jour 
    sprintf(tmp,"%d",boolc);
    quadr("BZ","",tmp,"vide");
};
BiF: AiF '{' MULTIINST '}' {
    fin_if = qc;
    quadr("BR","","vide","vide");
    sprintf(tmp, "%d", qc);
    updateQuad(deb_else,1,tmp);
};
AiF : mc_if '(' EXPRESSIONS ')'{
    deb_else = qc; // sauvgarder qc de BZ pour on peut faire une mise a jour 
    sprintf(tmp,"%d",boolc);
    quadr("BZ","",tmp,"vide");
};
SWITCH : mc_switch '(' idf ')' '{' CASE '}' {
           if (!estDeclareDansaportee(idfTable, $3)) {
                printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            }
            if (qnt == 1){
                sprintf(tmp, "%d", qc);
                updateQuad(fin_if,1,tmp);
            }
            };
CASE : ACASE CASE
     | mc_default ':' INST 
     | mc_default '{' MULTIINST '}' ;
ACASE : mc_case NUMB ':' INST mc_break ';' {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
}
     | mc_case NUMB '{' MULTIINST '}' mc_break ';' {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
}
     | mc_case chaine ':' INST mc_break ';' CASE {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
}
     | mc_case chaine '{' MULTIINST '}' mc_break ';' {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
} ;

TRY : mc_try '{' MULTIINST '}' mc_catch EXPS '{' MULTIINST '}' 
    | mc_try '{' MULTIINST '}' mc_finally '{' MULTIINST '}' 
    | mc_try '{' MULTIINST '}' mc_catch EXPS '{' MULTIINST '}' mc_finally '{' MULTIINST '}';

EXPS : '('mc_exception idf')' | '('mc_arithmetic_exception idf')' |  ;

TYPE : mc_int{strcpy(save_type,$1);}  | mc_float{strcpy(save_type,$1);}  | mc_boolean{strcpy(save_type,$1);}  | mc_double{strcpy(save_type,$1);}  | mc_char{strcpy(save_type,$1);}  | mc_string{strcpy(save_type,$1);}  ;

DEC: MODIFIERS TYPE DECLARATION  ';' 
   | TYPE DECLARATION ';';

DECLARATION : idf ',' DECLARATION {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);
                }
            }
            | idf '=' NUMB ',' DECLARATION {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);
                    float valeur_initiale = (float)$3;
                    maj_valeur(idfTable, (char*)$1, &valeur_initiale);
                }
                sprintf(tmp,"%f",$3);
                quadr("=",tmp,"vide",$1);
            }
            | idf '=' chaine ',' DECLARATION {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else if (strcmp(save_type, "String") != 0) {
                    printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, obtenu string) (ligne %d, colonne %d)\n", $1, save_type, nb_ligne, Col);
                }  else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);    
                }
                quadr("=",$3,"vide",$1);
                
            }
            | idf '=' chaine {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else if (strcmp(save_type, "String") != 0) {
                    printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, obtenu string) (ligne %d, colonne %d)\n", $1, save_type, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);
                }
                quadr("=",$3,"vide",$1);
            }
            | idf {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);
                }
            }
            | idf '=' EXPRESSION { 
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)$1, "IDF", save_type, 0.0);
                    float valeur_initiale = $3;
                    maj_valeur(idfTable, (char*)$1, &valeur_initiale); 
                 
                }
                if(boolc==-1){
                    sprintf(tmp,"%f",$3);
                    quadr("=",tmp,"vide",$1);
                }else{
                    if(boolc==0){
                        quadr("=","FALSE","vide",$1);
                    }else{
                        quadr("=","TRUE","vide",$1);
                    }
                    boolc = -1;
                }
                
            }
            | idf '=' logic ',' DECLARATION {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       $3, save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $1, "IDF", save_type, 0.0);
                float valeur = (strcmp($3, "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, $1, &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", $1);
                }
                }
            | idf '=' logic {
                if (estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } else if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       $3, save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, $1, "IDF", save_type, 0.0);
                float valeur = (strcmp($3, "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, $1, &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", $1);
                }

                };

ARGUMENT : TYPE idf {
                    insertComplex(idfTable, (char*)$2, "IDF", save_type, 0.0);
                    maj_type(idfTable, (char*)$2, save_type); 
            }
            | mc_string'['']' mc_args 
            | TYPE idf ',' ARGUMENT  {    
                    insertComplex(idfTable, (char*)$2, "IDF", save_type, 0.0);
                    maj_type(idfTable, (char*)$2, save_type);
            }
            | ;
EXPRESSIONS : EXPRESSION | OBJFUN ;

EXPRESSION: LOGICAL_OR   {  $$ = $1;  } ;

LOGICAL_OR: LOGICAL_AND {   $$ = $1; }
         | LOGICAL_OR mc_or LOGICAL_AND {  
                if($1 || $3){
                            boolc = 1;
                            $$=1;
                        }else {
                            boolc = 0;
                            $$=0;
                        }
} ;

LOGICAL_AND: RELATIONAL
            | LOGICAL_AND mc_and RELATIONAL {
    if($1 && $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
} ;

RELATIONAL: ADDITIVE 
          | ADDITIVE '>' ADDITIVE {
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 > $3){
                boolc = 1;
                $$=1;
                
            }else {
                boolc = 0;
                $$=0;
            }
          } 
          | ADDITIVE '<' ADDITIVE {
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 < $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
          }
          | ADDITIVE mc_ge ADDITIVE {
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 >= $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
          }
          | ADDITIVE mc_le ADDITIVE {
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 <= $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
          }
          | ADDITIVE mc_neq ADDITIVE{
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 != $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
          } 
          | ADDITIVE mc_eq ADDITIVE{
            sprintf(tmp_compare_value, "%d", (int)$3);  // Store as int
            if($1 == $3){
                boolc = 1;
                $$=1;
            }else {
                boolc = 0;
                $$=0;
            }
          } ;

ADDITIVE: TERM 
        | ADDITIVE '+' TERM { 
            $$ = $1 + $3;  // Calcul sémantique (correct)
            
            char *right = factor_names[--factor_index]; // Doit donner 2
            char *left  = factor_names[--factor_index]; // Doit donner 4 (mais donne 2 ?)
            sprintf(tmpb, "T%d", t++);
            quadr("+", left, right, tmpb);
            factor_names[factor_index++] = strdup(tmpb);
        }
        | ADDITIVE '-' TERM {
            $$ = $1 - $3;
            
            char *right = factor_names[--factor_index];
            char *left  = factor_names[--factor_index];
            
            sprintf(tmpb, "T%d", t++);
            quadr("-", left, right, tmpb);
            
            factor_names[factor_index++] = strdup(tmpb);
            
            printf("Soustraction : %s - %s → %s\n", left, right, tmpb);
        };

TERM: FACTOR 
    | TERM '*' FACTOR  { 
        $$ = $1 * $3;  // Multiplication
        printf("Résultat de la multiplication : %f\n", $$);
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("*",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    }
    | TERM '/' FACTOR { 
        if ($3 == 0) {
            printf("Erreur : Division par zéro (ligne %d, colonne %d)\n", nb_ligne, Col);
            $$ = 0;
        } else {
            $$ = $1 / $3;  // Division
            printf("Résultat de la division : %f\n", $$);
        }
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("/",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    }
    | TERM '%' FACTOR { 
        if ($3 == 0) {
            printf("Erreur : Modulo par zéro (ligne %d, colonne %d)\n", nb_ligne, Col);
            $$ = 0;
        } else {
            $$ = fmod($1, $3);  // Modulo
            printf("Résultat du modulo : %f\n", $$);
        }
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("%",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    };

FACTOR : idf { 
    if (!estDeclareDansaportee(idfTable, $1)) {
        printf("Erreur : Variable '%s' non déclarée (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
    }
    else {
        float valeur = 0.0;
        get_val(idfTable, $1, &valeur);
        $$ = valeur; // Récupérer la valeur de la variable
        factor_names[factor_index++] = strdup($1);
        
        strncpy(tmp_name, $1, sizeof(tmp_name)-1);
        tmp_name[sizeof(tmp_name)-1] = '\0';
        printf("[DEBUG] tmp_name = '%s'\n", tmp_name);  // Vérification


        strncpy(tmp_name_dowhile, $1, sizeof(tmp_name_dowhile)-1);
        tmp_name_dowhile[sizeof(tmp_name_dowhile)-1] = '\0';
        printf("[DEBUG] tmp_name = '%s'\n", tmp_name_dowhile);  // Vérification


    }

}
| NUMB {
    char *num_str = malloc(32);  // Allouer une nouvelle chaîne
    sprintf(num_str, "%f", $1);
    factor_names[factor_index++] = num_str;  // Stocker le nouveau pointeur
    printf("[DEBUG] Empile NUMB %f -> factor_names[%d] = %s\n", $1, factor_index-1, num_str);
}
| OBJFUN 
| logic 
| '(' EXPRESSION ')' { $$ = $2; }
| '!' FACTOR { $$ = !$2; };

MODIFIERS : mc_private mc_static | mc_protected mc_static | mc_public mc_static 
          | mc_private | mc_protected | mc_public | mc_static ;

RETURN : mc_return chaine {
            if (strcmp(type_retour_methode, "String") != 0) {
                printf("Erreur : Incompatibilité de type pour le retour (attendu : %s, trouvé : String) (ligne %d, colonne %d)\n",
                       type_retour_methode, nb_ligne, Col);
            }
            quadr("return",$2,"vide","vide");
        }
   
       | mc_return EXPRESSION { 
       char* typeRetour = save_type; 
    if (typeRetour == NULL) {
        printf("Erreur : Type inconnu pour l'expression (ligne %d, colonne %d)\n", nb_ligne, Col);
    } else if (strcmp(type_retour_methode, typeRetour) != 0) {
        printf("Erreur : Incompatibilité de type pour le retour (attendu : %s, trouvé : %s) (ligne %d, colonne %d)\n",
               type_retour_methode, typeRetour, nb_ligne, Col);
    } else {
        float val = $2;
        printf("[DEBUG] Retour de méthode : %s = %f\n", nom_fonction, val);
        maj_val_fonction(idfTable, nom_fonction , &val);
        
    }
    sprintf(tmp,"%f",$2);
    quadr("return",tmp,"vide","vide");
};
NUMB : real { $$ = $1; } 
     | integer { $$ = (float)$1; }; 

THROWS : mc_throws mc_exception | mc_throws |  ;

OBJFUN : idf '.' idf '(' ARG ')' {
            if (!estDeclareDansaportee(idfTable, $1)) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $1, nb_ligne, Col);

            if (!estDeclareDansaportee(idfTable, $3)) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            }
            } 
            sprintf(tmp, "%s.%s", $1, $3);
            quadr("call",tmp,"vide","vide");
        }
       | idf '.' idf {
            if (!estDeclareDansaportee(idfTable, $1)) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                if (!estDeclareDansaportee(idfTable, $3)) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $3, nb_ligne, Col);
            }
            } 
        }
       | idf DINTMATRIX '.' idf {
            if (!estDeclareDansaportee(idfTable, $1)) {
                printf("Erreur : Tableau '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                if (!estDeclareDansaportee(idfTable, $4)) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $4, nb_ligne, Col);
            }
            } 
        };

AFFTABLE : idf DINTMATRIX {
                if (!estDeclareDansaportee(idfTable, $1)) {
                    printf("Erreur : Tableau '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
                } 
            strcpy(tmp,$1);   
             strcpy($$, $1);  // retourne le nom pour l’utiliser comme $1 plus tard
    strcpy(typeAffTable, get_type(idfTable, $1)); // on récupère son type
          };
DINTMATRIX: '['integer']' {
                if ($2 < 0 || $2 >= taille) {
                    printf("Erreur : Indice hors bornes\n ");
                }
                float a = $2;
                sprintf(tmp1,"[%f]",a);
            }
          | '['idf']' {
                if (!estDeclareDansaportee(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée dans la portée actuelle (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, $2));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour être un indice de la matrice (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                    } else {
                        float valeur;
                        get_val(idfTable, $2, &valeur);
                        if (valeur < 0 || valeur >= taille) {
                              printf("Erreur : Indice hors bornes\n ");
                        }
                    }
                }
                float valeur;
                get_val(idfTable, $2, &valeur);
                sprintf(tmp1,"[%f]",valeur);
            }
          | '['integer']' '['integer']' {
                if ($2 < 0 || $2 >= i-1 || $5 < 0 || $5 >= j-1) {
                      printf("Erreur : Indice hors bornes\n ");
                }
                float a = $2;
                float b = $5;
                sprintf(tmp1,"[%f][%f]",a,b);
            }
          | '['idf']' '['integer']' {
                if (!estDeclareDansaportee(idfTable, $2)) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée dans la portée actuelle (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, $2));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour être un indice de la matrice (ligne %d, colonne %d)\n", $2, nb_ligne, Col);
                    } else {
                        float valeur;
                        get_val(idfTable, $2, &valeur);
                        if (valeur < 0 || valeur >= i-1 || $5 < 0 || $5 >= j-1) {
                              printf("Erreur : Indice hors bornes \n");
                        }
                    }
                }
                float valeur;
                float a = $5 ;
                get_val(idfTable, $2, &valeur);
                sprintf(tmp1,"[%f][%f]",valeur,a);
            }
          | '['idf']' '['idf']' {
                if (estDeclareDansaportee(idfTable, $2) == 0 || estDeclareDansaportee(idfTable, $5) == 0) {
                    printf("Erreur : Une ou plusieurs variables utilisées mais non déclarées dans la portée actuelle (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else {
                    char typeVar1[50], typeVar2[50];
                    strcpy(typeVar1, get_type(idfTable, $2));
                    strcpy(typeVar2, get_type(idfTable, $5));

                    if (strcmp(typeVar1, "int") != 0 || strcmp(typeVar2, "int") != 0) {
                        printf("Erreur sémantique : '%s' et '%s' doivent être des entiers pour être des indices de la matrice (ligne %d, colonne %d)\n", $2, $5, nb_ligne, Col);
                    } else {
                        float valeur1, valeur2;
                        get_val(idfTable, $2, &valeur1);
                        get_val(idfTable, $5, &valeur2);
                        if (valeur1 < 0 || valeur1 >= i-1 || valeur2 < 0 || valeur2 >= j-1) {
                              printf("Erreur : Indice hors bornes \n");
                        }
                    }
                }
                float valeur1, valeur2;
                get_val(idfTable, $2, &valeur1);
                get_val(idfTable, $5, &valeur2);
                sprintf(tmp1,"[%f][%f]",valeur1,valeur2);
            };
%%
int main() {
  
    // Initialisation des tables de symboles
    idfTable = createSymbolTable();
    separatorTable = createSymbolTable();
    keywordTable = createSymbolTable();

    yyparse();
    afficher_qdr();
    optimiser();
    afficher_qdr();

    generer_code_assembleur("output.asm", idfTable);
   // Affichage des tables des symboles après analyse
    printf("\n===== Table des Identificateurs =====\n");
    displayComplexTable(idfTable, "Identificateurs");

    printf("\n===== Table des Séparateurs =====\n");
    displaySimpleTable(separatorTable, "Séparateurs");

    printf("\n===== Table des Mots-Clés =====\n");
    displaySimpleTable(keywordTable, "Mots-clés");

    // Libération de la mémoire
    freeSymbolTable(idfTable);
    freeSymbolTable(separatorTable);
    freeSymbolTable(keywordTable);

    return 0 ;}

    
