#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "departamento.h"
#include "professor.h"


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


    static ArvNo* insere(ArvNo* prof, Professor* p)
    {
        if(prof == NULL)
        {
            prof = (ArvNo*)malloc(sizeof(ArvNo));
            prof->info = p;
            prof->esq = prof->dir = NULL;
        }
        else if(strcmp(professor_nome(prof->info), professor_nome(p)) > 0)
        {
            prof->esq = insere(prof->esq, p);
        }
        else
        {
            prof->dir = insere(prof->dir, p);
        }
        return prof;
    }


    void departamento_insere_professor(Departamento_Arv* depart, Professor* p)
    {
        depart->raiz = insere(depart->raiz, p);
    }


    static void imprime_mestrado(ArvNo* prof)
    {
        if(prof != NULL && strcmp(professor_titulacao(prof->info), "Mestrado") == 0)
        {
            imprime_mestrado(prof->esq);
            professor_imprime(prof->info);
            imprime_mestrado(prof->dir);
        }
    }


    static void imprime_doutorado(ArvNo* prof)
    {
        if(prof != NULL && strcmp(professor_titulacao(prof->info), "Doutorado") == 0)
        {
            imprime_doutorado(prof->esq);
            professor_imprime(prof->info);
            imprime_doutorado(prof->dir);
        }
    }


    static void imprime(ArvNo* prof)
    {
        if(prof != NULL)
        {
            imprime(prof->esq);
            professor_imprime(prof->info);
            imprime(prof->dir);
        }
    }


    void departamento_imprime(Departamento_Arv* depart, int op)
    {
        op = (int) op;
        printf("Nome do Departamento: %s\n", depart->nome);
        printf("Sigla: %s\n\n", depart->sigla);

        if(op == 1) //Listar Professores com Mestrado
        {
            imprime_mestrado(depart->raiz);
        }
        else if(op == 2) //Listar Professores com Doutorado
        {
            imprime_doutorado(depart->raiz);
        }
        else //Listar Todos os Professores
        {
            imprime(depart->raiz);
        }
    }


    static void libera(ArvNo* r)
    {
        if(r != NULL)
        {
            libera(r->esq);
            professor_libera(r->info);
            libera(r->dir);
            free(r);
        }
    }


    void departamento_libera(Departamento_Arv* depart)
    {
        libera(depart->raiz);
        free(depart);
    }


    char* departamento_sigla(Departamento_Arv* depart)
    {
        return depart->sigla;
    }

