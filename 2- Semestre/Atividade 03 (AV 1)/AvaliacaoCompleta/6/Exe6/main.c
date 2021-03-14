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
7) Implemente uma aplica��o que realize o cadastro de ve�culos.
a) Voc� deve criar uma estrutura para armazenar os dados do ve�culo
contendo (modelo, cor, placa, tipo, caracter�stica e status);
b) Sua aplica��o deve conter um menu com as seguintes op��es: (inserir,
editar, remover, listar, pesquisar, sair);
c) Utilize uma enumera��o para representar a cor do ve�culo, voc� deve usar
os seguintes dados: (1 - Preto, 2 - Branco, 3 - Verde, 4 - Azul, 5 - Vermelho,
6 - Amarelo, 7 - Prata, 8 - Cinza);
d) Para cadastro do tipo, deve ser informado se o ve�culo � (1 - Transporte de
passageiros, 2 - Transporte de Cargas, 3 - Passeio);
e) Conforme o tipo de ve�culo, deve ser armazenado uma caracter�stica
diferente no referido campo. Para isto, voc� deve criar uma uni�o entre:
quantidade de passageiros (inteiro); carga m�xima (float); possui seguro
(texto). Caso o ve�culo seja do tipo transporte de passageiros deve ser
informado a quantidade de passageiros, caso seja transporte de carga, deve
ser informado a carga m�xima e caso contr�rio, se o mesmo possui seguro
(sim ou n�o);
f) Deve ser poss�vel armazenar 15 registros de ve�culos. A cada inser��o deve
ser verificado se h� posi��es livres na lista, caso contr�rio deve ser
informado que a mesma est� cheia.
g) Quando selecionada a op��o de remover usu�rio, deve ser informada a
posi��o que se deseja remover e assim atualizar o status da posi��o da
lista. �*� indica que o registro est� apagado. �+� indica que o registro est� em
uso. Qualquer outro s�mbolo indica que o registro est� dispon�vel.
h) Para altera��o o usu�rio deve informar o c�digo desejado, caso a posi��o
esteja vazia n�o deve ser poss�vel alterar o conte�do;
i) A lista deve exibir na tela o C�digo, modelo, marca e placa dos ve�culos
cadastrados;
j) Na op��o de pesquisa o usu�rio informa a posi��o desejada e s�o
impressos todos os dados do ve�culo.

*/
typedef struct {
  char nome[50];
  int numeroVendedor;
  int idade;
}
ALUNO;
ALUNO al[10];
main()
{
    printf("Hello world!\n");

}
