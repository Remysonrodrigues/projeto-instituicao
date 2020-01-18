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


    static void dados_professor(Professor* prof)
    {
        printf("Nome: %s\n", prof->nome);
        printf("Matricula: %d\n", prof->matricula);
        printf("Area de Atuacao: %s\n", prof->area_atuacao);
        printf("Titulacao: %s\n\n", prof->titulacao);
    }

    static void imprime_mestrado(Professor* prof)
    {
        if(prof != NULL && strcmp(prof->titulacao, "Mestrado") == 0)
        {
            dados_professor(prof);
        }
    }


    static void imprime_doutorado(Professor* prof)
    {
        if(prof != NULL && strcmp(prof->titulacao, "Doutorado") == 0)
        {
            dados_professor(prof);
        }
    }


    static void imprime(Professor* prof)
    {
        if(prof != NULL)
        {
            dados_professor(prof);
        }
    }


    void professor_imprime(Professor* prof, int op)
    {

        if(op == 1) //Imprime Professor com Mestrado
        {
            imprime_mestrado(prof);
        }
        else if(op == 2) //Imprime Professor com Doutorado
        {
            imprime_doutorado(prof);
        }
        else //Imprime Professor
        {
            imprime(prof);
        }

    }


    void professor_libera(Professor* prof)
    {
        free(prof);
    }
