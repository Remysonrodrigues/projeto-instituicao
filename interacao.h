#ifndef INTERACAO_H_INCLUDED
#define INTERACAO_H_INCLUDED

    //(I) FUNÇÃO DE APRESENTAÇÃO DO PROGRAMA
    void apresenta_programa(char* msg);
    //(II) FUNÇÃO DE DESPEDIDA DO PROGRAMA
    void mensagem_despedida(char* msg);
    //(III) FUNÇÃO QUE LIMPA A TELA DE ÚSUARIO
    void limpa_tela(void);
    //(IV) FUNÇÃO QUE LIMPA O BUFFER DE ENTRADA
    void limpa_buffer(void);
    //(V) FUNÇÃO DE INTERAÇÃO E VALIDAÇÃO DE UMA OPÇÃO DIGITADA PELO ÚSUARIO
    int le_opcao(int menor_valor, int maior_valor);
    //(VI) FUNÇÃO QUE LÊ UMA UMA CADEIA DE CARACTERES
    char* le_string(void);
    //(VII) FUÇÃO QUE APRESENTA UM MENU COM NÚMERO INDETERMINADO DE OPÇÕES
    void apresenta_menu(int n_itens, int menor_opcao, ...);

#endif // INTERACAO_H_INCLUDED
