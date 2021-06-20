#include <stdio.h>
#include <stdlib.h>
int pares (int n, int *vet);
void inverte (int n, int *vet);
float minimo (int n, float *v);
int main()
{
    //atividade1(); // ativar para testar atividade 1
    //atividade2(); // ativar para testar atividade 2
    //atividade3(); // ativar para testar atividade 3
    printf("Hello world!\n");
    return 0;
}
/*

Escreva uma fun��o que receba como par�metro um vetor de n�meros inteiros de tamanho n
e retorne quantos n�meros pares est�o armazenados nesse vetor. Essa fun��o deve obedecer
ao prot�tipo a seguir. Escreva um programa para testar sua fun��o.

*/

void atividade1()
{
    int n = 0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    int vetor[n];
    for(int contador = 0; contador < n; contador++)
    {
        printf("Informe o valor do %d vetor: \n", contador + 1);
        scanf("%d", &vetor[contador]);
    }
    printf("Qtd numeros pares: %d\n", pares(n, vetor));
}
int pares (int n, int *vet)
{
    int j, total = 0;
    for (j = 0; j < n; j++)
    {
        if((vet[j]%2) == 0)
        {
            total++;
        }
    }
    return total;
};
//
/*

Implemente uma fun��o que receba como par�metro um vetor de n�meros inteiros de
tamanho n e inverta a ordem dos elementos armazenados nesse vetor. Essa fun��o deve
obedecer ao prot�tipo a seguir. Escreva um programa para testar sua fun��o.

*/
void atividade2()
{
    int n = 0;
    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &n);
    int vetor[n];
    for(int contador = 0; contador < n; contador++)
    {
        printf("Informe o valor do %d vetor: \n", contador + 1);
        scanf("%d", &vetor[contador]);
    }
    inverte(n, vetor);
}

void inverte (int n, int *vet)
{
    for(int contador = n-1; contador >= 0; contador--)
    {
        printf("%d\n", vet[contador]);
    }
}
//
/*

Escreva uma fun��o que retorne o valor m�nimo armazenado em um vetor. Essa fun��o deve
obedecer ao prot�tipo a seguir. Escreva um programa para testar sua fun��o.

*/

void atividade3() {
    int n = 0;
    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &n);
    float vetor[n];
    for(int contador = 0; contador < n; contador++)
    {
        printf("Informe o valor do %d vetor: \n", contador + 1);
        scanf("%f", &vetor[contador]);
    }
    printf("Valor minimo encontrado: %f \n",minimo(n, vetor));
}

float minimo (int n, float *v){
    float minimoEncontrado = 999999;
    for(int contador = 0; contador < n; contador++)
    {
        if(v[contador] < minimoEncontrado){
            minimoEncontrado = v[contador];
        }
    }
    return minimoEncontrado;
};
