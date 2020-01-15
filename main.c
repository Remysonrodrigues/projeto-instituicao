#include <stdio.h>
#include <stdlib.h>
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

    //VARIÁVEIS DE INTERAÇÃO
    int interacao = 1;
    int op;

    while(interacao)
    {
        apresenta_programa("========SISTEMA ORGANIZACIONAL INSTITUICAO DE ENSINO SUPERIOR========\n"
                           "\n------------------SEJA BEM VINDO.Versao 1.0------------------");//'MENSAGEM' APRESENTACAO DO PROGRAMA
        apresenta_menu(N_OPCOES, OPCAO1,TITULO_OPCAO1, TITULO_OPCAO2,TITULO_OPCAO3, TITULO_OPCAO4,
                       TITULO_OPCAO5, TITULO_OPCAO6); //APRESENTA O 'MENU'
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1); //LÊ OPCAO DIGITADA

        switch(op)
        {

            //OPCAO 1 CADASTRAR DEPARTAMENTO
            case OPCAO1:

                        break;

            //OPCAO 2 CADASTRAR PROFESSOR(A)
            case OPCAO2:

                        break;

            //OPCAO 3 LISTAR PROFESSORES COM MESTRADO
            case OPCAO3:

                        break;

            //OPCAO 4 LISTAR PROFESSORES COM DOUTORADO
            case OPCAO4:

                        break;

            //OPCAO 5 SALVAR DADOS EM ARQUIVO
            case OPCAO5:

                        break;

            //OPCAO 6 SAIR DO PROGRAMA
            case OPCAO6:

                        limpa_tela();
                        mensagem_despedida("\n\n---OBRIGADO E ATE LOGO!---\n\n");//'MENSAGEM' DESPEDIDA DO PROGRAMA
                        interacao = 0;
                        break;

            default:

                    printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                    return 1;
        }
    }

    return 0;
}


