#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED
#include "professor.h"

    typedef struct arvno ArvNo;

    typedef struct departamento_arv Departamento_Arv;

    Departamento_Arv* departamento_cria(char* nome, char* sigla);

    void departamento_insere_professor(Departamento_Arv* depart, Professor* p);

    void departamento_imprime(Departamento_Arv* depart, int op);

    void departamento_salva(FILE* fp, ArvNo* depart);

    Departamento_Arv* departamento_carrega(FILE* fp, Departamento_Arv* depart, int quant_professor);

    void departamento_libera(ArvNo* depart);

    int departamento_quant_professor(Departamento_Arv* depart);

    char* departamento_nome(Departamento_Arv* depart);

    char* departamento_sigla(Departamento_Arv* depart);

    ArvNo* departamento_raiz(Departamento_Arv* depart);

#endif // DEPARTAMENTO_H_INCLUDED
