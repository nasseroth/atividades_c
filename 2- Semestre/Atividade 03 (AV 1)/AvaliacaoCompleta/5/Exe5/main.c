#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <stdbool.h>

#ifdef __unix__#include <unistd.h>

#include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)

#define OS_Windows

#include <windows.h>

#endif
/*
5) (capacidade: 10
assentos).
a) Seu programa deve exibir o seguinte menu de alternativas:
Pressione 1 para �econ�mico�
Pressione 2 para �executivo�
b) Se a pessoa digitar 1, seu programa deve atribuir um assento na �rea
�econ�mica� (assentos 1-5). Se a pessoa digitar 2, seu programa deve atribuir
um assento na �rea �executiva� (assentos 6-10). Seu programa, ent�o, deve
imprimir um ticket de embarque indicando o n�mero de assento da pessoa e
se ela est� na �rea �econ�mica� ou �executiva� do avi�o.
c) Voc� deve fazer uso de um array para representar os assentos do avi�o.
Inicialize os elementos do array com 0 para indicar que os assentos est�o
vazios. � medida que cada assento � atribu�do, configure os elementos do
array com 1 para indicar que o assento n�o est� mais dispon�vel.
d) Seu programa deve verificar se o assento selecionado j� est� ocupado antes
da atribui��o, nunca deve atribuir um assento j� utilizado. Quando a �rea
�econ�mica� estiver lotada, seu programa deve solicitar ao atendente se este
deseja acomodar o passageiro na �rea �executiva� (e vice-versa). Se for, fa�a
a atribui��o apropriada de assento. Se n�o for, imprima a mensagem
�Aguarde o pr�ximo voo!!!�.

*/
int assentos[10];
unsigned int cp = 1252;
main()
{
    SetConsoleCP(cp);
    SetConsoleOutputCP(cp);
    limparAssentos();
    exibirMenu();
}

exibirMenu()
{
    int opcao = 0;
    while (opcao != 3)
    {
        printf("Bem vindo!\n");
        listarAssentos();
        printf("1 - Econ�mico\n");
        printf("2 - Executivo\n");
        printf("3 - Sair\n");
        printf("Informe a opcao desejada: \n");
        scanf("%d", & opcao);
        //limparTela();
        opcaoEscolhida(opcao);
    }
}

opcaoEscolhida(int opcaoSelecionada)
{
    atribuirAssento(opcaoSelecionada);
}

limparAssentos()
{
    for (int i = 0; i < 10; i++)
    {
        assentos[i] = 0;
    }
}

listarAssentos()
{
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            if (assentos[i] == 0)
            {
                printf("Assento: %d - Econ�mico - Status: VAGO\n", i);
            }
            else
            {
                printf("Assento: %d - Econ�mico - Status: OCUPADO\n", i);
            }
        }
        else if (i >= 5 && i < 10)
        {
            if (assentos[i] == 0)
            {
                printf("Assento: %d - Executivo - Status: VAGO\n", i);
            }
            else
            {
                printf("Assento: %d - Executivo - Status: OCUPADO\n", i);
            }
        }
    }
}

bool verificarAssentoDisponivel(int assento)
{
    if (assentos[assento] == 0)
    {
        return true;
    }
    return false;
}
bool verificarAssentoDisponivelPorClasse(int opcao)
{
   if(opcao == 1){
        for(int contador = 0; contador < 5; contador++){
            if(assentos[contador] == 0){
                return true;
            }
        }
    }
    if(opcao == 2){
        for(int contador = 5; contador >= 5 && contador <= 9; contador++){
            if(assentos[contador] == 0){
                return true;
            }
        }
    }
    return false;
}
atribuirAssento(int opcao)
{
    int contador = 0;
    bool naoTemAssentos;
    if (opcao == 1)
    {
        contador = 0;
        for ( ; contador < 5; contador++)
        {
            if (verificarAssentoDisponivel(contador))
            {
                assentos[contador] = 1;
                limparTela();
                naoTemAssentos = false;
                printf("Assento: %d [ECON�MICO] preenchido\n", contador);
                contador = 5;
            }
            else
            {
                limparTela();
                naoTemAssentos = true;
                printf("N�o h� assentos econ�micos dispon�veis\n");
            }
        }
    }
    if (opcao == 2)
    {
        contador = 5;
        for ( ; contador >= 5 && contador <= 9; contador++)
        {
            if (verificarAssentoDisponivel(contador))
            {
                assentos[contador] = 1;
                limparTela();
                printf("Assento: %d [EXECUTIVO] preenchido\n", contador);
                contador = 9;
            } else {
                limparTela();
                printf("N�o h� assentos executivos dispon�veis\n");
            }
        }
    }
    if(naoTemAssentos){
        int opcaoAtribuicao = 0;
        if(opcao == 1 && verificarAssentoDisponivelPorClasse(2)){ // econom
            printf("Deseja atribuir esse passageiro a classe EXECUTIVA? \n");
            printf("1 - SIM\n");
            printf("2 - N�O\n");
            printf("Informe a op��o desejada: \n");
            scanf("%d", &opcaoAtribuicao);
            if(opcaoAtribuicao == 1){
                atribuirAssento(2);
            } else {
                printf("Aguarde o pr�ximo voo!!!\n");
            }
        } else if (opcao == 2 && verificarAssentoDisponivelPorClasse(1)){
            printf("Deseja atribuir esse passageiro a classe ECONOMICA? \n");
            printf("1 - SIM\n");
            printf("2 - N�O\n");
            printf("Informe a op��o desejada: \n");
            scanf("%d", &opcaoAtribuicao);
            if(opcaoAtribuicao == 1){
                atribuirAssento(1);
            } else {
                printf("Aguarde o pr�ximo voo!!!\n");
            }
        }
    }

}
limparTela()
{
#ifdef OS_Windows
    /* Codigo Windows */
    system("cls");
#else
    /* Codigo GNU/Linux */
    system("clear");
#endif
}
