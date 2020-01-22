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


#define TITULO_OPCAO1 "CADASTRAR DEPARTAMENTO"
#define TITULO_OPCAO2 "CADASTRAR PROFESSOR(A)"
#define TITULO_OPCAO3 "LISTAR"
#define TITULO_OPCAO4 "SALVAR DADOS EM ARQUIVO"
#define TITULO_OPCAO5 "SAIR DO PROGRAMA"


#define SUB_OPCAO1 '1'
#define SUB_OPCAO2 '2'
#define SUB_OPCAO3 '3'
#define SUB_OPCAO4 '4'


#define SUB_TITULO_OPCAO1 "LISTAR PROFESSORES COM MESTRADO"
#define SUB_TITULO_OPCAO2 "LISTAR PROFESSORES COM DOUTORADO"
#define SUB_TITULO_OPCAO3 "LISTAR TODOS OS PROFESSORES"
#define SUB_TITULO_OPCAO4 "VOLTAR"


#define N_OPCOES 5
#define SUB_N_OPCOES 4

int main(void)
{

    //VARIÁVEIS DE INTERAÇÃO MENU
    int interacao = 1;
    int sub_interacao = 1;
    int op;

    //VARIÁVEL DE ARQUIVO
    FILE* saida;

    saida = fopen("saida.txt", "rt"); //ARQUIVO ABERTURA MODO LEITURA
    if(saida == NULL)
    {
        printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
        exit(1);
    }

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
    Hash* instituicao = instituicao_hash_carrega(saida);

    while(interacao)
    {
        apresenta_programa("========SISTEMA ORGANIZACIONAL INSTITUICAO DE ENSINO SUPERIOR========\n"
                           "\n------------------SEJA BEM VINDO.Versao 1.0------------------"); //'MENSAGEM' APRESENTACAO DO PROGRAMA
        apresenta_menu(N_OPCOES, OPCAO1,TITULO_OPCAO1, TITULO_OPCAO2,TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5); //APRESENTA O 'MENU'
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1); //LÊ OPCAO DIGITADA

        switch(op)
        {

            //OPCAO 1 CADASTRAR DEPARTAMENTO
            case OPCAO1:
                        limpa_tela();
                        printf("\n---DIGITE AS OPCOES SOLICITADAS---\n\n");
                        printf("\nNOME DO DEPARTAMENTO: ");
                        strcpy(nome_depart, le_string());
                        printf("\nSIGLA DO DEPARTAMENTO: ");
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
                        printf("\n---DIGITE AS OPCOES SOLICITADAS---\n\n");
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

            //OPCAO 3 LISTAR
            case OPCAO3:
                        sub_interacao = 1;
                        limpa_tela();
                        while(sub_interacao)
                        {
                            printf("\n---LISTAR PROFESSORES---\n\n");
                            apresenta_menu(SUB_N_OPCOES, SUB_OPCAO1, SUB_TITULO_OPCAO1, SUB_TITULO_OPCAO2, SUB_TITULO_OPCAO3, SUB_TITULO_OPCAO4); //APRESENTA O OPCOES DE LISTAR
                            op = le_opcao(SUB_OPCAO1, SUB_OPCAO1 + SUB_N_OPCOES - 1); //LÊ OPCAO DIGITADA

                            switch(op)
                            {
                                case SUB_OPCAO1:
                                                limpa_tela();
                                                printf("\n---PROFESSORES COM MESTRADO---\n\n");
                                                listar_departamento_professores(instituicao, 1);
                                                system("pause");
                                                limpa_tela();
                                                break;

                                case SUB_OPCAO2:
                                                limpa_tela();
                                                printf("\n---PROFESSORES COM DOUTORADO---\n\n");
                                                listar_departamento_professores(instituicao, 2);
                                                system("pause");
                                                limpa_tela();
                                                break;

                                case SUB_OPCAO3:
                                                limpa_tela();
                                                printf("\n---TODOS OS PROFESSORES---\n\n");
                                                listar_departamento_professores(instituicao, 3);
                                                system("pause");
                                                limpa_tela();
                                                break;

                                case SUB_OPCAO4:
                                                limpa_tela();
                                                sub_interacao = 0;
                                                break;

                                default:
                                        printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                                        return 1;
                            }

                        }

                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 4 SALVAR DADOS EM ARQUIVO
            case OPCAO4:
                        limpa_tela();
                        saida = fopen("saida.txt", "wt"); //ARQUIVOS ABERTURA MODO ESCRITA
                        if(saida == NULL)
                        {
                            printf("\n\nERRO NA ABERTURA DO ARQUIVO\n\n");
                            exit(1);
                        }
                        instituicao_hash_salva(saida, instituicao); //SALVA NO ARQUIVO 'saida.txt'
                        printf("\n\nDADOS SALVOS COM SUCESSO NO ARQUIVO 'saida.txt'.\n\n");
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO 5 SAIR DO PROGRAMA
            case OPCAO5:

                        limpa_tela();
                        mensagem_despedida("\n\n\n\n\n\n\n\n\n<<<<---OBRIGADO E ATE LOGO!--->>>>\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                        interacao = 0;
                        break;

            default:

                    printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                    return 1;
        }
    }

    fclose(saida); //FECHAMENTO DE ARQUIVO
    instituicao_hash_libera(instituicao); //LIBERANDO MEMORIA

    return 0;
}
