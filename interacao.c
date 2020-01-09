#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "interacao.h"


    void apresenta_programa(char* msg)
    {
        printf("\n%s\n\n",msg);
    }

    void mensagem_despedida(char* msg)
    {
        printf("\n%s\n\n",msg);
    }


    void limpa_tela(void)
    {
        system("cls");
    }

    void limpa_buffer(void)
    {
        int valorLido;
        do
        {
            valorLido = getchar();
        }while((valorLido != '\n') && (valorLido != EOF));
    }

    int le_opcao(int menor_valor, int maior_valor)
    {
        int op;
        while(1)
        {
            printf("\nDIGITE SUA OPCAO: ");
            op = getchar();

            if (op >= menor_valor && op <= maior_valor)
            {
                limpa_buffer();
                break;
            }
            else
            {
                printf("\nOPCAO INVALIDA. TENTE NOVAMENTE.");
                printf("\nA OPCAO DEVE ESTAR ENTRE '%c' E '%c'. \n",menor_valor, maior_valor);
                limpa_buffer();
            }
        }

        return op;
    }

    char* le_string(void)
    {
        char* string = (char*) malloc (81 * sizeof(char));
        scanf(" %80[^\n]", string);
        limpa_buffer();
        return string;
    }

    void apresenta_menu(int n_itens, int menor_opcao, ...)
    {
        int i;
        va_list argumentos;
        va_start(argumentos,menor_opcao);
        for(i = 0;i < n_itens; ++i)
        {
            printf(" %c-%s\n",menor_opcao++,va_arg(argumentos,char *));
        }
        va_end(argumentos);
    }
