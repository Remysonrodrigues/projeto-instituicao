#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

    typedef struct professor Professor;

    Professor* professor_cria(char* nome, int mat, char* area_atuacao, char* titulacao);

    void professor_imprime(Professor* prof, int op);

    void professor_libera(Professor* prof);

    char* professor_nome(Professor* prof);

    int professor_matricula(Professor* prof);

    char* professor_area(Professor* prof);

    char* professor_titulacao(Professor* prof);

#endif // PROFESSOR_H_INCLUDED
