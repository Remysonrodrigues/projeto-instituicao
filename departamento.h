#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED
#include "professor.h"

    typedef struct arvno ArvNo;

    typedef struct departamento_arv Departamento_Arv;

    Departamento_Arv* departamento_cria(char* nome, char* sigla);

    void departamento_insere_professor(Departamento_Arv* depart, Professor* p);

    void departamento_imprime(Departamento_Arv* depart, int op);

    void departamento_libera(Departamento_Arv* depart);

    char* departamento_sigla(Departamento_Arv* depart);

#endif // DEPARTAMENTO_H_INCLUDED
