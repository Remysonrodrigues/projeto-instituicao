#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

    typedef struct professor Professor;

    typedef struct arvno ArvNo;

    typedef struct departamento_arv Departamento_Arv;

    Departamento_Arv* departamento_cria(char* nome, char* sigla);

    void departamento_insere_professor(Departamento_Arv* depart, char* nome, int mat, char* area_atuacao, char* titulacao);

    void departamento_imprime(Departamento_Arv* depart);

    void departamento_libera(Departamento_Arv* depart);

#endif // DEPARTAMENTO_H_INCLUDED
