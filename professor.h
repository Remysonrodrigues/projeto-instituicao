#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

    typedef struct professor Professor;

    Professor* professor_cria(char* nome, int mat, char* area_atuacao, char* titulacao);

    char* professor_nome(Professor* prof);

    char* professor_titulacao(Professor* prof);

    void professor_imprime(Professor* prof);

    void professor_libera(Professor* prof);

#endif // PROFESSOR_H_INCLUDED
