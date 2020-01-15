#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instituicao.h"
#include "departamento.h"
#include "professor.h"


    struct hash
    {
        int n;
        int dim;
        Departamento_Arv** d;
    };

    Hash* instituicao_hash_cria(void)
    {
        Hash* tab = (Hash*)malloc(sizeof(Hash));
        tab->n = 0;
        tab->dim = 7;
        tab->d = (Departamento_Arv**)malloc(tab->dim * sizeof(Departamento_Arv*));
        int i;
        for(i = 0; i < tab->dim; i++)
        {
            tab->d[i] = NULL;
        }
        return tab;
    }


    static int hash (Hash* tab, char* sigla)
    {
        return strlen(sigla) % tab->dim;
    }


    static void redimensiona(Hash* tab)
    {
        int max_ant = tab->dim;
        Departamento_Arv** ant = tab->d;
        tab->n = 0;
        tab->dim *= 1.947;
        tab->d = (Departamento_Arv**)malloc(tab->dim * sizeof(Departamento_Arv*));
        int i;
        for(i = 0; i < tab-> dim; ++i)
        {
            tab->d[i] = NULL;
        }
        int j;
        for(j = 0; j < max_ant; ++i)
        {
            if(ant[i])
            {
                instituicao_hash_insere(tab, ant[i]);
            }
        }
        free(ant);
    }


    void instituicao_hash_insere(Hash* tab, Departamento_Arv* d)
    {
        if(tab->n > 0.75 * tab->dim)
        {
            redimensiona(tab);
        }
        int h = hash(tab, departamento_sigla(d));
        while(tab->d[h] != NULL)
        {
            h = (h+1) % tab->dim;
        }
        tab->d[h] = d;
        tab->n++;
    }


    Departamento_Arv* instituicao_hash_busca_departamento(Hash* tab, char* sigla)
    {
        int h = hash(tab, sigla);
        while(tab->d[h] != NULL)
        {
            if(strcmp(departamento_sigla(tab->d[h]), sigla) == 0)
            {
                return tab->d[h];
            }
            h = (h+1) % tab->n;
        }
        return NULL;
    }


    static void listar(Hash* tab, void (*cb) (void*, void*), int op)
    {
        int i;
        for(i = 0; i < tab->dim; i++)
        {
            if(tab->d[i] != NULL)
            {
                cb(tab->d[i], op);
            }
        }
    }


    void listar_departamento_professores(Hash* tab, int op)
    {
        tab->n == 0 ? printf("Nao a Departamentos Cadastrados.\n") : listar(tab, departamento_imprime, op);
    }


    /*
    Hash* instituicao_hash_carrega(FILE* fp)
    {

    }


    void instituicao_hash_salva(FILE* fp, Hash* tab)
    {

    }*/


    void instituicao_hash_libera(Hash* tab)
    {
        int i;
        for(i = 0; i < tab->dim; i++)
        {
            departamento_libera(tab->d[i]);
            free(tab->d[i]);
        }
        free(tab);
    }

