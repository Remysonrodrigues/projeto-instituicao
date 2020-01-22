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


    static void imprime(ArvNo* prof, int op)
    {
        if(prof != NULL)
        {
            imprime(prof->esq, op);
            professor_imprime(prof->info, op);
            imprime(prof->dir, op);
        }
    }


    void departamento_imprime(Departamento_Arv* depart, int op)
    {
        printf("Nome do Departamento: %s\n", depart->nome);
        printf("Sigla: %s\n\n", depart->sigla);

            imprime(depart->raiz, op);

    }


    void departamento_salva(FILE* fp, ArvNo* depart)
    {
        if(depart != NULL)
        {
            departamento_salva(fp, depart->esq);
            fprintf(fp,"%s\n%d\n%s\n%s\n", professor_nome(depart->info),
                                           professor_matricula(depart->info),
                                           professor_area(depart->info),
                                           professor_titulacao(depart->info));

            departamento_salva(fp, depart->dir);
        }
    }


    Departamento_Arv* departamento_carrega(FILE* fp, Departamento_Arv* depart, int quant_professor)
    {
        int i;
        //Variáveis Auxiliares Professor
        char nome_prof[100];
        int matricula;
        char area_atuacao[50];
        char titulacao[30];

        for(i = 0; i < quant_professor; i++)
        {
            fscanf(fp, "%s\n%d\n%s\n%s\n", nome_prof, &matricula, area_atuacao, titulacao);
            departamento_insere_professor(depart, professor_cria(nome_prof, matricula, area_atuacao, titulacao));
        }
        return depart;
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


    void departamento_libera(ArvNo* depart)
    {
        libera(depart);
    }


    static int quantidade(ArvNo* depart)
    {
        if(depart == NULL)
        {
           return 0;
        }
        else
        {
            return 1 + quantidade(depart->esq) + quantidade(depart->dir);
        }

    }


    int departamento_quant_professor(Departamento_Arv* depart)
    {
        return quantidade(depart->raiz);
    }


    char* departamento_nome(Departamento_Arv* depart)
    {
        return depart->nome;
    }


    char* departamento_sigla(Departamento_Arv* depart)
    {
        return depart->sigla;
    }


    ArvNo* departamento_raiz(Departamento_Arv* depart)
    {
        return depart->raiz;
    }
