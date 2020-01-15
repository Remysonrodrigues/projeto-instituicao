#ifndef INSTITUICAO_H_INCLUDED
#define INSTITUICAO_H_INCLUDED
#include "departamento.h"
#include "professor.h"

    typedef struct hash Hash;

    Hash* instituicao_hash_cria(void);

    void instituicao_hash_insere(Hash* tab, Departamento_Arv* p);

    Departamento_Arv* instituicao_hash_busca_departamento(Hash* tab, char* sigla);

    void listar_departamento_professores(Hash* tab, int op);

    //Hash* instituicao_hash_carrega(FILE* fp);

    //void instituicao_hash_salva(FILE* fp,Hash* tab);

    void instituicao_hash_libera(Hash* tab);

#endif // INSTITUICAO_H_INCLUDED
