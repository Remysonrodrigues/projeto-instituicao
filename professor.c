#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "professor.h"


    struct professor
    {
        char nome[100];
        int matricula;
        char area_atuacao[50];
        char titulacao[30];
    };


    Professor* professor_cria(char* nome, int mat, char* area_atuacao, char* titulacao)
    {
        Professor* prof = (Professor*)malloc(sizeof(Professor));
        strcpy(prof->nome, nome);
        prof->matricula = mat;
        strcpy(prof->area_atuacao, area_atuacao);
        strcpy(prof->titulacao, titulacao);
        return prof;
    }


    char* professor_nome(Professor* prof)
    {
        return prof->nome;
    }


    char* professor_titulacao(Professor* prof)
    {
        return prof->titulacao;
    }


    void professor_imprime(Professor* prof)
    {
        printf("Nome: %s\n", prof->nome);
        printf("Matricula: %d\n", prof->matricula);
        printf("Area de Atuacao: %s\n", prof->area_atuacao);
        printf("Titulacao: %s\n\n", prof->titulacao);
    }


    void professor_libera(Professor* prof)
    {
        free(prof);
    }
