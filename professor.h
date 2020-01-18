#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

    typedef struct professor Professor;

    Professor* professor_cria(char* nome, int mat, char* area_atuacao, char* titulacao);

    char* professor_nome(Professor* prof);

    void professor_imprime(Professor* prof, int op);

    void professor_libera(Professor* prof);

#endif // PROFESSOR_H_INCLUDED
