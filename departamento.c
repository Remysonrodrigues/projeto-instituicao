#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "departamento.h"


    struct professor
    {
        char nome[100];
        int matricula;
        char area_atuacao[50];
        char titulacao[30];
    };


    struct arvno
    {
        Professor* info;
        ArvNo* esq;
        ArvNo* dir;
    };


    struct departamento_arv
    {
        char nome[100];
        char sigla[10];
        ArvNo* raiz;
    };


    Departamento_Arv* departamento_cria(char* nome, char* sigla)
    {
        Departamento_Arv* depart = (Departamento_Arv*)malloc(sizeof(Departamento_Arv));
        strcpy(depart->nome, nome);
        strcpy(depart->sigla, sigla);
        depart->raiz = NULL;
        return depart;
    }


    static Professor* professor_insere(char* nome, int mat, char* area_atuacao, char* titulacao)
    {
        Professor* prof = (Professor*)malloc(sizeof(Professor));
        strcpy(prof->nome, nome);
        prof->matricula = mat;
        strcpy(prof->area_atuacao, area_atuacao);
        strcpy(prof->titulacao, titulacao);
        return prof;
    }


    static ArvNo* insere(ArvNo* prof, char* nome, int mat, char* area_atuacao, char* titulacao)
    {
        if(prof == NULL)
        {
            prof = (ArvNo*)malloc(sizeof(ArvNo));
            prof->info = professor_insere(nome, mat, area_atuacao, titulacao);
            prof->esq = prof->dir = NULL;
        }
        else if(strcmp(prof->info->nome, nome) > 0)
        {
            prof->esq = insere(prof->esq, nome, mat, area_atuacao, titulacao);
        }
        else
        {
            prof->dir = insere(prof->dir, nome, mat, area_atuacao, titulacao);
        }
        return prof;
    }


    void departamento_insere_professor(Departamento_Arv* depart, char* nome, int mat, char* area_atuacao, char* titulacao)
    {
        depart->raiz = insere(depart->raiz,nome, mat, area_atuacao, titulacao);
    }


    static void imprime(ArvNo* prof)
    {
        if(prof != NULL)
        {
            imprime(prof->esq);
            printf("\tNome: %s\n", prof->info->nome);
            printf("\tMatricula: %d\n", prof->info->matricula);
            printf("\tArea de Atuacao: %s\n", prof->info->area_atuacao);
            printf("\tTitulacao: %s\n\n", prof->info->titulacao);
            imprime(prof->dir);
        }
    }


    void departamento_imprime(Departamento_Arv* depart)
    {
        printf("Nome do Departamento: %s\n", depart->nome);
        printf("Sigla: %s\n\n", depart->sigla);
        imprime(depart->raiz);
    }


    static void libera(ArvNo* r)
    {
        if(r != NULL)
        {
            libera(r->esq);
            libera(r->dir);
            free(r->info);
            free(r);
        }
    }


    void departamento_libera(Departamento_Arv* depart)
    {
        libera(depart->raiz);
        free(depart);
    }

