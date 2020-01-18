#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interacao.h"
#include "instituicao.h"
#include "departamento.h"
#include "professor.h"


#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'


#define TITULO_OPCAO1 "CADASTRAR DEPARTAMENTO"
#define TITULO_OPCAO2 "CADASTRAR PROFESSOR(A)"
#define TITULO_OPCAO3 "LISTAR PROFESSORES COM MESTRADO"
#define TITULO_OPCAO4 "LISTAR PROFESSORES COM DOUTORADO"
#define TITULO_OPCAO5 "SALVAR DADOS EM ARQUIVO"
#define TITULO_OPCAO6 "SAIR DO PROGRAMA"


#define N_OPCOES 6


int main(void)
{

    //VARIÁVEIS DE INTERAÇÃO MENU
    int interacao = 1;
    int op;

    //VARIÁVEIS DE INTERAÇÃO PROFESSOR
    char nome_prof[100];
    int matricula;
    char area_atuacao[50];
    int titulacao;

    //VARIÁVEIS DE INTERAÇÃO DEPARTAMENTO
    char nome_depart[100];
    char sigla[10];
    Departamento_Arv* departamento;

    //TABELA INSTITUIÇÃO
    Hash* instituicao = instituicao_hash_cria();

    while(interacao)
    {
        apresenta_programa("========SISTEMA ORGANIZACIONAL INSTITUICAO DE ENSINO SUPERIOR========\n"
                           "\n------------------SEJA BEM VINDO.Versao 1.0------------------"); //'MENSAGEM' APRESENTACAO DO PROGRAMA
        apresenta_menu(N_OPCOES, OPCAO1,TITULO_OPCAO1, TITULO_OPCAO2,TITULO_OPCAO3, TITULO_OPCAO4,
                       TITULO_OPCAO5, TITULO_OPCAO6); //APRESENTA O 'MENU'
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1); //LÊ OPCAO DIGITADA

        switch(op)
        {

            //OPCAO 1 CADASTRAR DEPARTAMENTO
            case OPCAO1:
                        limpa_tela();
                        printf("\nDIGITE O NOME DO DEPARTAMENTO: ");
                        strcpy(nome_depart, le_string());
                        printf("\nDIGITE A SIGLA DO DEPARTAMENTO: ");
                        strcpy(sigla, le_string());
                        if(instituicao_hash_busca_departamento(instituicao, sigla) == NULL)
                        {
                            departamento = departamento_cria(nome_depart, sigla);
                            instituicao_hash_insere(instituicao, departamento);
                            printf("\nDEPARTAMENTO CADASTRADO.\n\n");
                        }
                        else
                        {
                            printf("\nESSE DEPARTAMENTO JA SE ENCONTRA-SE CADASTRADO.\n\n");
                        }
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 2 CADASTRAR PROFESSOR(A)
            case OPCAO2:
                        limpa_tela();
                        printf("\nNOME: ");
                        strcpy(nome_prof, le_string());
                        printf("\nMATRICULA: ");
                        scanf("%d", &matricula);
                        printf("\nAREA DE ATUACAO: ");
                        strcpy(area_atuacao, le_string());
                        printf("\nTITULACAO (Mestrado - 1 | Doutorado - 2 | Outra - 3): ");
                        scanf("%d", &titulacao);
                        printf("\nDIGITE A SIGLA DO DEPARTAMENTO AO QUAL O PROFESSOR SERA INSERIDO: ");
                        strcpy(sigla, le_string());
                        departamento = instituicao_hash_busca_departamento(instituicao, sigla);
                        if(departamento != NULL)
                        {

                            if(titulacao == 1)
                            {
                                departamento_insere_professor(departamento,
                                                              professor_cria(nome_prof, matricula, area_atuacao, "Mestrado"));
                            }
                            else if(titulacao == 2)
                            {
                                departamento_insere_professor(departamento,
                                                              professor_cria(nome_prof, matricula, area_atuacao, "Doutorado"));
                            }
                            else
                            {
                                departamento_insere_professor(departamento,
                                                              professor_cria(nome_prof, matricula, area_atuacao, "Outra"));
                            }

                            printf("\nPROFESSOR CADASTRADO.\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("\nNEM UM DEPARTAMENTO ENCONTRADO COM A SIGLA INFORMADA.\n\n");
                            system("pause");
                        }
                        limpa_tela();
                        break;

            //OPCAO 3 LISTAR PROFESSORES COM MESTRADO
            case OPCAO3:
                        limpa_tela();
                        printf("\nPROFESSORES COM MESTRADO:\n\n");
                        listar_departamento_professores(instituicao, 1);
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 4 LISTAR PROFESSORES COM DOUTORADO
            case OPCAO4:
                        limpa_tela();
                        printf("\nPROFESSORES COM DOUTORADO:\n\n");
                        listar_departamento_professores(instituicao, 2);
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 5 SALVAR DADOS EM ARQUIVO
            case OPCAO5:

                        break;

            //OPCAO 6 SAIR DO PROGRAMA
            case OPCAO6:

                        limpa_tela();
                        mensagem_despedida("\n\n\n\n\n\n\n\n\n<<<<---OBRIGADO E ATE LOGO!--->>>>\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        interacao = 0;
                        break;

            default:

                    printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                    return 1;
        }
    }

    return 0;
}


